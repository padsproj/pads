/*
 * Helpers
 *
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#ifndef __RW_FN_H__
#define __RW_FN_H__

#define CM_RW_FN_IMPL(fn_nm, params, targ_decl, read_call, assign_stmt, dbg_val_write, write2buf_nm, write_sz, write_call) \
Perror_t fn_nm ( params ) \
{ \
  targ_decl; \
  Pbase_pd    pd; \
  Pbase_m     m = P_CheckAndSet; /* could optimize and just use P_Set */ \
  Perror_t    er; \
  int            buf_full; \
 \
  size_t avail_in   = end - (begin + qy->off); \
  size_t remain_out = cm->outbuf_end - cm->outbuf_cursor; \
 \
  sfprintf(cm->errf, PDCI_MacroArg2String(fn_nm) " for type %s called\n", qy->entry->tname); \
  sfprintf(cm->errf, "  outbuf has %lu bytes remaining\n", (unsigned long)remain_out); \
  sfprintf(cm->errf, "  input has %lu bytes available starting at offset %lu\n", \
	(unsigned long)avail_in, (unsigned long)qy->off); \
  if (qy->out_sz > remain_out) { \
    sfprintf(cm->errf, \
	  "  Error: qy requires %lu output bytes but outbuf has only %lu bytes\n" \
	  "   remaining.  Skipping this data item.\n", \
	  (unsigned long)qy->out_sz, (unsigned long)remain_out); \
    return P_ERR; \
  } \
  if (qy->in_sz > avail_in) { \
    sfprintf(cm->errf, \
	  "  Error: qy requires %lu input bytes but input record has only %lu bytes\n\n" \
	  "  available starting at offset %lu.  Skipping this data item.\n", \
	  (unsigned long)qy->in_sz, (unsigned long)avail_in, (unsigned long)qy->off); \
    return P_ERR; \
  } \
  P_io_checkpoint(cm->pads, 0); /* could use 1 to supress error msgs */ \
  if (qy->off) { \
    PDCI_io_forward(cm->pads, qy->off); \
  } \
  er = read_call; \
  P_io_restore(cm->pads); \
  if (P_ERR == er) { \
    sfprintf(cm->errf, \
	  "  Error: read function for type %s at offset %lu failed\n" \
	  "  Skipping this data item.\n", (unsigned long)qy->off, qy->entry->tname); \
    return P_ERR; \
  } \
  assign_stmt; \
  dbg_val_write; \
  if (qy->out_sz) { /* write the val */ \
    if (write_sz != write_call) { \
      sfprintf(cm->errf, "\n*** FATAL: Unexpected error calling " write2buf_nm "\n\n"); \
      abort(); \
    } \
    sfprintf(cm->errf, "  advancing outbuf_cursor by %lu bytes\n", (unsigned long)qy->out_sz); \
    cm->outbuf_cursor += qy->out_sz; \
  } \
  return P_OK; \
}

#endif  /*  !__RW_FN_H__  */
