Popt Pchar foo_t : Psome b => {b == 'a'};

Parray bar {
  foo_t[];
};

Precord Pstruct entry {
  bar b;
  'x';
};

Psource Parray source {
  entry[];
};
		      