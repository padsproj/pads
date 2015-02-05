#include "shel-vpn.h"
#define DEF_INPUT_FILE  "../../data/Sheleheda/alpa-vpn-extract.txt"
#define READ_MASK P_CheckAndSet
#ifndef DEF_CLEAN_FILE
#  define DEF_CLEAN_FILE "/dev/stdout"
#endif

void mungeIP(Pip *ip){
  sfprintf(sfstderr, "The ip address before: %d\n", *ip);
  *ip = *ip + *ip;
  sfprintf(sfstderr, "The ip address after: %d\n", *ip);
};

char mungeChar(char c){
  unsigned char n;
  if ('a' <= c && c <= 'z') {
    n = c + 10;
    if (n > 'z') return n-26; else return n;
  };
  if ('A' <= c && c <= 'Z') {
    n = c + 10;
    if (n > 'Z') return n-26; else return n;
  };
  if ('0' <= c && c <= '9') {
    n = c + 3;
    if (n > '9') return n-9; else return n;
  };
  return c;
};

void mungeString(Pstring *p){
  int i;
  for(i=0; i< p->len; i++){
    p->str[i] = mungeChar(p->str[i]);
  };
};

void cleanAddress(address_t *addr){
  if (addr->host.tag == ipAddress) {
    mungeIP(&addr->host.val.ipAddress);
  };
  if (addr->host.tag == namedHost) {
    mungeString(&addr->host.val.namedHost);
  };   
}

void cleanData(entry_t *rep){
  mungeString(&rep->systemName);
  if (rep->body.tag == main_exp) {
    if (rep->body.val.main_exp.msg.tag == csfw){
      mungeIP(&rep->body.val.main_exp.msg.val.csfw.ip1);
      mungeIP(&rep->body.val.main_exp.msg.val.csfw.ip2);
    };
    if (rep->body.val.main_exp.msg.tag == isakmp){
      if (rep->body.val.main_exp.msg.val.isakmp.ISKAMP_body.tag == noProposalMsg){
        mungeIP(&rep->body.val.main_exp.msg.val.isakmp.ISKAMP_body.val.noProposalMsg.msgSource);
      };
      if (rep->body.val.main_exp.msg.val.isakmp.ISKAMP_body.tag == InvalidMsg){
        mungeIP(&rep->body.val.main_exp.msg.val.isakmp.ISKAMP_body.val.InvalidMsg.msgSource);
      };
    };
    if (rep->body.val.main_exp.msg.tag == security){
      if (rep->body.val.main_exp.msg.val.security.securityBody.tag == securitySession){
        cleanAddress(&rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.address);
      };
      if (rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.tag==physicalAddresses){
        mungeIP(&rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.val.physicalAddresses.remoteIP);
        mungeIP(&rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.val.physicalAddresses.localIP);
      };
      if (rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.tag==ipPair){
        if (rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.val.ipPair.ip1.tag == IPAddress){
          mungeIP(&rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.val.ipPair.ip1.val.IPAddress);
          mungeIP(&rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.val.ipPair.ip2.val.IPAddress);
        };
      };
      if (rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.tag==assignedIP){
        mungeIP(&rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.val.assignedIP.assignedIP);
        mungeIP(&rep->body.val.main_exp.msg.val.security.securityBody.val.securitySession.securitySessionBody.val.assignedIP.assignedMask);
      };
    };
    if (rep->body.val.main_exp.msg.tag == failedLogIn){
      mungeString(&rep->body.val.main_exp.msg.val.failedLogIn.userName);
    };
    if (rep->body.val.main_exp.msg.tag == session){
      cleanAddress(&rep->body.val.main_exp.msg.val.session.sessionAddress);
    };
  };
};


int main(int argc, char** argv) {
  P_t              *pads;
  Pdisc_t           my_disc = Pdefault_disc;
  Pio_disc_t       *io_disc = 0;

  entry_t           rep;
  entry_t_pd        pd;
  entry_t_m         m;
  char             *fileName = 0;
  char             *cleanName = DEF_CLEAN_FILE;
  Sfio_t           *cleanfile;

  if (argc >= 2) {
    fileName = argv[1];
  } else {
    fileName = DEF_INPUT_FILE;
  }
  error(0, "\nData file = %s\n", fileName);
  cleanfile = sfopen(0, cleanName, "w");

  /* Initialize PADS library */
  io_disc = P_nlrec_make(0);
  P_open(&pads, &my_disc, io_disc);

  /* Initialize in-memory representation, parse descriptor, and mask */
  entry_t_init(pads, &rep);
  entry_t_pd_init(pads, &pd);
  entry_t_m_init(pads, &m, READ_MASK);

  /* Open data file */
  if (P_ERR == P_io_fopen(pads, fileName)) {
    error(ERROR_FATAL, "*** P_io_fopen failed ***");
  }

  /* Read each line of data  */
  while (!P_io_at_eof(pads)) {
    if (P_OK == entry_t_read(pads, &m, &pd, &rep)) {
      cleanData(&rep);
      entry_t_write2io(pads, cleanfile, &pd, &rep);
    }
  };
  P_io_close(pads);

  entry_t_cleanup(pads, &rep);
  entry_t_pd_cleanup(pads, &pd);
  P_close(pads);
  return 0;
}
