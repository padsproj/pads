// On input ../data/dns:
//   1 question, 1496 answers, 0 auths, 0 others ?
//   The 1 question has domain_name research.att.com, length 9 + 4 + 4 + 1 = 18,
//   plus 4 bytes for qtype/qclass gives length 22.
//   It starts at 14 (0xe), plus 22 = 36 (0x24).
//   
//   Next thing is supposed to be domain name of first resource
//   in answers.  The c00c at that loc is not a legal label,
//   but it is legal pointer (ptr to data offset 0c == research.att.com label),
//   which ends the domain name.
//   The next 2+2+4+2+rdlength bytes are the rest of the resource.
//   These are: 0006 0001 00000e10 0027 (rdlength = 39)
//   total bytes = 12 + 39 = 51.  36 + 51 = 87 (0x57).
//
//   Another c00c (value 0c).
//   000f 0001 00000e10 000a (rdlength = 10)
//   total bytes = 12 + 10 = 22.  87 + 22 = 109 (0x6D)
//
//   etc.

/* PADS specification for DNS */

Pstruct dns_label_t {
   Psbh_uint8(:1:)        length : length < 64; 
   Pa_string_FW(:length:) l;  
};

// For convenience to get the actual pointer from ptr_t field p
int p_offset(Puint16 p) {
  return  p &( 0xC000 -1 ); 
}

Pstruct ptr_t {
  Psbh_uint16(:2:)          p : (p>>14) == 3;
};

Punion label_or_ptr {
  dns_label_t label;
  ptr_t   ptr;
};

int check256(size_t s, size_t offset) {
  if (s > 255) {
    error(ERROR_FATAL, "domain_name beginning at offset %lx has size %lu > 256",(long)offset, (unsigned long)s);
  };
  return 0;
}

// XXX_REMOVE
Puint32 ctr = 0;
int domain_name_dbg(label_or_ptr* elts, Puint32 length, size_t offset) {
  int i;
  fprintf(stderr, "domain_name begins at offset = %lx (ptr target offset == %lx)\n", (long)offset, (long)offset-2);
  fprintf(stderr, "  domain_name: ");
  if (length == 0) {
    fprintf(stderr, "(EMPTY)");
  } else {
    for (i = 0; i < length; i++) {
      if (i != 0) fprintf(stderr, ".");
      if (elts[i].tag == label) {
	fprintf(stderr, "%s", P_fmt_str(&(elts[i].val.label.l)));
      } else {
	fprintf(stderr, "[ptr:%x->%x]", elts[i].val.ptr.p, p_offset(elts[i].val.ptr.p));
      }
    }
  }
  fprintf(stderr, "\n\n");
  //  if (++ctr == 10) abort();
  return 1; 
}

Parray domain_name {
  label_or_ptr [] : Plast(Pparsecheck(check256(eltEnd.offset - begin.offset, begin.offset)
				      || elts[current].tag != label
				      || elts[current].val.label.length == 0)) ;
};


Pstruct character_string {
  Psbh_uint8(:1:)        length;
  Pa_string_FW(:length:) bytes;
}

Pstruct A_t {
  Psbh_uint32(:4:) address;
};

Pstruct CNAME_t {
  domain_name name;
};

Pstruct HINFO_t {
  character_string cpu;
  character_string os;
};

Pstruct MB_t {
  domain_name name;
};

Pstruct MD_t {
  domain_name name;
};

Pstruct MF_t {
  domain_name name;
};

Pstruct MG_t {
  domain_name name;
};

Pstruct MINFO_t {
  domain_name rmailbx;
  domain_name emailbx;
};

Pstruct MR_t {
  domain_name name;
};

Pstruct MX_t {
  Psbh_uint16(:2:) preference;
  domain_name exchange;
};

Pstruct NULL_t(:Puint16 rdlength:) {
  Pa_string_FW(:rdlength:) rdata;
};
  
Pstruct NS_t {
  domain_name name;
};

Pstruct PTR_t {
  domain_name name;
};

