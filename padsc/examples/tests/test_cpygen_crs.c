#include "pads.h"
#include "cpygen_crs.h"

/* declared in cpygen_crs.[ph], initialized here : */
Puint64 num_recs = 0;

void print_cpy_crsdet(P_t* pads, cpy_crsdet *tt);

int main(int argc, char** argv) {
  P_t             *pads;
  Pio_disc_t*     io_disc;
  Pdisc_t         my_disc = Pdefault_disc;

  cpy_crshdr         hdr_rep;
  cpy_crshdr_pd      hdr_pd;

  det_or_tlr         rep;
  det_or_tlr_pd      pd;
  cpy_crsdet_acc     acc;

  char              *fileName;
  Perror_t        e;
  
  if (argc == 2) {
    fileName = argv[1];
    error(0, "Data file = %s\n", fileName);
  } else {
    fileName = "/dev/stdin";
    error(0, "Data file = standard in\n");
  }

  io_disc = P_fwrec_noseek_make(0, 86, 0);

  if (!io_disc) {
    error(ERROR_FATAL, "\nFailed to install IO discipline");
  } else {
    error(0, "\nInstalled IO discipline %s", io_disc->name);
  }

  if (P_ERR == P_open(&pads, &my_disc, io_disc)) {
    error(2|ERROR_FATAL, "*** P_open failed ***");
  }

  if (P_ERR == P_io_fopen(pads, fileName)) {
    error(2|ERROR_FATAL, "*** P_io_fopen failed ***");
  }

  if (P_ERR == cpy_crshdr_init(pads, &hdr_rep)) {
    error(2|ERROR_FATAL, "*** cpy_crshdr representation initialization failed ***");
  }
  if (P_ERR == cpy_crshdr_pd_init(pads, &hdr_pd)) {
    error(2|ERROR_FATAL, "*** cpy_crshdr error description initialization failed ***");
  }


  if (P_ERR == det_or_tlr_init(pads, &rep)) {
    error(2|ERROR_FATAL, "*** det_or_tlr representation initialization failed ***");
  }
  if (P_ERR == det_or_tlr_pd_init(pads, &pd)) {
    error(2|ERROR_FATAL, "*** det_or_tlr error description initialization failed ***");
  }

  if (P_ERR == cpy_crsdet_acc_init(pads, &acc)) {
    error(2|ERROR_FATAL, "*** cpy_crsdet accumulator initialization failed ***");
  }

  /*
   * Try to read the header
   */
  if (P_OK != cpy_crshdr_read(pads, 0, &hdr_pd, &hdr_rep)) {
    error(2|ERROR_FATAL, "crshdr_read returned error");
  }
  error(0, "HEADER INFO:");
  error(0, "          XX_COPY_ID_8: %s", hdr_rep.XX_CRS_HEADER_1.XX_COPY_ID_8.str);
  error(0, "           XX_RPC_CD_8: %s", hdr_rep.XX_CRS_HEADER_1.XX_RPC_CD_9.str);
  error(0, "  XX_BILL_CYCLE_DATE_3: %02llu/%02llu/%02llu",
	hdr_rep.XX_CRS_HEADER_1.XX_BILL_CYCLE_DATE_3.XX_BILL_CYC_MM_5,
	hdr_rep.XX_CRS_HEADER_1.XX_BILL_CYCLE_DATE_3.XX_BILL_CYC_DD_6,
	hdr_rep.XX_CRS_HEADER_1.XX_BILL_CYCLE_DATE_3.XX_BILL_CYC_YY_4);
  error(0, "     XX_CREATE_DATE_11: %02llu/%02llu/%02llu\n",
	hdr_rep.XX_CRS_HEADER_1.XX_CREATE_DATE_11.XX_CREATE_MM_13,
	hdr_rep.XX_CRS_HEADER_1.XX_CREATE_DATE_11.XX_CREATE_DD_14,
	hdr_rep.XX_CRS_HEADER_1.XX_CREATE_DATE_11.XX_CREATE_YY_12);

  /*
   * Try to read each line of data
   */
  while (!P_io_at_eof(pads)) {
    e = det_or_tlr_read(pads, 0, &pd, &rep);
    if (rep.tag == is_tlr) break;
    num_recs++;
    if (e == P_ERR) {
      error(2, "det_or_tlr_read returned error");
    } else {
      print_cpy_crsdet(pads, &(rep.val.is_det));
    }
    /* accum both good and bad vals */
    if (P_ERR == cpy_crsdet_acc_add(pads, &acc, &(pd.val.is_det), &(rep.val.is_det))) {
      error(2|ERROR_FATAL, "*** accumulator add failed ***");
    }
  }
  if (rep.tag == is_tlr) {
    error(0, "TRAILER INFO:");
    error(0, "          XX_TOTAL_RECORDS_3: %llu", rep.val.is_tlr.XX_CRS_TRAILER_1.XX_TOTAL_RECORDS_3);
    error(0, "         compare to num_recs: %llu\n", num_recs);
  }

  if (P_ERR == cpy_crsdet_acc_report(pads, "", 0, 0, &acc)) {
    error(0, "** accum_report failed **");
  }

  if (P_ERR == P_io_close(pads)) {
    error(2|ERROR_FATAL, "*** P_io_close failed ***");
  }

  if (P_ERR == det_or_tlr_cleanup(pads, &rep)) {
    error(0, "** representation cleanup failed **");
  }

  if (P_ERR == det_or_tlr_pd_cleanup(pads, &pd)) {
    error(0, "** error descriptor cleanup failed **");
  }

  if (P_ERR == cpy_crsdet_acc_cleanup(pads, &acc)) {
    error(0, "** accumulator cleanup failed **");
  }

  if (P_ERR == P_close(pads)) {
    error(2|ERROR_FATAL, "*** P_close failed ***");
  }

  return 0;
}

