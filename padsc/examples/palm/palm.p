const Puint32 expected = 'T' + ('D' << 8) + (2 << 16) + (0 << 24);

Pstruct  versionTag_t{
  Pchar c1 : c1 == '0';
  Pchar c2 : c2 == '0';
  Pchar c3 : c3 == 'R';
  Pchar c4 : c4 == 'V';
  Pendian Pb_uint32 tag : tag == expected;
};

Pstruct smallCString_t{
  Pchar size : size < 255;
  Pstring_FW(:size:) chars;
};

Pstruct largeCString_t{
  Pchar isLarge : isLarge == 0xFF;
  Pb_uint16 size;
  Pstring_FW(:size:) chars;
};

Punion cString_t{
  largeCString_t lstr;
  smallCString_t sstr;
  
}

Pstruct categoryEntry_t{
  Pb_uint32        index;
  Pb_uint32        id;
  Pb_uint32        dirtyFlag;
  cString_t      longName;
  cString_t      shortName;
}

Pstruct todoEntry_t{
  Pb_uint32     ft1 : ft1 = 1;
  Pb_uint32     recordID;

  Pb_uint32     ft2 : ft2 = 1;
  Pb_uint32     status;

  Pb_uint32     ft3 : ft3 = 1;
  Pb_uint32     position;

  Pb_uint32     ft4 : ft4 = 5;
  Pb_uint32     padding4 : padding4 == 0;
  cString_t   description;

  Pb_uint32     ft5 : ft5 = 3;
  Pb_uint32     dueDate;

  Pb_uint32     ft6 : ft6 = 6;
  Pb_uint32     completed;
  
  Pb_uint32     ft7 : ft7 = 1;
  Pb_uint32     priority;

  Pb_uint32     ft8 : ft8 = 6;
  Pb_uint32     private;

  Pb_uint32     ft9 : ft9 = 1;
  Pb_uint32     category;

  Pb_uint32     ft10 : ft10 = 5;
  Pb_uint32     padding10 : padding10 == 0;
  cString_t   noteText;
}

Psource Pstruct toDo_t{
  Pb_uint32        unknown;
  cString_t      creator;
  versionTag_t   versionTag;
  Pstring_FW(:24:) unknownToo;
  cString_t      fileName;
  cString_t      tableString;
  Pb_uint32        nextFree;
  Pb_uint32        categoryCount;
  categoryEntry_t  [categoryCount] categoryEntries;
  Pb_uint32        resourceID;
  Pb_uint32        fieldsPerRow; // : fieldsPerRow == 10;
  Pb_uint32        recIDPos;
  Pb_uint32        recStatusPos;
  Pb_uint32        placementPos;
  Pb_uint16        fieldCount;
  Pb_uint16        [fieldCount] fieldEntries;
  Pb_uint32        numEntries;
  Pcompute Puint32 numRecords = numEntries / 10;
  todoEntry_t    [numRecords] toDoEntries;
};

// 8 cat.
