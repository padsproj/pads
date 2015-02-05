#include <stdio.h>
#include <ctype.h>

int printtodo(int c){
  do{
    putchar(c);
  }while(isprint(c = getchar()));
  putchar('\n');
  fflush(stdout);	
  return c;
}

int main(){
  int c = getchar();
  while(c != EOF){
    if (isprint(c))
      c = printtodo(c);
    else{
      printf("%d ",c);
      c = getchar();
    }
  }

  return 0;
}
