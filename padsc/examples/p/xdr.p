#include <rpc/rpc.h> 

// Assume argument pointers point to valid space
void Pstr2float(Pstring *src, Pbase_pd *src_pd, Pfloat32 *dest, Pbase_pd *dest_pd){
  XDR xin;
  *dest = 0;
  *dest_pd = *src_pd;  /* set destination parse descriptor from source */
  xdrmem_create(&xin, &src->str, src->len, XDR_DECODE);
  xdr_float(&xin, dest);
};

void Pfloat2str(P_t *p, Pfloat32 *src, Pbase_pd *src_pd, Pstring *dest, Pbase_pd *dest_pd){
  XDR xout;
  char str[8];
  *dest_pd = *src_pd;
  xdrmem_create(&xout, str, 8, XDR_ENCODE);
  xdr_float(&xout, src);
  if (P_OK != Pstring_cstr_copy(p, dest, str, 4)) {
    // Error: copy into Pstring failed
      dest_pd->nerr++;
      dest_pd->errCode = P_TRANSFORM_FAILED;
  };
}


Ptrans PxdrFloat{
 Pstr2float: Pstring_FW(:4:) <=> Pfloat32: Pfloat2str(:pads:);
};
