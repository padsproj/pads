Punion Host_t{
  Pip             ipAddress;
  Pstring(:' ':)  hostName;
};

Punion Auth_t{
  Pchar          unavailable : unavailable == '-';
  Pstring(:' ':) name;
};

Penum Method_t{GET,HEAD, OPTIONS, POST, T, PROPFIND};

Ptypedef Pstring(:' ':) Path_t; 
Ptypedef Pstring_SE(:"/\" /":) Url_t;

Pstruct Version_t{
  "HTTP/";  Puint8         major;
  '.';      Puint8_FW(:1:) minor;
};

Ptypedef Puint16 Response_t : Response_t x => {(x == 0) || (200 <= x && x < 600)};

Punion Platform_t{
  Pstring_ME(:"/PSP \\(Playstation Portable\\); 2.00/":) PSP;
  Pstring_SE(:"/[;)]/":)                                 Other;
}

Pstruct PlatformInfo_t{
   ' '; 
   '('; Platform_t[] platform : Psep("; ") && Pterm(Pre "/;?\\)/"); 
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

Punion Agent_t{
  Browser_t[]    browsers : Psep(' ') && Pterm('"');
  Pstring(:'"':) agentDesc;
};

Punion OptUint32_t{
  Pchar   intMissing : intMissing == '-';
  Puint32 intValue ;
};

Pstruct NameValue_t{
       Pstring(:'=':) label;
  '='; Pstring_SE(:"/;|$/":) value;
};

Pstruct RMFD_t{
    Pstring_SE(:"/[|;]|$/":)[] items : Psep('|') && Pterm(Pre "/;|$/");
};

Pstruct Attribute_t{
       Pstring(:'=':) attributeName;
  '='; Pstring_SE(:"/[;#]|$/":) attributeValue;
};

Pstruct Attributes_t{
  Attribute_t[] attribute : Psep(Pre "/#(____)?/") && Pterm(Pre "/#?(____)?(;|$)/");
  Pre "/#?(____)?/";
};

Pstruct PivaInfo_t{
        Puint32_FW(:10:) first;
  '.';  Puint32_FW(:5:)  second;
  '.';  Puint32_FW(:4:)  third;
};

Penum YN_t{yes,no};
Penum Bool_t{true, false};

Penum StateName_t{JSESSIONID, 
		  DYN_USER_ID, DYN_USER_CONFIRM,  
	          YPC_ANON_ID,YPC_RECENT_SEARCH, YPC_RECENT_LISTING, YPC_REF, YPC_DEFAULT_LOCATION,
		  RMID, RMFD, RMFL, RMFH, RMFS,
                  SELLUID, PREF_PERM, PREF_SESSION,
		  Default_Location,
		  BIGipServerpPivaBrick, BIGipServerPIVIA_NODES, 
		  yptoolbar_id,  yptoolbar_visible, yellowpbar_id, yellowpbar_visible, yel_news, 
		  Version Pfrom("$Version"), custClass, local_state, affinity, Enabled,
		  CFC7FA0342, BCSI Pfrom("BCSI-CSAC18EE89")};

Punion StateValue_t(:StateName_t state:){
  Pswitch (state) {
    Pcase JSESSIONID          : Pstring_FW(:23:)      jsession_id;
    Pcase DYN_USER_ID         : Pstring_SE(:"/;|$/":) dyn_user_id;
    Pcase DYN_USER_CONFIRM    : Pstring_FW(:32:)      dyn_user_confirm;
    Pcase YPC_ANON_ID         : Puint64               ypc_anon_id;
    Pcase YPC_RECENT_SEARCH   : Attributes_t          ypc_recent_search; // name value pairs, separated by #
    Pcase YPC_RECENT_LISTING  : Attributes_t          ypc_recent_listing; // name value pairs, separeted by #
    Pcase YPC_REF             : Pstring_SE(:"/;|$/":) ypc_ref;
    Pcase RMID        : Pstring_SE(:"/;|$/":) rmid;  
    Pcase RMFD        : RMFD_t                rmfd; 
    Pcase RMFL        : Pstring_SE(:"/;|$/":) rmfl;
    Pcase RMFH        : Pstring_SE(:"/;|$/":) rmfh;
    Pcase RMFS        : Pstring_SE(:"/;|$/":) rmfs;
    Pcase Default_Location    : Pstring_SE(:"/;|$/":) default_location;   // all empty
    Pcase BIGipServerpPivaBrick   : PivaInfo_t        bigIPServerpPivaBrick;  //int_fw(10) . int_fw(5) . int_fw(4)
    Pcase BIGipServerPIVIA_NODES  : PivaInfo_t        bigIPServerPivia_nodes; //int_fw(10) . int_fw(5) . int_fw(4)
    Pcase PREF_PERM               : Pstring_SE(:"/;|$/":) pref_perm;      // not enough data.
    Pcase PREF_SESSION            : Pstring_SE(:"/;|$/":) pref_session;      // not enough data.
    Pcase SELLUID                 : Pstring_SE(:"/;|$/":) selluid;
    Pcase yptoolbar_id            : Pstring_SE(:"/;|$/":) yptoolbar_ID;
    Pcase yptoolbar_visible       : YN_t                  yptoolbar_Visible;
    Pcase yellowpbar_id           : Pstring_SE(:"/;|$/":) yellowpbar_ID;
    Pcase yellowpbar_visible      : YN_t                  yellowpbar_Visible;
    Pcase yel_news                : Pstring_SE(:"/;|$/":) yel_News;
    Pcase Version                 : Puint8                version;
    Pcase YPC_DEFAULT_LOCATION    : Attributes_t          ypc_default_location;
    Pcase CFC7FA0342              : Pstring_SE(:"/;|$/":) unknown1;
    Pcase BCSI                    : Puint8                unknown2;
    Pcase custClass               : Puint8                cust_class;
    Pcase Enabled                 : Bool_t                enabled;
    Pdefault                      : Pstring_SE(:"/;|$/":) otherValue;
  }
};

Pstruct PreciseNameValue_t{
              StateName_t               stateName;
  Pre "/=?/"; StateValue_t(:stateName:) stateValue;
};

Punion GeneralNameValue_t{
  PreciseNameValue_t knownName;
  NameValue_t        unknownName;
};

Pstruct Trailer_t{
  ' '; GeneralNameValue_t[] nameValue : Psep(Pre "/; ?/") && Pterm(Pre "/;?$/");
  Pre "/;?/";
};

Punion TrailerOpt_t{
  noTrailer Pfrom(" -");
  Trailer_t trailer;
};

Precord Pstruct Entry_t{
        Host_t  requestSource;
  ' ';  Auth_t  remoteID;
  ' ';  Auth_t  authID;
  " ["; Ptimestamp(:']':) ts;                  
  "] "; Request_t         request;
  ' ';  Response_t        response;
  ' ';  Puint32           numBytes;
  ' ';
  '"';  Url_t             rootUrl;
  '"'; 
  ' '; 
  '"';  Agent_t           agent;
  '"';
  ' ';  Pstring(:' ':)    unknownString;
  ' ';  OptUint32_t       unknownInt;
        Popt TrailerOpt_t trailer;
};
