int hexCharToInt(char c){
  if ('0' <= c && c <= '9') {
    return c - '0';
  } else {
    switch (c){
    case 'a':
    case 'A': return 10;
    case 'b':
    case 'B': return 11;
    case 'c':
    case 'C': return 12;
    case 'd':
    case 'D': return 13;
    case 'e':
    case 'E': return 14;
    case 'f':
    case 'F': return 15;
    }
    return -1;  /* hex digit out of range */
  }
}

char intToHexChar(Puint32 h){
  if ( h > 15) return 'z';  // error!
  if ( h < 10) return '0' + h;
  return 'a' + (h - 10);
}

// Assume argument pointers point to valid space
void toInt32(Pstring *src, Pbase_pd *src_pd, Puint32 *dest, Pbase_pd *dest_pd){
  size_t i;
  int digit;
  *dest = 0;
  *dest_pd = *src_pd;  /* set destination parse descriptor from source */
  for(i=0; i<src->len; i++){
    digit = hexCharToInt(src->str[i]);
    if (digit <0) {
      dest_pd->nerr++;
      dest_pd->errCode = P_TRANSFORM_FAILED;
      break;
    } else {
      *dest = *dest * 16 + digit;
      // should check for overflow here
    }
  }
};

/* if first arg is P_t, we automatically pass in the current pads handle; needed for string routines and ??? */
/* second arg is supplied in transform decl.  Others are required */
void toHexString(P_t *p, Puint32 size, Puint32 *src, Pbase_pd *src_pd, Pstring *dest, Pbase_pd *dest_pd){
  Puint32 local = *src;
  int i;
  char str[256];
  Puint32 msize = (size < 256) ? size : 255;
  *dest_pd = *src_pd;

  if (msize < size) {
      // Error: hex representation too large
      dest_pd->nerr++;
      dest_pd->errCode = P_TRANSFORM_FAILED;
  }
  for (i=0; i<msize + 1; i++){
    str[i] = 0;
  }
  for (i = msize-1; i>=0; i--){
    char result = intToHexChar(local % 16);
    if ('z' == result) {
      // Error: hex string contained a non-hex digit
      dest_pd->nerr++;
      dest_pd->errCode = P_TRANSFORM_FAILED;
      break;
    }
    str[i] = result;
    local = local / 16;
  }
  if (local != 0) {
    // Error: number too big to be represented in given size.
      dest_pd->nerr++;
      dest_pd->errCode = P_TRANSFORM_FAILED;
  };
  if (P_OK != Pstring_cstr_copy(p, dest, str, size)) {
    // Error: copy into Pstring failed
      dest_pd->nerr++;
      dest_pd->errCode = P_TRANSFORM_FAILED;
  };
}

void cnvMask(Pbase_m *phy, Pbase_m *log){
  *phy = *log;
}

Ptrans hexint32(:Puint32 size:){
 toInt32: Pstring_FW(:size:) <=> Puint32: toHexString(:pads, size :);
 Pmaskmap cnvMask;
};

Precord Pstruct entry_t{
  hexint32(:8:) f;
};

