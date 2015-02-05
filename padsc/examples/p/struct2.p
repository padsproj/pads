Precord Pstruct test {
       Pa_uint32 id : id < 100000;     //- identity 
  '|'; Pa_uint32 ts : ts == 11 * id;   //- time stamp
  Pcompute Pa_uint32 nums = ts + id;
};


