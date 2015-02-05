/*
 * rbuf implementation
 * 
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#include <ast.h>
#include <vmalloc.h>
#include <error.h>
#include "rbuf-internal.h"

/* ================================================================================ */
/* IMPL CONSTANTS */

/*
 * On first alloc, if no hint is given as to likely max size, then
 * we use the following as the hint.  This avoids allocating, e.g.,
 * a single array element for the case where resize is called on each
 * element (resize to 1, 2, 3, ....) but with no hint. 
 */
/*  XXX ??? #define RBUF_DEFAULT_HINT 16 */
#define RBUF_DEFAULT_HINT 1

/* ================================================================================ */
/* RMM : default allin1 functions and disciplines */

void *
RMM_allin1_zero(void *vm, void *data, size_t size)
{
  if (!vm) {
    Vmdcheap->round = 1024 * 1024;
    return  (void *)vmopen(Vmdcheap, Vmbest, VM_TRACE);  /* change this last flag to a zero */
  }
  if (data || size) {
    vmcompact((Vmalloc_t*) vm); 
    return (void *)vmresize((Vmalloc_t*)vm, data, size, VM_RSMOVE|VM_RSCOPY|VM_RSZERO);
  }
  vmclose((Vmalloc_t*)vm);
  return 0;
}

void *
RMM_allin1_nozero(void *vm, void *data, size_t size)
{
  if (!vm) {
    return (void *)vmopen(Vmdcheap, Vmbest, 0);
  }
  if (data || size) {
    return (void *)vmresize((Vmalloc_t*)vm, data, size, VM_RSMOVE|VM_RSCOPY);
  }
  vmclose((Vmalloc_t*)vm);
  return 0;
}

RMM_disc_t RMM_zero_disc   = { RMM_allin1_zero };
RMM_disc_t RMM_nozero_disc = { RMM_allin1_nozero };

RMM_disc_t *RMM_zero_disc_ptr   = &RMM_zero_disc;
RMM_disc_t *RMM_nozero_disc_ptr = &RMM_nozero_disc;

/* ================================================================================ */
/* RMM : open/close */

RMM_t*
RMM_open(RMM_disc_t *disc)
{
  void  *vm;
  RMM_t *res;

  if (!disc) {
    disc = RMM_zero_disc_ptr;
  }
  if (!(vm = disc->allin1(0, 0, 0))) {
    return 0;
  }
  if (!(res = (RMM_t*)disc->allin1(vm, 0, sizeof(RMM_t)))) {
    return 0;
  }
  res->vm = vm;
  res->fn = disc->allin1;
  return res;
}

int
RMM_close(RMM_t *mgr)
{
  if (!mgr || !mgr->vm || !mgr->fn) {
    return -1; /* failure */
  }
  mgr->fn(mgr->vm, 0, 0); /* frees vm region / all vm-allocated objects, including mgr itself */
  return 0; /* success */
}

/* ================================================================================ */
/* RMM : new/free functions */

#ifdef RBUF_DEBUG
static unsigned long long RBuf_allocd_mem_ = 0ULL;

void RBuf_dbg_report(const char *context) {
  error(0, "%s: Rbuf_allocd_mem_ = %llu", context, RBuf_allocd_mem_);
}
#endif

#ifndef RBUF_DEBUG
RBuf_t*
RMM_new_rbuf (RMM_t *mgr)
{
  RBuf_t *res;

  if (!mgr || !mgr->vm || !mgr->fn) {
    return 0; /* failure */
  }
  if (!(res = (RBuf_t*)mgr->fn(mgr->vm, 0, sizeof(RBuf_t)))) {
    return 0; /* failure */
  }
  res->mgr = mgr;
  res->buf = 0;
  res->bufSize = res->eltSize = res->numElts = res->maxEltHint = 0;
  return res;
}

#else

RBuf_t*
RMM_new_rbuf_dbg(RMM_t *mgr, const char *file, int line)
{
  RBuf_t *res;

  if (!mgr || !mgr->vm || !mgr->fn) {
    return 0; /* failure */
  }
  if (!(res = (RBuf_t*)mgr->fn(mgr->vm, 0, sizeof(RBuf_t)))) {
    return 0; /* failure */
  }
  res->mgr = mgr;
  res->buf = 0;
  res->bufSize = res->eltSize = res->numElts = res->maxEltHint = 0;
  res->new_file = file;
  res->new_line = line;
  res->reserve_file = "RESERVE_NEVER_CALLED";
  res->reserve_line = 0;
  return res;
}
#endif

