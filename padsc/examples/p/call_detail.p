int validPN(Pint64 pn) {
  return (2000000000 < pn) && (pn < 9999999999);
}

int getNPA(Pint64 pn){
  if (pn < 0) return ( -1 * pn)/10000000;
  return pn/10000000;
};

int hasTollFreeNPA(int npa){
  return ((npa == 800) || (npa == 888) ||
	  (npa == 877) || (npa == 866) || (npa == 855));
};


Punion dialed_t{
  Puint64 domestic : validPN(domestic);
  Pint64  international : getNPA(international) == 15;
};

unsigned char isTF(dialed_t dialed){
  switch (dialed.tag) {
  case domestic: 
    return hasTollFreeNPA(getNPA(dialed.val.domestic));
  case international:
    return 0;
  default: 
    return 0;
  };
 
};

Precord Pstruct callRec_t {
  Pint64 origin : validPN(origin);
  dialed_t dialed;
  Pint64 terminated : validPN(terminated);
  Puint32 connect;
  Puint32 duration;
  Pcompute Puint8  isIntl = dialed.tag == international;
  Pcompute Puint8  isTollFree = isTF(dialed);
  Pcompute Puint8  isIncomplete = (0 == duration);
};