Pstruct SOA_t {
  domain_name mname;
  domain_name rname;
  Psbh_uint32(:4:) serial;
  Psbh_uint32(:4:) refresh;
  Psbh_uint32(:4:) retry;
  Psbh_uint32(:4:) expire;
  Psbh_uint32(:4:) minimum;
};

Pstruct WKS_t(:Puint16 rdlength:) {
  Pcompute size_t start = position.offset;
  Psbh_uint32(:4:) address;
  Psbh_uint8(:1:) protocol;
  Pcompute size_t middle = position.offset;
  // Need to make sure rdlength > middle - start
  Pa_string_FW(:rdlength-(middle-start):) bitmap;
};

Parray TXT_t(:Puint16 rdlength:) {
  character_string [] : Plast(Pparsecheck(eltEnd.offset - begin.offset >= rdlength));
};

Pstruct SRV_t {
  Psbh_uint16(:2:) priority;
  Psbh_uint16(:2:) weight;
  Psbh_uint16(:2:) port;
  domain_name target;
};

Pstruct NAPTR_t {
  Psbh_uint16(:2:) order;
  Psbh_uint16(:2:) preference;
  character_string flags;
  character_string services;
  character_string regexp;
  domain_name replacement;
};

Pstruct KX_t {
  Psbh_uint16(:2:) preference;
  domain_name exchanger;
};

Punion domain_name_opt(:Pint8 len:) {
  Pswitch(len){
    Pcase 0 : Pcompute Pint8 x = 0;  // PADS ISSUE: really want a Pvoid here
    Pdefault: domain_name dn;
  }
};

Pstruct A6_t {
  Psbh_uint8(:1:) prefix_len : prefix_len < 129;
  Pa_string_FW(:(prefix_len==128)?0:((128-prefix_len)/8 + 1):) address_suffix; // Note: can be 0 octets
  domain_name_opt(:prefix_len:) prefix;
};

Pstruct DNAME_t {
  domain_name target;
};



Pstruct DS_t(:Puint16 rdlength:) {
  Pcompute size_t start = position.offset;
  Psbh_uint16(:2:) key_tag;
  Psbh_uint8(:1:) algorithm;
  Psbh_uint8(:1:) digest_type;
  domain_name signers_name;
  Pcompute size_t middle = position.offset;
  Pcompute int x = ((rdlength > middle - start) ? 1 : (abort(),0)); 
  // PADS ISSUE:Pabort(predicate) to abort program if constraint failure: i'm not sure this is a good idea.
  // PADS ISSUE:Pomit on Pcompute: what about in unions? coded, but not tested
  // TODO: allow POMIT to precede PCOMPUTE: this requires changing the structure of the parser
  //       and unifying the representation of manifest and normal fields
  // TODO: allow predicates to be given in PCOMPUTEs (syntactic)
  // TODO: add code to check pcompute predicates 
  // TODO: ask BOB about countFieldMan
  // What happens if a union omits a field?
  //   part way through adding code to support this usage.
  // check that union branch names can appear in where clauses
  Pa_string_FW(:rdlength-(middle-start):) digest;
};

Pstruct RP_t {
  domain_name mbox_dname;
  domain_name txt_dname;
};

Pstruct AFSDB_t {
  Psbh_uint16(:2:) subtype;
  domain_name hostname;
};

Pstruct X25_t {
  character_string PSDN_address;
};

Pstruct ISDN_t {
  character_string ISDN_address;
  character_string sa; // FIX: OPTIONAL! RFC 1183
};

Pstruct RT_t {
  Psbh_uint16(:2:) preference;
  domain_name intermediate_host;
};

Pstruct NSAP_t(:Puint16 rdlength:) {
  Pa_string_FW(:rdlength:) nsap;
};

Pstruct SIG_t(:Puint16 rdlength:) {
  // Identical to and obsoleted by RRSIG
  Pcompute size_t start = position.offset;
  Psbh_uint16(:2:) type_covered;
  Psbh_uint8(:1:) algorithm;
  Psbh_uint8(:1:) labels;
  Psbh_uint32(:4:) original_ttl;
  Psbh_uint32(:4:) signature_expiration;
  Psbh_uint32(:4:) signature_inception;
  Psbh_uint16(:2:) key_tag;
  domain_name signers_name;
  Pcompute size_t middle = position.offset;
  // Need to make sure rdlength > middle - start
  Pa_string_FW(:rdlength-(middle-start):) signature;
};

