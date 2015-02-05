#define LIST_SIZE 10
Precord Parray intList {
  Pint32 [LIST_SIZE] : Psep('|');
} Pwhere {
  Pforall (i Pin elts : elts[i] == intList[i]);
};
