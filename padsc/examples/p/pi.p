
Pstruct quarter_t {
        '\"';
        Puint16 myyear;
        '.';
        Puint8 myquarter;
        '\"';
};

Parray quarters_t {
        quarter_t [] : Psep(',');
};

Precord Pstruct table_header_t {
        "\"Personal income\",";
        "\"FIPS\",";
        "\"AreaName\",";
        quarters_t my_quarters;
};

Parray incomeseq {
        Puint32[]: Psep(',');
};

Precord Pstruct entry_t {
        "\"010\",\"";
        Pstring_ME(:"/\\d\\d/":) areacode;
        "\",\"";
        Pstring(:'\"':) areaname;
        "\",";
        incomeseq incomes;
};

Precord Ptypedef Pstring_SE(:Peor:) Eor_t;

Psource Pstruct quarter_income_t {
        table_header_t h;
        entry_t[] es: Pterm("\"Source:");
	"\"Source: Regional Economic Information System, Bureau of Economic Analysis, U.S. Department of Commerce\"";
        Eor_t eor;
};
