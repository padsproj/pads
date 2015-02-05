typedef int bool;
#define true 1
#define false 0

Parray Phostname{
  Pstring_SE(:"/[. ]/":) [] : Psep('.') && Pterm(Pnosep); 
};

Punion client_t {
  Pip       ip;      /- 135.207.23.32
  Phostname host;    /- www.research.att.com
};

Punion auth_id_t {
  Pchar unauthorized : unauthorized == '-'; 
  Pstring(:' ':) id;                        
};

Penum method_t {
    GET,    PUT,  POST,  HEAD,     
    DELETE, LINK, UNLINK 
};

Pstruct version_t {
  "HTTP/";
  Puint8 major; '.';
  Puint8 minor;          
};

bool chkVersion(version_t v, method_t m) {
  if ((v.major == 1) && (v.minor == 1)) return true;
  if ((m == LINK) || (m == UNLINK)) return false;
  return true;
};

Pstruct request_t {
  '\"';   method_t       meth;     
  ' ';    Pstring(:' ':) req_uri;  
  ' ';    version_t      version : 
                  chkVersion(version, meth); 
  '\"';
};

Ptypedef Puint16_FW(:3:) response_t : 
         response_t x => { 100 <= x && x < 600};

Punion length_t {
  Pchar unavailable : unavailable == '-';
  Puint32 len;    
};

Precord Pstruct entry_t {
         client_t       client;          
   ' ';  auth_id_t      remoteID;        
   ' ';  auth_id_t      auth;            
   " ["; Pdate(:']':)   date;            
   "] "; request_t      request;         
   ' ';  response_t     response;        
   ' ';  length_t        length;          
};

Psource Parray clt_t {
  entry_t [];
}
