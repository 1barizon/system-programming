#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char
    *byte_pointer; // ponteiro para um objeto do tipo unsigned char*
                   // esse tipo recebe um endereco de memoria, entao ele aponta
                   // para o endereco de memoria que eu quiser
                   // o char ocupa 1 byte

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++)
    printf(" %x", start[i]); // %.2x indica que o inteiro tem que ser printado
                             // start[i] -> aritimetica de ponteiro, o
                             // compilador transforma isso em : ponteiro[1]=
                             // inicio + (i * 1)) , navegando de byte em byte pois o tipo char do ponteiro faz pensar que estamos analisando uma coisa de 1 byte
                            // em hexadecimal com pelo menos 2 digitos
  printf("\n");
}

void show_int(int x) { show_bytes((byte_pointer)&x, sizeof(int)); }


int bis(int x, int m){ // bit set, colocar o bit para 1 aonde o m tb e 1 
  return x | m;
}
int bic(int x, int m){ // bit clear, colocar 0 aonde no m e 1
  return x & ~m;
}

int bool_or(int x, int y){
  return bis(x,y);
}

int bool_xor(int x, int y){
  return bis(bic(x,y), bic(y,x));
}


int main() {
  //int a = 0x12345678;
  //byte_pointer ap = (byte_pointer)&a;
  // Little endian podemos ver aqui que o codigo printa do byte menos
  // significativo para o byte mais significativo
  //show_bytes(ap, 1);

  // Print em hex
  printf("\n");
  //int b = 10;
  //show_int(b);

  // representing strings
  const char *m = "a";
  int x = 0x87654321;
  int mask = 0xff;
  int r = x & mask;
  int r1 = x ^ ~mask; 
  


  show_bytes((byte_pointer) &r, sizeof(int));
  show_bytes((byte_pointer) &r1, sizeof(int));


  return 0;
}
