// soma_cpe_stats_out.p
//
// Header:
// Sector Name|Sector IP Address|WHATEVER|ESN|Date|Time|\
// cpeConnectionState|cpeCrnti|cpeDiscardsFromCpe|cpeDiscardsToCpe|cpeIpAddress|\
// cpeMaxDownlinkBitrate|cpeMaxUplinkBitrate|cpeOctetsInFromCpe|cpeOctetsOutToCpe|\
// cpePktsFromCpe|cpePktsToCpe|cpeRadioLinkFailures
//
// Data:
// Frontage|75.30.171.7|BS_RSC_0|33000000CAAA4DC0|01-09-2007|04:00|2|161|0|0|75.30.168.162|784000|9600|32331|9189|5790|59|0

Precord Pstruct SomaCPEStat_out_header_t
{
	"Sector Name|Sector IP Address|WHATEVER|ESN|Date|Time|cpeConnectionState|cpeCrnti|cpeDiscardsFromCpe|cpeDiscardsToCpe|cpeIpAddress|cpeMaxDownlinkBitrate|cpeMaxUplinkBitrate|cpeOctetsInFromCpe|cpeOctetsOutToCpe|cpePktsFromCpe|cpePktsToCpe|cpeRadioLinkFailures";
};

Precord Pstruct SomaCPEStat_out_t
{
	Pstring(:'|':) sectorName;	// A string followed immediately by an underscore
	Pip sectorIPAddr;		// An IP address (ends with '.')
	'|'; Pstring(:'|':) whatever;	// Sector ID actually
	'|'; Pstring(:'|':) ESN;
	'|'; 
	Ptimestamp_explicit_SE(: "/|/", "%m-%d-%Y|%H:%M", P_cstr2timezone("-0800"):) collectionTimestamp;
					// A time stamp ending with the end of the record, 
					// in the format 2digit month, day, hour, minute 
					// 4digit year with date and time separated by a pipe
					// character. E.g. 01-09-2007|04:00
					// Treated as time local to PST.
	'|'; Pstring(:'|':) cpeConnectionState;
	'|'; Pstring(:'|':) cpeCrnti;
	'|'; Pstring(:'|':) cpeDiscardsFromCpe;
	'|'; Pstring(:'|':) cpeDiscardsToCpe;
	'|'; Pstring(:'|':) cpeIpAddress;
	'|'; Pstring(:'|':) cpeMaxDownlinkBitrate;
	'|'; Pstring(:'|':) cpeMaxUplinkBitrate;
	'|'; Pstring(:'|':) cpeOctetsInFromCpe;
	'|'; Pstring(:'|':) cpeOctetsOutToCpe;
	'|'; Pstring(:'|':) cpePktsFromCpe;
	'|'; Pstring(:'|':) cpePktsToCpe;
	'|'; Pstring(:'|':) cpeRadioLinkFailures;
};

Parray SomaCPEStats_out_t { SomaCPEStat_out_t []; };

Psource Pstruct SomaCPEStats_out {
	SomaCPEStat_out_header_t header;
	SomaCPEStats_out_t       details;
};
