Parray nIP {
  Puint8 [4] : Psep('.') && Pterm(Pnosep);          
};

Parray sIP{
  Pstring_SE(:"/[. ]/":) [] : Psep('.') && Pterm(Pnosep); 
};

Punion clihost_t {
  nIP resolved;    /- 135.207.23.32
  sIP symbolic;    /- www.research.att.com
};

Ptypedef Pchar unknown_t : unknown_t x => { x == '-'};

Punion auth_id_t {
  unknown_t unauthorized;         /- non-authenticated http session
  Pstring(:' ':) id;              /- login supplied during authentication
};

Punion contentOpt_t {
  Puint32 len;                    /- length available
  unknown_t unavailable;
};

Pstruct http_v_t {
  "HTTP/";
  Puint8 major; '.';
  Puint8 minor;           /- http minor mode
};

Penum http_method_t {
    GET,     PUT,     POST,     HEAD,     DELETE, 
    LINK,        /- Unused after http 1.0
    UNLINK       /- Unused after http 1.0
};

int  checkVersion(http_v_t version, http_method_t meth) {
  if ((version.major == 1) && (version.minor == 0)) return 1;
  if ((meth == LINK)  || (meth == UNLINK )) return 0;
  return 1;
}

Pstruct http_request_t {
  '\"';   http_method_t meth;             /- Method used during request
  ' ';    Pstring(:' ':) req_uri;         /- Requested uri.
  ' ';    http_v_t       version : checkVersion(version, meth); /- HTTP version number of request 
  '\"';
};

Precord Pstruct http_clf_t {
        clihost_t host;                   /- IP address of client requesting service
   ' '; auth_id_t remoteID;               /- Remote identity; '-' indicates not obtained.
   ' '; auth_id_t auth;                   /- Name of authenticated user.
   " [";
   Ptimestamp(:']':) ts;                  /- Timestamp of request.
   "] ";
   http_request_t request;                /- Request.
   ' ';  Puint16_FW(:3:) response;        /- 3-digit response code
   ' ';  contentOpt_t contentLength;      /- Number of bytes in request response.
};

Psource Parray log_t {
  http_clf_t [];
}