#ifndef RBUF_DEBUG
int
RMM_free_rbuf(RBuf_t *rbuf)
{
  RMM_t *mgr;
  if (!rbuf) {
    return -2; /* failure - other */
  }
  mgr = rbuf->mgr;
  if (!mgr || !mgr->vm || !mgr->fn) {
    return -1; /* failure - no manager */
  }
  if (rbuf->buf) {
    mgr->fn(mgr->vm, rbuf->buf, 0); /* free buf */
    rbuf->buf = 0;
  }
  rbuf->mgr = 0; /* prevent future rbuf_free from doing anything */
  mgr->fn(mgr->vm, rbuf, 0); /* free rbuf */
  return 0; /* success */
}

int
RMM_free_rbuf_keep_buf(RBuf_t *rbuf, void **buf_out, RMM_t **mgr_out)
{
  RMM_t *mgr;
  if (!rbuf) {
    return -2; /* failure - other */
  }
  mgr = rbuf->mgr;
  if (!mgr || !mgr->vm || !mgr->fn) {
    return -1; /* failure - no manager */
  }
  if (mgr_out) {
    *mgr_out = mgr;
  }
  if (buf_out) {
    *buf_out = rbuf->buf;
  }
  rbuf->mgr = 0; /* prevent future rbuf_free from doing anything */
  rbuf->buf = 0; /* ditto for future rbuf access calls */
  mgr->fn(mgr->vm, rbuf, 0); /* free rbuf */
  return 0; /* success */
}

#else

int
RMM_free_rbuf_dbg(RBuf_t *rbuf, const char *file, int line)
{
  RMM_t *mgr;
  if (!rbuf) {
    return -2; /* failure - other */
  }
  mgr = rbuf->mgr;
  if (!mgr || !mgr->vm || !mgr->fn) {
    return -1; /* failure - no manager */
  }
  if (rbuf->buf) {
  RBuf_allocd_mem_ -= rbuf->bufSize;
  error(0, "XXX[new at %s:%d last reserve at %s:%d NOW at %s:%d] RBuf freed, RBuf_allocd_mem_ now = %llu  ",
	rbuf->new_file, rbuf->new_line,
	rbuf->reserve_file, rbuf->reserve_line,
	file, line,
	RBuf_allocd_mem_);
    mgr->fn(mgr->vm, rbuf->buf, 0); /* free buf */
    rbuf->buf = 0;
  }
  rbuf->mgr = 0; /* prevent future rbuf_free from doing anything */
  mgr->fn(mgr->vm, rbuf, 0); /* free rbuf */
  return 0; /* success */
}

int
RMM_free_rbuf_keep_buf_dbg(RBuf_t *rbuf, void **buf_out, RMM_t **mgr_out,
			   const char *file, int line)
{
  RMM_t *mgr;
  if (!rbuf) {
    return -2; /* failure - other */
  }
  mgr = rbuf->mgr;
  if (!mgr || !mgr->vm || !mgr->fn) {
    return -1; /* failure - no manager */
  }
  if (mgr_out) {
    *mgr_out = mgr;
  }
  if (buf_out) {
    *buf_out = rbuf->buf;
  }
  /* warn that we are subtracting mem now even tho it is not being freed yet */
  RBuf_allocd_mem_ -= rbuf->bufSize;
  error(0, "XXX[new at %s:%d last reserve at %s:%d NOW at %s:%d] RBuf freed, RBuf_allocd_mem_ now = %llu  "
	"[RMM_free_rbuf_keep_buf: ASSUMING buf will be freed]",
	rbuf->new_file, rbuf->new_line,
	rbuf->reserve_file, rbuf->reserve_line,
	file, line,
	RBuf_allocd_mem_);
  rbuf->mgr = 0; /* prevent future rbuf_free from doing anything */
  rbuf->buf = 0; /* ditto for future rbuf access calls */
  mgr->fn(mgr->vm, rbuf, 0); /* free rbuf */
  return 0; /* success */
}
#endif

void*
RMM_alloc_unmanaged_buf(RMM_t* mgr, size_t size)
{
  if (!mgr || !mgr->vm || !mgr->fn) {
    return 0; /* failure */
  }
  return mgr->fn(mgr->vm, 0, size);
}

