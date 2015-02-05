/*
 *  rbuftest1: Test rbufs
 */

#include "pads-internal.h" /* for testing - normally do not include internal */

P_NOGEN

int main(int argc, char** argv) {
  int             err, i;
  P_t*          pads;
  RMM_t*          rmm_z;
  RMM_t*          rmm_nz;
  RMM_t*          mgr;
  RBuf_t*         rbuf1;
  RBuf_t*         rbuf2;
  void*           buf1;
  void*           buf2;
  void*           buf2b;
  Pint32*      ar1;
  Pint8*       ar2;

  if (P_ERR == P_libopen(&pads, 0, 0, 1)) {
    error(2, "*** P_libopen failed ***");
    exit(-1);
  }
  rmm_z = P_rmm_zero(pads);
  rmm_nz = P_rmm_nozero(pads);

  if (!(rbuf1 = RMM_new_rbuf(rmm_z))) {
    error(2, "*** RMM_new_rbuf on rmm_z failed ***");
    exit(-1);
  }
  if (!(rbuf2 = RMM_new_rbuf(rmm_nz))) {
    error(2, "*** RMM_new_rbuf on rmm_nz failed ***");
    exit(-1);
  }
  if ((err = RBuf_RESERVE_HINT(rbuf1, buf1, Pint32, 5, 10))) {
    error(2, "*** rbuf1 reserve failed with err= %d ***", err);
    exit(-1);
  }
  ar1 = (Pint32*)buf1;
  if ((err = RBuf_RESERVE_HINT(rbuf2, buf2, Pint8, 5, 0))) {
    error(2, "*** rbuf2 reserve failed with err= %d ***", err);
    exit(-1);
  }
  ar2 = (Pint8*)buf2;


  error(0, "Walking zerod data array");
  for (i = 0; i < 5; i++) {
    error(0, "ar1[%d] = %d", i, ar1[i]);
  }
  error(0, "Walking non-zerod data array");
  for (i = 0; i < 5; i++) {
    error(0, "ar2[%d] = %d", i, ar2[i]);
  }
  error(0, "Growing zerod array from 5 to 20 elts, one increment at a time");
  for (i = 5; i < 20; i++) {
    if ((err = RBuf_RESERVE_HINT(rbuf1, buf1, Pint32, i+1, 10))) {
      error(2, "*** rbuf1 reserve failed with err= %d ***", err);
      exit(-1);
    }
    ar1 = (Pint32*)buf1;
    error(0, "ar1[%d] = %d", i, ar1[i]);
  }
  error(0, "Growing non-zerod array from 5 to 20 elts, one increment at a time");
  for (i = 5; i < 20; i++) {
    if ((err = RBuf_RESERVE_HINT(rbuf2, buf2, Pint8, i+1, 0))) {
      error(2, "*** rbuf2 reserve failed with err= %d ***", err);
      exit(-1);
    }
    ar2 = (Pint8*)buf2;
    error(0, "ar2[%d] = %d", i, ar2[i]);
  }
  error(0, "Calling RMM_free_rbuf on rbuf1 (should cause 2 mem frees)");
  err = RMM_free_rbuf(rbuf1);
  error(0, "=> RMM_rbuf_free on rbuf1 result: err= %d ***", err);

  error(0, "Calling RMM_free_rbuf on rbuf1 (should do nothing)");
  err = RMM_free_rbuf(rbuf1);
  error(0, "=> RMM_rbuf_free on rbuf1 result: err= %d ***", err);

  error(0, "Calling RMM_free_rbuf_keep_buf on rbuf2 (should cause 1 mem free)");
  err = RMM_free_rbuf_keep_buf(rbuf2, &buf2b, &mgr);
  error(0, "=> RMM_rbuf_free_keep_buf on rbuf2 result: err= %d ***", err);
  if (buf2b != buf2) {
    error(2, "*** unexpected: buf2b != buf2");
  }
  if (mgr != rmm_nz) {
    error(2, "*** unexpected: mgr != rmm_nz");
  }

  error(0, "Calling RMM_free_keep_buf on rbuf2 (should do nothing)");
  err = RMM_free_rbuf_keep_buf(rbuf2, 0, 0);
  error(0, "=> RMM_rbuf_free_keep_buf on rbuf2 result: err= %d ***", err);

  error(0, "Calling RMM_free_buf on rbuf2's buffer (should cause 1 mem free)");
  err = RMM_free_buf(mgr, buf2b);
  error(0, "=> RMM_free_buf on rbuf2's buffer result: err= %d ***", err);

  if (P_ERR == P_close(pads)) {
    error(2, "*** P_close failed ***");
    exit(-1);
  }
  return 0;
}
