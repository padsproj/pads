Pstruct test {
  Puint32 id : id < 100000;     /- identity 
  '|';
  Puint32 ts : ts == 11 * id;   /- time stamp
  '\n';
};

#define RECLIST_SIZE 10
Parray recList {
  test [RECLIST_SIZE];
} Pwhere {
  Pforall( i Pin [0..length-2] : elts[i].id < elts[i+1].id );
};


Pstruct testtwo{
  Puint32 id : id < 100000;     /- identity
  '|';
  Puint32 ts : ts == 11 * id;  /- time stamp
};


Parray recListtwo{
  testtwo [] : Psep('\n');
};


#define MIN 2
#define MAX 5
Parray intList {
  Puint32 [MIN : MAX] : Psep('|') && Pterm('\n');
} Pwhere {
  Pforall( i Pin [0 .. length -2] : elts[i] < elts[i+1]);
};

Pstruct entry{
  intList i;
  '\n';
}