int
RMM_free_buf(RMM_t *mgr, void *buf)
{
  if (!mgr || !mgr->vm || !mgr->fn) {
    return -1; /* failure - no manager */
  }
  mgr->fn(mgr->vm, buf, 0); /* free buf */
  return 0; /* success */
}

/* ================================================================================ */
/* RBuf: reserve function */

#ifndef RBUF_DEBUG
int
RBuf_reserve(RBuf_t *rbuf, void **buf_out, size_t eltSize,
	     size_t numElts, size_t maxEltHint)
{
  RMM_t  *mgr;
  char  *old_buf;
  size_t old_size;
  size_t new_size;
  size_t targ_size;

  if (!rbuf) {
    error(2, "RBuf_reserve called with null rbuf");
    return -3; /* failure - other */
  }
  old_buf = rbuf->buf;
  old_size = rbuf->bufSize;
  mgr = rbuf->mgr;
  if (!mgr || !mgr->vm || !mgr->fn) {
    error(2, "RBuf_reserve called with rbuf that has no mem mgr");
    return -1; /* failure - no manager */
 }
  rbuf->eltSize    = eltSize;
  rbuf->numElts    = numElts;
  rbuf->maxEltHint = maxEltHint;
  targ_size = eltSize * numElts;
  if (rbuf->buf && (targ_size <= rbuf->bufSize)) {
    /* trivial success */
    if (buf_out) {
      *buf_out = rbuf->buf;
    }
    return 0;
  }
  if (!(rbuf->buf) && maxEltHint == 0) {
    /* on first alloc, avoid allocating too little space due to lack of a hint */
    maxEltHint = RBUF_DEFAULT_HINT;
  }
  if (maxEltHint <= numElts) {
    /* hint does not help */
    if (rbuf->buf) {
      /* a realloc, note that we already chose a multiple of 8 */
      if (targ_size > 32768) {
	/* above 32K, we use the first multiple of 4K > target_size + eltSize */
	new_size = targ_size + eltSize + 4095;
	new_size = (new_size >> 12) << 12; /* (new_size/4K)*4K */
      } else {
	/* below 32K, we use doubling */
	new_size = rbuf->bufSize;
	while (new_size < targ_size) {
	  new_size *= 2;
	}
      }
    } else { /* this is the first alloc, use nearest multiple of 8 > targ_size */
      new_size = targ_size + 7;
      new_size = (new_size >> 3) << 3;
    }
  } else { /* hint helps, so use it */
    /* round eltSize * maxEltHint up to nearest multiple of 8 */
    new_size = eltSize * maxEltHint + 7;
    new_size = (new_size >> 3) << 3;
  }
  if (!(rbuf->buf = mgr->fn(mgr->vm, rbuf->buf, new_size))) { /* alloc or resize buf */
    error(2, "RBuf_reserve -- out of space");
    return -2; /* failure - out of space */
  }
  if (mgr->fn == RMM_allin1_zero) {
    int i;
    char *start = rbuf->buf + old_size;
    char *end = rbuf->buf + new_size;
    int buf_moved = (old_buf && (old_buf != rbuf->buf));
    for (i=0 ; start + i < end; i++) {
      if (start[i]) {
	error(0, "YIKES: RMM_allin1_zero did not zero some of the newly allocated memory, buf_moved = %d",
	      buf_moved);
	break;
      }
    }
    memset((void*)(rbuf->buf + old_size), 0, new_size - old_size);
  }
  rbuf->bufSize = new_size;
  if (buf_out) {
    *buf_out = rbuf->buf;
  }
  return 0; /* success */
}

#else

