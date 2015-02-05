#define INTLIST_SIZE 4

Precord Parray intList {
  Puint32 [INTLIST_SIZE] : Psep('|');
} Pwhere {
  Pforall (i Pin [0..length-2] : (elts[i] < elts[i+1]))  && 
  Pparsecheck(end.offset - begin.offset > 10)        &&
  Pforall (i Pin [0..length-1] : (elts[i] % 2 == 0))        && 
    length > 0 ? elts[0] > 2 : 1;
};


