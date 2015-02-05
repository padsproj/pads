#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// PADS functions

// Some return result codes
#define  PADS_RET_OK                0  // no error
#define  PADS_RET_ERR              -1  // error
#define  PADS_RET_NEED_MORE_BYTES  -2  // need more input bytes

// PADS_INIT: initialize PADS data structures.
// Returns PADS_RET_OK or PADS_RET_ERR.
int PADS_INIT();

// PADS_INPUT_FILE and PADS_INPUT_BUF provide some additional bytes to
// the PADS parsing engine from a file or a buffer, respectively.
// They share these control params:
//
// "continuation" indicates whether the provided bytes are a
// continuation of an ongoing parse.  If "continuation" is non-zero
// then the provided bytes are treated as a continuation of the bytes
// already *successfully* parsed by PADS_NEXT calls (i.e., PADS_NEXT
// calls with a return value of PADS_RET_OK or PADS_RET_ERR).  If
// "continuation" is 0, the bytes begin a fresh parse, which resets
// the PADS state.
//
// "fuzzy_boundary" indicates whether the tail end of the provided
// bytes might contain a partial header or record.  If
// "fuzzy_boundary" is non-zero, this tells PADS that there are more
// bytes coming in the future (via another PADS_INPUT call with a
// non-zero "continuation") and furthermore the current bytes may not
// end cleanly -- the last byte provided may not be at a clean header
// or record boundary.
//
// IMPORTANT:  If the input stream is not infinite, such that there
// is an actual EOF point, then the final PADS_INPUT call should
// pass zero for "fuzzy_boundary", even if all previous PADS_INPUT
// calls passed a non-zero "fuzzy_boundary".  Otherwise, PADS will
// always wait on parsing the last record and ask for more bytes,
// since it thinks it needs to make sure it has a full record's
// worth of bytes.
//
// IMPORTANT: If a PADS_NEXT call indicates that PADS need more bytes,
// the caller must copy any unused bytes into a buffer, append to that
// buffer some additional bytes, and then use PADS_INPUT_BUF to
// provide those bytes to pads.  The unused bytes equals the total
// number of bytes provided minus the number of parsed bytes as given
// by PADS_BYTES_PARSED_CURRENT_INPUT().
//
// IMPORTANT: When using a non-zero "fuzzy_boundary", the file or
// buffer passed to the PADS_INPUT call MUST contain more than just a
// single record.  For fuzzy bounaries, PADS holds off on parsing what
// appears to be the last record until it gets more bytes, so if you
// provide a buffer that only has one record in it, a call to
// PADS_NEXT will ask for more bytes after using zero bytes, which
// means you will end up in an infinite loop.  Summary: if you are
// using fuzzy bounaries, you should choose your buffer or file size
// to be large enough to guarantee at least a few records are passed
// to PADS on each PADS_INPUT call.

// PADS_INPUT_FILE: (re)initialize PADS to read from file "inName",
// which can be "/dev/stdin" or a file path.
// Returns PADS_RET_OK or PADS_RET_ERR.
int PADS_INPUT_FILE(const char *inName,
		    int continuation, int fuzzy_boundary);

// PADS_INPUT_BUF: (re)initialize PADS to read from a buffer "buf" of
// length "buf_len".
// Returns PADS_RET_OK or PADS_RET_ERR.
int PADS_INPUT_BUF(char *buf, size_t buf_len,
		   int continuation, int fuzzy_boundary);

// PADS_CLEANUP: done using pads, clean up PADS data structures.
// Returns PADS_RET_OK or PADS_RET_ERR.
int PADS_CLEANUP();

// PADS_NEXT: read the next record.
//
// Returns one of three result codes:
//   PADS_RET_OK               =>  successful parse, no errors
//   PADS_RET_ERR              =>  entire record was read,
//                                 but there were some field-level errors
//   PADS_RET_NEED_MORE_BYTES  =>  PADS needs more bytes before it can
//                                 parse more records
//
// NB: PADS_NEXT will only return PADS_RET_NEED_MORE_BYTES if the most
// recent call to PADS_INPUT_BUF or PADS_INPUT_FILE passed a non-zero
// "fuzzy_bytes" parameter.  If "fuzzy_bytes" was zero and
// PADS_NEXT cannot read a full record, it will report an error but will
// not ask for more bytes.
//
// PADS_NEXT sets (*done) to 0 or 1, using 1 is for the following:
//
//      (a) A fixed maximum number of records was set when
//          gigacope_make.pl was used (via --maxrecs) and
//          the specified number of records has been reached.
//
//      (b) The end of input is reached and the most recent
//          PADS_INPUT call used a zero "fuzzy_bytes" arg.
//
//      (c) There is an error reading a header.  Failure to read
//          a header normally means there is a serious problem
//          with the input.  (Errors in normal records do not
//          cause *done to be set to 1.)
//
// Once (*done) is set to 1, if more input is to be parsed, the next
// PADS_INPUT call should start the input at a valid header boundary
// (if headers are used) and pass 0 for the "continuation" arg to
// cause a reset of the PADS state.

int PADS_NEXT(int *done);

// PADS_BYTES_PARSED_CURRENT_INPUT: returns the number of bytes parsed
// by calls to PADS_NEXT since the last call to PADS_INPUT_BUF or
// PADS_INPUT_FILE.  Note: a call to PADS_NEXT that produces
// PADS_RET_NEED_MORE_BYTES does not change the number of bytes parsed.
int PADS_BYTES_PARSED_CURRENT_INPUT();

