Parray nIP {
  Puint8 [4] : Psep('.') && Pterm(Pnosep);          
};

Parray sIP{
  Pstring_SE(:"/[. ]/":) [] : Psep('.') && Pterm(Pnosep); 
};

Punion clihost_t {
  sIP symbolic;    /- www.research.att.com
  nIP resolved;    /- 135.207.23.32
};

Ptypedef Pchar unknown_t : unknown_t x => { x == '-'};

Punion f_auth_id_t {
  unknown_t unauthorized_f;         /- non-authenticated http session
  Pstring(:' ':) id;              /- login supplied during authentication
};

Punion s_auth_id_t {
  unknown_t unauthorized_s;         /- non-authenticated http session
  Pstring_SE(:"/ [[]/":) id;              /- login supplied during authentication
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
    GET,     PUT,     POST,     HEAD,     DELETE,  OPTIONS, CONNECT, PROPFIND,
    LINK,        /- Unused after http 1.0
    UNLINK       /- Unused after http 1.0
};

int  checkVersion(http_v_t version, http_method_t meth) {
  if ((version.major == 1) && (version.minor == 0)) return 1;
  if ((meth == LINK)  || (meth == UNLINK )) return 0;
  return 1;
}

Pstruct http_request_t {
          http_method_t meth;             /- Method used during request
  ' ';    Pstring(:' ':) req_uri;         /- Requested uri.
  ' ';    http_v_t       version : checkVersion(version, meth); /- HTTP version number of request 
};

Punion http_request_vars_t{
  http_request_t  standard_http_request;
  Pstring(:'\"':) alternate_http_request;
}

Pstruct q_http_request_t {
  '\"';   
  http_request_vars_t request;
  '\"';
};

Pstruct refPage_t{
  "\"";
  Pstring(:'\"':) referring_page;
  "\"";
}

Ptypedef Pstring_SE(:"/[ +(]/":) BrowserVersion_t;

Penum BrowserName_t  {msnbotMedia Pfrom("msnbot-media"),
                      Mozilla, msnbot,Baiduspider,DoCoMo,Safari,
    SAMSUNG Pfrom ("SAMSUNG-SGH-E250"),
    MailRu Pfrom("Mail.Ru"),
    /*    Java,
    WinHttp, */
    SpeedySpider Pfrom("Speedy Spider"), 
    renlifangbot,
    ia_archiver,
    TMobileMozilla Pfrom("T-Mobile Dash Mozilla"),
    rdfbot, GingerCrawler, 
    SogouWebSpider Pfrom("Sogou web spider"),
    Yandex
                       };


Pstruct BrowserMessageBody_t{
  BrowserVersion_t version;
  Pre "/[ +]?/";
  Pstring(:'\"':) browser_info;
}

Punion BrowserMessage_t(:BrowserName_t n:){
  Pswitch (n){
    Pcase Mozilla     :  BrowserMessageBody_t mozilla_v;
    Pcase msnbot      :  BrowserMessageBody_t msbnot_v;
    Pcase Baiduspider :  BrowserMessageBody_t baiduspider_v;
    Pcase SAMSUNG     :  BrowserMessageBody_t samsung_v;
    Pcase msnbotMedia :  BrowserMessageBody_t msbnotMedia_v;
    Pcase DoCoMo      :  BrowserMessageBody_t docomo_v;
    Pcase SpeedySpider    :  BrowserMessageBody_t speedySailor_v;
    Pcase Safari          :  BrowserMessageBody_t safari_v;
    Pcase TMobileMozilla  :  BrowserMessageBody_t tmobile_v;
    Pcase rdfbot      :  BrowserMessageBody_t rdfbot_v;
    Pdefault :           BrowserMessageBody_t default_v;
  }
}

Pstruct browserInfo_t{
  BrowserName_t browser;
  BrowserMessage_t(:browser:) b_body;
}


Punion optBrowserInfo_t{
  unknown_t unknownBrowser;
  browserInfo_t bInfo;
  Pstring(:'\"':) otherBrowserInfo;
}

Precord Pstruct pws_t {
        clihost_t host;                   /- IP address of client requesting service
   ' '; f_auth_id_t remoteID;               /- Remote identity; '-' indicates not obtained.
   ' '; s_auth_id_t auth;                   /- Name of authenticated user.
   " [";
   Ptimestamp(:']':) ts;                  /- Timestamp of request.
   "] "; q_http_request_t request;                /- Request.
   ' ';  Puint16_FW(:3:) response;        /- 3-digit response code
   ' ';  contentOpt_t contentLength;      /- Number of bytes in request response.
   ' ';  refPage_t uInfo;
   " \"";  optBrowserInfo_t bInfo;
   "\"";
};

Psource Parray log_t {
  pws_t [];
}
