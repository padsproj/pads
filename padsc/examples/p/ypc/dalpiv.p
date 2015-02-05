Punion Host_t{
  Pip             ipAddress;
  Pstring(:' ':)  hostName;
};

Punion Auth_t{
  Pchar          unavailable : unavailable == '-';
  Pstring(:' ':) name;
};

Penum Method_t{GET,POST};

Ptypedef Pstring(:' ':) Path_t; 
Ptypedef Pstring(:'"':) Url_t;

Pstruct Version_t{
  "HTTP/";  Puint8 major;
  '.';      Puint8 minor;
};

Ptypedef Puint16 Response_t : Response_t x => {200 <= x && x < 600};

Pstruct PlatformInfo_t{
   ' '; 
   '('; Pstring_SE(:"/[;)]/":)[] platform : Psep("; ") && Pterm(Pre "/;?\\)/"); 
   Pre "/;?/";
   ')';
};

Pstruct Browser_t{
        Pstring_SE(:"=[/ ]=":) browserName;
   Pre "=[/ ]=";
   Pstring_SE(:"/[ \"]/":)     version;
   Popt PlatformInfo_t         platformInfo;
   Pre "/(  \\[en\\])?/";
};

Pstruct Request_t{
  '"'; Method_t   method;
  ' '; Path_t     path;
  ' '; Version_t  version;
  '"';
};

Precord Pstruct Entry_t{
        Host_t  requestSource;
  ' ';  Auth_t  remoteID;
  ' ';  Auth_t  authID;
  " ["; Ptimestamp(:']':) ts;                  
  "] "; Request_t request;
  ' ';  Response_t response;
  ' ';  Puint32    numBytes;
  ' ';
  '"';  Url_t      rootUrl;
  '"'; 
  ' '; 
  '"';  Browser_t[] browsers : Psep(' ') && Pterm('"');
  '"';
  ' ';  Pstring(:' ':) unknownString;
  ' ';  Puint32        unknownInt;
};
