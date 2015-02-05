// Set the output time zone to the one where the ai data (web log) was
// recorded (the data file has dates with a trailing -0700).  This
// means timestamp output will be consistent with the timestamps in the data.

#define OUT_TIME_ZONE "-0700"

////////////////////////////////////////////////////////////////////////////////
// Change this to '#if 1' to enable some printing for each good line
#if 0
#define EXTRA_GOOD_READ_CODE \
do { \
      if (rep->host.tag == resolved) { \
	error(0, "host: %u.%u.%u.%u", \
	      rep->host.val.resolved.elts[0],  \
	      rep->host.val.resolved.elts[1],  \
	      rep->host.val.resolved.elts[2],  \
	      rep->host.val.resolved.elts[3]); \
      } else { \
	int i; \
	error(0|ERROR_PROMPT, "host: "); \
	for (i = 0; i < rep->host.val.symbolic.length; i++) { \
	  if (i <  rep->host.val.symbolic.length-1) { \
	    error(0|ERROR_PROMPT, "%-.*s.", rep->host.val.symbolic.elts[i].len, rep->host.val.symbolic.elts[i].str); \
	  } else { \
	    error(0, "%-.*s", rep->host.val.symbolic.elts[i].len, rep->host.val.symbolic.elts[i].str); \
	  } \
	} \
      } \
      if (rep->remoteID.tag == unauthorized) { \
	error(0, "remoteID: **unauthorized**"); \
      } else { \
	error(0, "remoteID: %-.*s", rep->remoteID.val.id.len, rep->remoteID.val.id.str); \
      } \
      if (rep->auth.tag == unauthorized) { \
	error(0, "authid: **unauthorized**"); \
      } else { \
	error(0, "authid: %-.*s", rep->auth.val.id.len, rep->auth.val.id.str); \
      } \
      error(0, "date: %s", fmttime("%K", (time_t)rep->ts)); \
      error(0, "request meth: %s  req_uri: %-.*s  version: %u.%u", \
	    http_method_t2str(rep->request.meth), \
	    rep->request.req_uri.len, rep->request.req_uri.str, \
	    rep->request.version.major, \
	    rep->request.version.minor); \
      error(0, "response: %u   contentLength: %u", rep->response, rep->contentLength); \
      error(0, ""); \
} while (0)

#endif

////////////////////////////////////////////////////////////////////////////////

#define DEF_INPUT_FILE "../../data/ai"
#define PADS_TY(suf) http_clf_t ## suf
#include "ai.h"
#include "template/accum_report.h"

