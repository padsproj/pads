Punion branches(:Pa_uint32 a:){
  Pswitch (a) {
  Pcase 1 : Pa_int32               number : number % 2 == 0;
  Pcase 2 : Pa_string_SE(:"/$/":)  name;
  Pdefault: Pa_uint32              def : def % 2 == 1; 
  }
} 

Precord Pstruct choice{
  Pa_uint32      a; 
  branches(:a:)  b; 
}