#define	PR_O(ofst)				error(ERROR_PROMPT, "%d:", (int)(ofst))
#define	PR_T_CHARS(nm,ff,ofst)			PR_O(ofst), error(0, "%s" #nm ": '%.*s'", indent, (ff)->len, (ff)->str)
#define	PR_T_NUM(nm,ff,ofst)			PR_O(ofst), error(0, "%s" #nm ": %lld", indent, (*(ff)))
#define	PR_T_SNUM(nm,ff,ofst)			PR_O(ofst), error(0, "%s" #nm ": %lld", indent, (*(ff)))
#define	PR_T_BCD(nm,ff,ofst)			PR_O(ofst), error(0, "%s" #nm ": %lld", indent, (*(ff)))
#define	PR_T_SBCD(nm,ff,ofst)			PR_O(ofst), error(0, "%s" #nm ": %lld", indent, (*(ff)))
#define	PR_T_BINARY(nm,ff,ofst)			PR_O(ofst), error(0, "%s" #nm ": %lld", indent, (*(ff)))
#define	PR_T_UBINARY(nm,ff,ofst)		PR_O(ofst), error(0, "%s" #nm ": %lld", indent, (*(ff)))
#define	PR_T_FIXEDPOINT(nm,ff,ofst,z,d)		PR_O(ofst), error(0, "%s" #nm ": %*.*f", indent, z, d, P_FPOINT2FLT(*ff))
#define	PR_T_SFIXEDPOINT(nm,ff,ofst,z,d)	PR_O(ofst), error(0, "%s" #nm ": %*.*f", indent, z, d, P_FPOINT2FLT(*ff))
#define	PR_T_SBCDFIXEDPOINT(nm,ff,ofst,z,d)	PR_O(ofst), error(0, "%s" #nm ": %*.*f", indent, z, d, P_FPOINT2FLT(*ff))
#define	PR_T_UBINFIXEDPOINT(nm,ff,ofst,z,d)	PR_O(ofst), error(0, "%s" #nm ": %*.*f", indent, z, d, P_FPOINT2FLT(*ff))

static char *tabs = "\t\t\t\t\t\t\t\t\t\t\t\t\t";

