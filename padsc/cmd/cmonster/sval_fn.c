/*
 * switch value functions for cmonster
 *
 * Kathleen Fisher, Robert Gruber
 * AT&T Labs Research
 */

#include "cmonster.h"
#include "rw_fn.h"

/* 
 * CM_RW_FN_IMPL(fn_name,         name of function being defined
 *               params,          params of function
 *               targ_decl,       declare in-memory rep type targ
 *               read_call,       read function call
 *               assign_stmt,     either null statement or a (*res_out) assignment
 *               dbg_val_write,   stmt that writes resulting value to cm->errf, uses targ or res_out
 *               write2buf_nm,    name of write2buf fn as string
 *               write_sz,        size in bytes to write, may be constant or qy->params.elts[0]
 *               write_call       write2buf function call, uses targ or res_out
 * );      
 */

/*
 * Implement all the SVAL functions
 */

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(int32_FW),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Pint32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(a_int32_FW),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Pa_int32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(e_int32_FW),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Pe_int32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(ebc_int32),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Pebc_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(bcd_int32),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Pbcd_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(sbl_int32),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Psbl_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(sbh_int32),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Psbh_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(b_int32),
		CM_SVAL_FN_PARAMS,
		Pint32 targ,
		Pb_int32_read(cm->pads, &m, &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(char),
		CM_SVAL_FN_PARAMS,
		Pchar targ,
		Pchar_read(cm->pads, &m, &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)(*res_out)),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, res_out)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(a_char),
		CM_SVAL_FN_PARAMS,
		Pchar targ,
		Pa_char_read(cm->pads, &m, &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)(*res_out)),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, res_out)
);

CM_RW_FN_IMPL(  CM_SVAL_FN_NM(e_char),
		CM_SVAL_FN_PARAMS,
		Pchar targ,
		Pe_char_read(cm->pads, &m, &pd, &targ),
		(*res_out) = (Pint32)targ,
		sfprintf(cm->errf, "  ==> switch val = %ld\n", (long)(*res_out)),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, res_out)
);


