/* Is skip a good idea?
   Skip is like omit in unions and structs, raising some of the same issues.
   Basic semantic question: does skip test come before or after termination checks?
   Interaction with Pended
    - ended reads speculatively.
    - if skip first, only do ended test if not skipped; skip must commit read
    - if ended first, skip should only be called if either !ended orelse (ended and consume)
      this semantics should match that for Plast.
   Interaction with maximum length
    - does skip come before or after length checks?
    - does maximum length mean maximum on disk length, or maximum in-memory length?
      ** I think it should be the maximum length on disk
         Which would mean we need to have two different length vars: disk-length and mem-length
         Disk length would have to be incremented on every read (modulo ended ^ !consume)
   Interaction with parse descriptors
   - if we skip a cell, then we have to skip it in the parse descriptor array as well,
     to keep them parallel.
*/


Parray seq_t{
  Pint32 [] : Psep('|') && Pomit(elt % 2 == 0 ) 
              && Pended(consume = (elts[current] == -1));
};

Precord Pstruct entry{
  seq_t seq;
};




