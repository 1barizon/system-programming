#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char
    *byte_pointer; // ponteiro para um objeto do tipo unsigned char*
                   // esse tipo recebe um endereco de memoria, entao ele aponta
                   // para o endereco de memoria que eu quiser

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++)
    printf(" %x", start[i]); // %.2x indica que o inteiro tem que ser printado
                             // start[i] -> aritimetica de ponteiro, o
                             // compilador transforma isso em : ponteiro[1]=
                             // inicio + (1* 4(no caso do int que tem 4 byts))
                             // em hexadecimal com pelo menos 2 digitos
  printf("\n");
}

void show_int(int x) { show_bytes((byte_pointer)&x, sizeof(int)); }

int main() {
  int a = 0x12345678;
  byte_pointer ap = (byte_pointer)&a;
  // Little endian podemos ver aqui que o codigo printa do byte menos
  // significativo para o byte mais significativo
  show_bytes(ap, 1);
  show_bytes(ap, 2);
  show_bytes(ap, 3);
  show_bytes(ap, 4);

  // Print em hex
  printf("\n");
  int b = 10;
  show_int(b);

  // representing strings
  const char *m = "abcdefghijklmnopqrstuvwxyz";
  show_bytes((byte_pointer)m, strlen(m));

  return 0;
}
