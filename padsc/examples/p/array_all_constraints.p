
Precord Parray list(:Puint32 min, Puint32 max:) {
  Pint32 [min : max] : Psep(':') && Pterm('|');
} Pwhere{
  Pforall (i Pin elts : elts[i] == list[i]);
};

