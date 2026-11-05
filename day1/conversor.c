#include <stdio.h>
#include <stdlib.h>




typedef unsigned char *byte_pointer; // ponteiro para um objeto do tipo unsigned char*

void show_bytes(byte_pointer start, size_t len){
  int i ;
  for(i = 0; i< len; i++)
    printf(" %d", start[i]); // %.2x indica que o inteiro tem que ser printado em hexadecimal com pelo menos 2 digitos
  printf("\n");

}


void show_int(int x){
  show_bytes((byte_pointer) &x, sizeof(int));
}



int main(){
  int x ;
  scanf("%d", &x);

  show_int(x);
  
  return 0;
}