static void
pr_XX_GROSS_AND_DISCS_21_crsdet(P_t* pads, char *indent, int offset, XX_GROSS_AND_DISCS_21_crsdet *tt)
{
  error(0, "%sXX_GROSS_AND_DISCS_21_crsdet >>>>>>aggr", indent--);
  PR_T_SBCDFIXEDPOINT(XX_GROSS_USAGE_22, &(tt->XX_GROSS_USAGE_22), offset, 9, 2);
  PR_T_SBCDFIXEDPOINT(XX_DISC_AMT_23, &(tt->XX_DISC_AMT_23),    offset+6, 9, 2);
}
static void
pr_XX_TOTALS_BY_JURISD_RD_20_crsdet(P_t* pads, char *indent, int offset, XX_TOTALS_BY_JURISD_RD_20_crsdet *tt)
{
  error(0, "%sXX_TOTALS_BY_JURISD_RD_20_crsdet >>>>>>aggr", indent--);
  {
    int i;
    for(i = 0; i < 5; i++) {
      pr_XX_GROSS_AND_DISCS_21_crsdet(pads, indent, offset+(i*12),
				      &(tt->XX_GROSS_AND_DISCS_21.elts[i]));
    }
  }
}
static void
HACK_pr_XX_TOTALS_BY_JURISD_RD_20_crsdet(P_t* pads, char *indent, int offset, XX_TOTALS_BY_JURISD_4_crsdet *tt)
{
  error(0, "%sXX_TOTALS_BY_JURISD_RD_20_crsdet >>>>>>aggr", indent--);
  pr_XX_GROSS_AND_DISCS_21_crsdet(pads, indent, offset, (XX_GROSS_AND_DISCS_21_crsdet*)&(tt->XX_DOM_GROSS_AND_DISCS_5));
  pr_XX_GROSS_AND_DISCS_21_crsdet(pads, indent, offset+12,  (XX_GROSS_AND_DISCS_21_crsdet*)&(tt->XX_CAN_GROSS_AND_DISCS_8));
  pr_XX_GROSS_AND_DISCS_21_crsdet(pads, indent, offset+24,  (XX_GROSS_AND_DISCS_21_crsdet*)&(tt->XX_OVS_GROSS_AND_DISCS_11));
  pr_XX_GROSS_AND_DISCS_21_crsdet(pads, indent,  offset+36, (XX_GROSS_AND_DISCS_21_crsdet*)&(tt->XX_MEX_GROSS_AND_DISCS_14));
  pr_XX_GROSS_AND_DISCS_21_crsdet(pads, indent,  offset+48, (XX_GROSS_AND_DISCS_21_crsdet*)&(tt->XX_LOC_GROSS_AND_DISCS_17));
}
static void
pr_XX_LOC_GROSS_AND_DISCS_17_crsdet(P_t* pads, char *indent, int offset, XX_LOC_GROSS_AND_DISCS_17_crsdet *tt)
{
  error(0, "%sXX_LOC_GROSS_AND_DISCS_17_crsdet >>>>>>aggr", indent--);
  PR_T_SBCDFIXEDPOINT(XX_LOC_GROSS_USAGE_18, &(tt->XX_LOC_GROSS_USAGE_18), offset, 9, 2);
  PR_T_SBCDFIXEDPOINT(XX_LOC_DISC_AMT_19, &(tt->XX_LOC_DISC_AMT_19), offset+6, 9, 2);
}
static void
pr_XX_MEX_GROSS_AND_DISCS_14_crsdet(P_t* pads, char *indent, int offset, XX_MEX_GROSS_AND_DISCS_14_crsdet *tt)
{
  error(0, "%sXX_MEX_GROSS_AND_DISCS_14_crsdet >>>>>>aggr", indent--);
  PR_T_SBCDFIXEDPOINT(XX_MEX_GROSS_USAGE_15, &(tt->XX_MEX_GROSS_USAGE_15), offset, 9, 2);
  PR_T_SBCDFIXEDPOINT(XX_MEX_DISC_AMT_16, &(tt->XX_MEX_DISC_AMT_16), offset+6, 9, 2);
}
static void
pr_XX_OVS_GROSS_AND_DISCS_11_crsdet(P_t* pads, char *indent, int offset, XX_OVS_GROSS_AND_DISCS_11_crsdet *tt)
{
  error(0, "%sXX_OVS_GROSS_AND_DISCS_11_crsdet >>>>>>aggr", indent--);
  PR_T_SBCDFIXEDPOINT(XX_OVS_GROSS_USAGE_12, &(tt->XX_OVS_GROSS_USAGE_12), offset, 9, 2);
  PR_T_SBCDFIXEDPOINT(XX_OVS_DISC_AMT_13, &(tt->XX_OVS_DISC_AMT_13), offset+6, 9, 2);
}
static void
pr_XX_CAN_GROSS_AND_DISCS_8_crsdet(P_t* pads, char *indent, int offset, XX_CAN_GROSS_AND_DISCS_8_crsdet *tt)
{
  error(0, "%sXX_CAN_GROSS_AND_DISCS_8_crsdet >>>>>>aggr", indent--);
  PR_T_SBCDFIXEDPOINT(XX_CAN_GROSS_USAGE_9, &(tt->XX_CAN_GROSS_USAGE_9), offset, 9, 2);
  PR_T_SBCDFIXEDPOINT(XX_CAN_DISC_AMT_10, &(tt->XX_CAN_DISC_AMT_10), offset+6, 9, 2);
}
static void
pr_XX_DOM_GROSS_AND_DISCS_5_crsdet(P_t* pads, char *indent, int offset, XX_DOM_GROSS_AND_DISCS_5_crsdet *tt)
{
  error(0, "%sXX_DOM_GROSS_AND_DISCS_5_crsdet >>>>>>aggr", indent--);
  PR_T_SBCDFIXEDPOINT(XX_DOM_GROSS_USAGE_6, &(tt->XX_DOM_GROSS_USAGE_6), offset, 9, 2);
  PR_T_SBCDFIXEDPOINT(XX_DOM_DISC_AMT_7, &(tt->XX_DOM_DISC_AMT_7), offset+6, 9, 2);
}
static void
pr_XX_TOTALS_BY_JURISD_4_crsdet(P_t* pads, char *indent, int offset, XX_TOTALS_BY_JURISD_4_crsdet *tt)
{
  error(0, "%sXX_TOTALS_BY_JURISD_4_crsdet >>>>>>aggr", indent--);
  pr_XX_DOM_GROSS_AND_DISCS_5_crsdet(pads, indent, offset, &(tt->XX_DOM_GROSS_AND_DISCS_5));
  pr_XX_CAN_GROSS_AND_DISCS_8_crsdet(pads, indent, offset+12,  &(tt->XX_CAN_GROSS_AND_DISCS_8));
  pr_XX_OVS_GROSS_AND_DISCS_11_crsdet(pads, indent, offset+24,  &(tt->XX_OVS_GROSS_AND_DISCS_11));
  pr_XX_MEX_GROSS_AND_DISCS_14_crsdet(pads, indent,  offset+36, &(tt->XX_MEX_GROSS_AND_DISCS_14));
  pr_XX_LOC_GROSS_AND_DISCS_17_crsdet(pads, indent,  offset+48, &(tt->XX_LOC_GROSS_AND_DISCS_17));
}
static void
pr_XX_CRS_RECORD_1_crsdet(P_t* pads, char *indent, int offset, XX_CRS_RECORD_1_crsdet *tt)
{
  error(0, "%sXX_CRS_RECORD_1_crsdet >>>>>>aggr", indent--);
  PR_T_CHARS(XX_LEAD_ACCT_NUM_2, &(tt->XX_LEAD_ACCT_NUM_2), offset);
  PR_T_CHARS(XX_SUB_ACCT_NUM_3, &(tt->XX_SUB_ACCT_NUM_3), offset+13);
  if (tt->GEN_UNION_1.tag != XX_TOTALS_BY_JURISD_4_arm) {
    error(2|ERROR_FATAL, "XXX Unexpected: tag is not first tag.\n"
	  "XXX A redefine should match all punion arms, so tag should always be first tag");
  }
  /* XXX ignore tag and print redefine-based union value both ways, since that is what Hume's code does. */
  pr_XX_TOTALS_BY_JURISD_4_crsdet(pads, indent, offset+26,
				  &(tt->GEN_UNION_1.val.XX_TOTALS_BY_JURISD_4_arm));
#if 0
  pr_XX_TOTALS_BY_JURISD_RD_20_crsdet(pads, indent, offset+26,
				      &(tt->GEN_UNION_1.val.XX_TOTALS_BY_JURISD_RD_20_crsdet));
#else
  /* XXX hack: the representation differs due to use of variable length array so need to fake it here */
  HACK_pr_XX_TOTALS_BY_JURISD_RD_20_crsdet(pads, indent, offset+26,
					   &(tt->GEN_UNION_1.val.XX_TOTALS_BY_JURISD_4_arm));
#endif
}
static void
pr_cpy_crsdet(P_t* pads, char *indent, int offset, cpy_crsdet *tt)
{
  error(0, "%scpy_crsdet >>>>>>aggr", indent--);
  pr_XX_CRS_RECORD_1_crsdet(pads, indent, offset, &(tt->XX_CRS_RECORD_1));
}

void
print_cpy_crsdet(P_t* pads, cpy_crsdet *tt)
{
  pr_cpy_crsdet(pads, strchr(tabs, 0), 0, tt);
}

