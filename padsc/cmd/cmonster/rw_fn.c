/*
 * readwrite functions for cmonster
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
 * Implement all the RW functions
 */

CM_RW_FN_IMPL(  CM_RW_FN_NM(int8_FW),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Pint8_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(int16_FW),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Pint16_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(int32_FW),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Pint32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(int64_FW),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Pint64_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(uint8_FW),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Puint8_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(uint16_FW),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Puint16_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(uint32_FW),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Puint32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(uint64_FW),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Puint64_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_int8_FW),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Pa_int8_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_int16_FW),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Pa_int16_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_int32_FW),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Pa_int32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_int64_FW),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Pa_int64_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_uint8_FW),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Pa_uint8_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_uint16_FW),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Pa_uint16_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_uint32_FW),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Pa_uint32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_uint64_FW),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Pa_uint64_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_int8_FW),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Pe_int8_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_int16_FW),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Pe_int16_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_int32_FW),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Pe_int32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_int64_FW),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Pe_int64_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_uint8_FW),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Pe_uint8_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_uint16_FW),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Pe_uint16_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_uint32_FW),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Pe_uint32_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_uint64_FW),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Pe_uint64_FW_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_int8),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Pb_int8_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_int16),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Pb_int16_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_int32),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Pb_int32_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_int64),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Pb_int64_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_uint8),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Pb_uint8_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_uint16),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Pb_uint16_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_uint32),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Pb_uint32_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(b_uint64),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Pb_uint64_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_int8),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Pebc_int8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_int16),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Pebc_int16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_int32),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Pebc_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_int64),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Pebc_int64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_uint8),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Pebc_uint8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_uint16),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Pebc_uint16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_uint32),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Pebc_uint32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_uint64),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Pebc_uint64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_int8),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Pbcd_int8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_int16),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Pbcd_int16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_int32),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Pbcd_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_int64),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Pbcd_int64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_uint8),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Pbcd_uint8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_uint16),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Pbcd_uint16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_uint32),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Pbcd_uint32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_uint64),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Pbcd_uint64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_int8),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Psbl_int8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_int16),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Psbl_int16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_int32),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Psbl_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_int64),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Psbl_int64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_uint8),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Psbl_uint8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_uint16),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Psbl_uint16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_uint32),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Psbl_uint32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_uint64),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Psbl_uint64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_int8),
		CM_RW_FN_PARAMS,
		Pint8 targ,
		Psbh_int8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int8_write2buf",
		1,
		Psbl_int8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_int16),
		CM_RW_FN_PARAMS,
		Pint16 targ,
		Psbh_int16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %d\n", (int)targ),
		"Psbl_int16_write2buf",
		2,
		Psbl_int16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_int32),
		CM_RW_FN_PARAMS,
		Pint32 targ,
		Psbh_int32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %ld\n", (long)targ),
		"Psbl_int32_write2buf",
		4,
		Psbl_int32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_int64),
		CM_RW_FN_PARAMS,
		Pint64 targ,
		Psbh_int64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lld\n", (long long)targ),
		"Psbl_int64_write2buf",
		8,
		Psbl_int64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_uint8),
		CM_RW_FN_PARAMS,
		Puint8 targ,
		Psbh_uint8_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint8_write2buf",
		1,
		Psbl_uint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_uint16),
		CM_RW_FN_PARAMS,
		Puint16 targ,
		Psbh_uint16_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %u\n", (unsigned int)targ),
		"Psbl_uint16_write2buf",
		2,
		Psbl_uint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_uint32),
		CM_RW_FN_PARAMS,
		Puint32 targ,
		Psbh_uint32_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %lu\n", (unsigned long)targ),
		"Psbl_uint32_write2buf",
		4,
		Psbl_uint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_uint64),
		CM_RW_FN_PARAMS,
		Puint64 targ,
		Psbh_uint64_read(cm->pads, &m, qy->params.elts[0], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %llu\n", (unsigned long long)targ),
		"Psbl_uint64_write2buf",
		8,
		Psbl_uint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_fpoint8),
		CM_RW_FN_PARAMS,
		Pfpoint8 targ,
		Pebc_fpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint8_write2buf",
		1,
		Psbl_fpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_fpoint16),
		CM_RW_FN_PARAMS,
		Pfpoint16 targ,
		Pebc_fpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint16_write2buf",
		2,
		Psbl_fpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_fpoint32),
		CM_RW_FN_PARAMS,
		Pfpoint32 targ,
		Pebc_fpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %ld  denom = %lu\n", (long)targ.num, (unsigned long)targ.denom),
		"Psbl_fpoint32_write2buf",
		4,
		Psbl_fpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_fpoint64),
		CM_RW_FN_PARAMS,
		Pfpoint64 targ,
		Pebc_fpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lld  denom = %llu\n", (long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_fpoint64_write2buf",
		8,
		Psbl_fpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_ufpoint8),
		CM_RW_FN_PARAMS,
		Pufpoint8 targ,
		Pebc_ufpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint8_write2buf",
		1,
		Psbl_ufpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_ufpoint16),
		CM_RW_FN_PARAMS,
		Pufpoint16 targ,
		Pebc_ufpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint16_write2buf",
		2,
		Psbl_ufpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_ufpoint32),
		CM_RW_FN_PARAMS,
		Pufpoint32 targ,
		Pebc_ufpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lu  denom = %lu\n", (unsigned long)targ.num, (unsigned long)targ.denom),
		"Psbl_ufpoint32_write2buf",
		4,
		Psbl_ufpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(ebc_ufpoint64),
		CM_RW_FN_PARAMS,
		Pufpoint64 targ,
		Pebc_ufpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %llu  denom = %llu\n", (unsigned long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_ufpoint64_write2buf",
		8,
		Psbl_ufpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_fpoint8),
		CM_RW_FN_PARAMS,
		Pfpoint8 targ,
		Pbcd_fpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint8_write2buf",
		1,
		Psbl_fpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_fpoint16),
		CM_RW_FN_PARAMS,
		Pfpoint16 targ,
		Pbcd_fpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint16_write2buf",
		2,
		Psbl_fpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_fpoint32),
		CM_RW_FN_PARAMS,
		Pfpoint32 targ,
		Pbcd_fpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %ld  denom = %lu\n", (long)targ.num, (unsigned long)targ.denom),
		"Psbl_fpoint32_write2buf",
		4,
		Psbl_fpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_fpoint64),
		CM_RW_FN_PARAMS,
		Pfpoint64 targ,
		Pbcd_fpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lld  denom = %llu\n", (long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_fpoint64_write2buf",
		8,
		Psbl_fpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_ufpoint8),
		CM_RW_FN_PARAMS,
		Pufpoint8 targ,
		Pbcd_ufpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint8_write2buf",
		1,
		Psbl_ufpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_ufpoint16),
		CM_RW_FN_PARAMS,
		Pufpoint16 targ,
		Pbcd_ufpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint16_write2buf",
		2,
		Psbl_ufpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_ufpoint32),
		CM_RW_FN_PARAMS,
		Pufpoint32 targ,
		Pbcd_ufpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lu  denom = %lu\n", (unsigned long)targ.num, (unsigned long)targ.denom),
		"Psbl_ufpoint32_write2buf",
		4,
		Psbl_ufpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(bcd_ufpoint64),
		CM_RW_FN_PARAMS,
		Pufpoint64 targ,
		Pbcd_ufpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %llu  denom = %llu\n", (unsigned long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_ufpoint64_write2buf",
		8,
		Psbl_ufpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_fpoint8),
		CM_RW_FN_PARAMS,
		Pfpoint8 targ,
		Psbl_fpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint8_write2buf",
		1,
		Psbl_fpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_fpoint16),
		CM_RW_FN_PARAMS,
		Pfpoint16 targ,
		Psbl_fpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint16_write2buf",
		2,
		Psbl_fpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_fpoint32),
		CM_RW_FN_PARAMS,
		Pfpoint32 targ,
		Psbl_fpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %ld  denom = %lu\n", (long)targ.num, (unsigned long)targ.denom),
		"Psbl_fpoint32_write2buf",
		4,
		Psbl_fpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_fpoint64),
		CM_RW_FN_PARAMS,
		Pfpoint64 targ,
		Psbl_fpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lld  denom = %llu\n", (long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_fpoint64_write2buf",
		8,
		Psbl_fpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_ufpoint8),
		CM_RW_FN_PARAMS,
		Pufpoint8 targ,
		Psbl_ufpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint8_write2buf",
		1,
		Psbl_ufpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_ufpoint16),
		CM_RW_FN_PARAMS,
		Pufpoint16 targ,
		Psbl_ufpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint16_write2buf",
		2,
		Psbl_ufpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_ufpoint32),
		CM_RW_FN_PARAMS,
		Pufpoint32 targ,
		Psbl_ufpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lu  denom = %lu\n", (unsigned long)targ.num, (unsigned long)targ.denom),
		"Psbl_ufpoint32_write2buf",
		4,
		Psbl_ufpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbl_ufpoint64),
		CM_RW_FN_PARAMS,
		Pufpoint64 targ,
		Psbl_ufpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %llu  denom = %llu\n", (unsigned long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_ufpoint64_write2buf",
		8,
		Psbl_ufpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_fpoint8),
		CM_RW_FN_PARAMS,
		Pfpoint8 targ,
		Psbh_fpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint8_write2buf",
		1,
		Psbl_fpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_fpoint16),
		CM_RW_FN_PARAMS,
		Pfpoint16 targ,
		Psbh_fpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %d  denom = %u\n", (int)targ.num, (unsigned int)targ.denom),
		"Psbl_fpoint16_write2buf",
		2,
		Psbl_fpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_fpoint32),
		CM_RW_FN_PARAMS,
		Pfpoint32 targ,
		Psbh_fpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %ld  denom = %lu\n", (long)targ.num, (unsigned long)targ.denom),
		"Psbl_fpoint32_write2buf",
		4,
		Psbl_fpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_fpoint64),
		CM_RW_FN_PARAMS,
		Pfpoint64 targ,
		Psbh_fpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lld  denom = %llu\n", (long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_fpoint64_write2buf",
		8,
		Psbl_fpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_ufpoint8),
		CM_RW_FN_PARAMS,
		Pufpoint8 targ,
		Psbh_ufpoint8_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint8_write2buf",
		1,
		Psbl_ufpoint8_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 1, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_ufpoint16),
		CM_RW_FN_PARAMS,
		Pufpoint16 targ,
		Psbh_ufpoint16_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %u  denom = %u\n", (unsigned int)targ.num, (unsigned int)targ.denom),
		"Psbl_ufpoint16_write2buf",
		2,
		Psbl_ufpoint16_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 2, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_ufpoint32),
		CM_RW_FN_PARAMS,
		Pufpoint32 targ,
		Psbh_ufpoint32_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %lu  denom = %lu\n", (unsigned long)targ.num, (unsigned long)targ.denom),
		"Psbl_ufpoint32_write2buf",
		4,
		Psbl_ufpoint32_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 4, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(sbh_ufpoint64),
		CM_RW_FN_PARAMS,
		Pufpoint64 targ,
		Psbh_ufpoint64_read(cm->pads, &m, qy->params.elts[0], qy->params.elts[1], &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val: num = %llu  denom = %llu\n", (unsigned long long)targ.num, (unsigned long long)targ.denom),
		"Psbl_ufpoint64_write2buf",
		8,
		Psbl_ufpoint64_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, 8, qy->params.elts[1], &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(char),
		CM_RW_FN_PARAMS,
		Pchar targ,
		Pchar_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %s\n", P_qfmt_char(targ)),
		"Pa_char_write2buf",
		1,
		Pa_char_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_char),
		CM_RW_FN_PARAMS,
		Pchar targ,
		Pa_char_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %s\n", P_qfmt_char(targ)),
		"Pa_char_write2buf",
		1,
		Pa_char_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_char),
		CM_RW_FN_PARAMS,
		Pchar targ,
		Pe_char_read(cm->pads, &m, &pd, &targ),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = %s\n", P_qfmt_char(targ)),
		"Pa_char_write2buf",
		1,
		Pa_char_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, &pd, &targ)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(string_FW),
		CM_RW_FN_PARAMS,
		Pstring *targp = &(cm->tmp1),
		Pstring_FW_read(cm->pads, &m, qy->params.elts[0], &pd, targp),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = [%s]\n", P_qfmt_str(targp)),
		"Pa_string_FW_write2buf",
		qy->params.elts[0],
		Pa_string_FW_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, qy->params.elts[0], &pd, targp)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(a_string_FW),
		CM_RW_FN_PARAMS,
		Pstring *targp = &(cm->tmp1),
		Pa_string_FW_read(cm->pads, &m, qy->params.elts[0], &pd, targp),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = [%s]\n", P_qfmt_str(targp)),
		"Pa_string_FW_write2buf",
		qy->params.elts[0],
		Pa_string_FW_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, qy->params.elts[0], &pd, targp)
);

CM_RW_FN_IMPL(  CM_RW_FN_NM(e_string_FW),
		CM_RW_FN_PARAMS,
		Pstring *targp = &(cm->tmp1),
		Pe_string_FW_read(cm->pads, &m, qy->params.elts[0], &pd, targp),
		P_NULL_STMT,
		sfprintf(cm->errf, "  ==> val = [%s]\n", P_qfmt_str(targp)),
		"Pa_string_FW_write2buf",
		qy->params.elts[0],
		Pa_string_FW_write2buf(cm->pads, cm->outbuf_cursor, remain_out, &buf_full, qy->params.elts[0], &pd, targp)
);

