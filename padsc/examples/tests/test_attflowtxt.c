#include "pads.h"
Puint32 bytes_sent;

#define DO_INIT1(pads, m)          bytes_sent = 0

#define DO_INIT2(pads, m) do { \
  bytes_sent = 0; \
  attflow_m_init(pads, m, P_Ignore); \
  m->Protocol  = P_CheckAndSet; \
  m->BytesSent = P_CheckAndSet; \
} while (0)

#define DO_INIT(pads, m)           DO_INIT1(pads, m)
#define DO_SELECT(pads, pd, rep)   (pd->nerr == 0 && rep->Protocol == 17)
#define DO_ACT(pads, pd, rep)      bytes_sent += rep->BytesSent
#define DO_DONE(pads)              sfprintf(sfstdout, "Bytes sent: %lu\n\n", bytes_sent)

#define MAX_RECS 1000
#define IO_DISC_MK P_nlrec_make(0)
#define PADS_TY(suf) attflow ## suf
#define DEF_INPUT_FILE "../../data/ATTFlow.small"
#include "attflowtxt.h"
#include "template/init_select_act_done.h"