Pstruct KEY_t(:Puint16 rdlength:) {
  // Identical to and obsoleted by DNSKEY
  Pcompute size_t start = position.offset;
  Psbh_uint16(:2:) flags;
  Psbh_uint8(:1:) protocol;
  Psbh_uint8(:1:) algorithm;
  Pcompute size_t middle = position.offset;
  // Need to make sure rdlength > middle - start
  Pa_string_FW(:rdlength-(middle-start):) public_key;
};

Pstruct PX_t {
  Psbh_uint16(:2:) preference;
  domain_name map822;
  domain_name mapx400;
};

Pstruct AAAA_t {
  Pa_string_FW(:16:) address;
};

Pstruct LOC_t {
  Psbh_uint8(:1:) version;
  Psbh_uint8(:1:) size;
  Psbh_uint8(:1:) horiz_pre;
  Psbh_uint8(:1:) vert_pre;
  Psbh_uint32(:4:) latitude;
  Psbh_uint32(:4:) longitude;
  Psbh_uint32(:4:) altitude;
};

Pstruct NXT_t(:Puint16 rdlength:) {
  // Identical to and obsoleted by NSEC
  Pcompute size_t start = position.offset;
  domain_name next_domain_name;
  Pcompute size_t middle = position.offset;
  // Need to make sure rdlength > middle - start
  Pa_string_FW(:rdlength-(middle-start):) type_bit_map;
};

Pstruct RRSIG_t(:Puint16 rdlength:) {
  Pcompute size_t start = position.offset;
  Psbh_uint16(:2:) type_covered;
  Psbh_uint8(:1:) algorithm;
  Psbh_uint8(:1:) labels;
  Psbh_uint32(:4:) original_ttl;
  Psbh_uint32(:4:) signature_expiration;
  Psbh_uint32(:4:) signature_inception;
  Psbh_uint16(:2:) key_tag;
  domain_name signers_name;
  Pcompute size_t middle = position.offset;
  // Need to make sure rdlength > middle - start
  Pa_string_FW(:rdlength-(middle-start):) signature;
};

Pstruct NSEC_t(:Puint16 rdlength:) {
  Pcompute size_t start = position.offset;
  domain_name next_domain_name;
  Pcompute size_t middle = position.offset;
  // Need to make sure rdlength > middle - start
  Pa_string_FW(:rdlength-(middle-start):) type_bit_map;
};

Pstruct DNSKEY_t(:Puint16 rdlength:) {
  Pcompute size_t start = position.offset;
  Psbh_uint16(:2:) flags;
  Psbh_uint8(:1:) protocol;
  Psbh_uint8(:1:) algorithm;
  Pcompute size_t middle = position.offset;
  // Need to make sure rdlength > middle - start
  Pa_string_FW(:rdlength-(middle-start):) public_key;
};

Pstruct TKEY_t {
  domain_name algorithm;
  Psbh_uint32(:4:) inception;
  Psbh_uint32(:4:) expiration;
  Psbh_uint16(:2:) mode;
  Psbh_uint16(:2:) error;
  Psbh_uint16(:2:) key_size;
  Pa_string_FW(:key_size:) key_data;
  Psbh_uint16(:2:) other_size;
  Pa_string_FW(:other_size:) other_data;
};

Pstruct TSIG_t {
  domain_name algorithm;
  Psbh_uint64(:6:) time_signed;
  Psbh_uint16(:2:) fudge;
  Psbh_uint16(:2:) mac_size;
  Pa_string_FW(:mac_size:) mac;
  Psbh_uint16(:2:) original_id;
  Psbh_uint16(:2:) error;
  Psbh_uint16(:2:) other_len;
  Pa_string_FW(:other_len:) other_data;
};