int
RBuf_reserve_dbg(RBuf_t *rbuf, void **buf_out, size_t eltSize,
		 size_t numElts, size_t maxEltHint,
		 const char *file, int line)
{
  RMM_t  *mgr;
  char  *old_buf;
  size_t old_size;
  size_t new_size;
  size_t targ_size;
  char * which;

  if (!rbuf) {
    error(2, "[%s:%d] RBuf_reserve called with null rbuf",
	  file, line);
    return -3; /* failure - other */
  }
  rbuf->reserve_file = file;
  rbuf->reserve_line = line;
  old_buf = rbuf->buf;
  old_size = rbuf->bufSize;
  mgr = rbuf->mgr;
  if (mgr->fn == RMM_allin1_zero) {
    which = "zeroing";
  } else {
    which = "non-zeroing";
  };

  if (!mgr || !mgr->vm || !mgr->fn) {
    error(2, "[new at %s:%d NOW at %s:%d] RBuf_reserve called with rbuf that has no mem mgr",
	  rbuf->new_file, rbuf->new_line,
	  file, line);
    return -1; /* failure - no manager */
  }
  rbuf->eltSize    = eltSize;
  rbuf->numElts    = numElts;
  rbuf->maxEltHint = maxEltHint;
  targ_size = eltSize * numElts;
  if (rbuf->buf && (targ_size <= rbuf->bufSize)) {
    /* trivial success */
    if (buf_out) {
      *buf_out = rbuf->buf;
    }
    return 0;
  }
  if (!(rbuf->buf) && maxEltHint == 0) {
    /* on first alloc, avoid allocating too little space due to lack of a hint */
    maxEltHint = RBUF_DEFAULT_HINT;
  }
  if (maxEltHint <= numElts) {
    /* hint does not help */
    if (rbuf->buf) {
      /* a realloc, note that we already chose a multiple of 8 */
      if (targ_size > 32768) {
	/* above 32K, we use the first multiple of 4K > target_size + eltSize */
	new_size = targ_size + eltSize + 4095;
	new_size = (new_size >> 12) << 12; /* (new_size/4K)*4K */
      } else {
	/* below 32K, we use doubling */
	new_size = rbuf->bufSize;
	while (new_size < targ_size) {
	  new_size *= 2;
	}
      }
    } else { /* this is the first alloc, use nearest multiple of 8 > targ_size */
      new_size = targ_size + 7;
      new_size = (new_size >> 3) << 3;
    }
  } else { /* hint helps, so use it */
    /* round eltSize * maxEltHint up to nearest multiple of 8 */
    new_size = eltSize * maxEltHint + 7;
    new_size = (new_size >> 3) << 3;
  }
  if (!(rbuf->buf = mgr->fn(mgr->vm, rbuf->buf, new_size))) { /* alloc or resize buf */
    error(2, "[new at %s:%d NOW at %s:%d] RBuf_reserve -- out of space",
	  rbuf->new_file, rbuf->new_line,
	  file, line);
    return -2; /* failure - out of space */
  }
  rbuf->bufSize = new_size;
  if (mgr->fn == RMM_allin1_zero) {
    char *start = rbuf->buf + old_size;
    char *end = rbuf->buf + new_size;
    int buf_moved = (old_buf && (old_buf != rbuf->buf));
    for ( ; start < end; start++) {
      if (*start) {
	error(0, "[%s:%d] RMM_allin1_zero did not zero some of the newly allocated memory, buf_moved = %d",
	      file, line, buf_moved);
	break;
      }
    }
    memset((void*)(rbuf->buf + old_size), 0, new_size - old_size);
  }
  RBuf_allocd_mem_ += (new_size - old_size);
  error(0, "XXX[new at %s:%d NOW at %s:%d] RBuf_allocd_mem_ now = %llu",
	rbuf->new_file, rbuf->new_line,
	file, line,
	RBuf_allocd_mem_);
  if (buf_out) {
    *buf_out = rbuf->buf;
  }
  return 0; /* success */
}
#endif


/* ================================================================================ */
/* RBuf : accessor functions */

size_t
RBuf_bufSize(RBuf_t *rbuf)
{
  if (!rbuf) {
    return 0;
  }
  return rbuf->bufSize;
}

size_t
RBuf_numElts(RBuf_t *rbuf)
{
  if (!rbuf) {
    return 0;
  }
  return rbuf->numElts;
}

size_t
RBuf_eltSize(RBuf_t *rbuf)
{
  if (!rbuf) {
    return 0;
  }
  return rbuf->eltSize;
}

size_t
RBuf_maxEltHint(RBuf_t *rbuf)
{
  if (!rbuf) {
    return 0;
  }
  return rbuf->maxEltHint;
}

void *
RBuf_get_buf(RBuf_t *rbuf)
{
  if (!rbuf) {
    return 0;
  }
  return rbuf->buf;
}

void *
RBuf_get_elt(RBuf_t *rbuf, size_t index)
{
  if (!rbuf) {
    return 0;
  }
  return (void *) ((char*)rbuf->buf + (index * rbuf->eltSize));
}

/* ================================================================================ */