Punion rr_spec (:Puint16 t,Puint16 rdlength:) {
  Pswitch (t) {
  Pcase 1 : A_t A;
  Pcase 2 : NS_t NS;
  Pcase 3 : MD_t MD;
  Pcase 4 : MF_t MF;
  Pcase 5 : CNAME_t CNAME;
  Pcase 6 : SOA_t SOA;
  Pcase 7 : MB_t MB;
  Pcase 8 : MG_t MG;
  Pcase 9 : MR_t MR;
  Pcase 10 : NULL_t(:rdlength:) RRNULL;
  Pcase 11 : WKS_t(:rdlength:) WKS;
  Pcase 12 : PTR_t PTR;
  Pcase 13 : HINFO_t HINFO;
  Pcase 14 : MINFO_t MINFO;
  Pcase 15 : MX_t MX;
  Pcase 16 : TXT_t(:rdlength:) TXT;
  Pcase 17 : RP_t RP;
  Pcase 18 : AFSDB_t AFSDB;
  Pcase 19 : X25_t X25;
  Pcase 20 : ISDN_t ISDN;
  Pcase 21 : RT_t RT;
  Pcase 22 : NSAP_t(:rdlength:) NSAP;
  Pcase 24 : SIG_t(:rdlength:) SIG;
  Pcase 25 : KEY_t(:rdlength:) KEY;
  Pcase 26 : PX_t PX;
  Pcase 28 : AAAA_t AAAA;
  Pcase 29 : LOC_t LOC;
  Pcase 30 : NXT_t(:rdlength:) NXT;
  Pcase 33 : SRV_t SRV;
  Pcase 35 : NAPTR_t NAPTR;
  Pcase 36 : KX_t KX;
  Pcase 38 : A6_t A6;
  Pcase 39 : DNAME_t DNAME;
  Pcase 43 : DS_t(:rdlength:) DS;
  Pcase 46 : RRSIG_t(:rdlength:) RRSIG;
  Pcase 47 : NSEC_t(:rdlength:) NSEC;
  Pcase 48 : DNSKEY_t(:rdlength:) DNSKEY;
  Pcase 249 : TKEY_t TKEY;
  Pcase 250 : TSIG_t TSIG;
  Pdefault : Pa_string_FW(:rdlength:) unknown;
  }
} Pwhere { 
  //   Pparsecheck(fprintf(stderr,"end.offset=%llx,begin.offset=%llx,rdlength=%x\n",
  //   (long long)end.offset,(long long)begin.offset,rdlength)) &&
           Pparsecheck(end.offset - begin.offset == rdlength); };

Pstruct resource_record {
  domain_name              name;
  Psbh_uint16(:2:)         type;
  Psbh_uint16(:2:)         class;
  Psbh_uint32(:4:)         ttl: ttl < (1<<31);    /- should be limited to positive signed 32bit
  Psbh_uint16(:2:)         rdlength;
  rr_spec(:type,rdlength:) rdata;
};

Parray resource_records(:unsigned int size:) {
   resource_record [size];
};

Pstruct question_t {
   domain_name qname;
   Psbh_uint16(:2:) qtype;
   Psbh_uint16(:2:) qclass;
};

Parray questions(:unsigned int size:) {
   question_t [size];
};

Pstruct mheader_t {
   Psbh_uint16(:2:) id;
   Psbh_uint16(:2:) blob;
   Psbh_uint16(:2:) qdcount; /- number of questions
   Psbh_uint16(:2:) ancount; /- number of answers
   Psbh_uint16(:2:) nscount; /- number of authorities
   Psbh_uint16(:2:) arcount; /- number of additionals
};

int cnt_dbg(const char *cnt_descr, unsigned int cnt) {
  //  fprintf(stderr, "# of %s = %u\n", cnt_descr, cnt);
  return 1;
};

Pstruct dns_msg {
   Psbh_uint16(:2:)                   length;
   mheader_t                           header :   cnt_dbg("questions", header.qdcount);  /- not? OK to use "header" for both?
   questions(:header.qdcount:)        question:  cnt_dbg("answers",   header.ancount);
   resource_records(:header.ancount:) answer:    cnt_dbg("auths",     header.nscount);
   resource_records(:header.nscount:) authority: cnt_dbg("other",     header.arcount);
   resource_records(:header.arcount:) additional;
};


Psource Parray dns_msg_array{
  dns_msg[];
}
