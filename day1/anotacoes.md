# Repesenting and Manipulating Information

os tipos: (int64_t/ uint64_t) e (int32_t/uint32_t) possuem tamanhos fixos independentes de qual maquina esteja sendo compilada, possuindo respectivamente sempre 4 e 8 bytes

# Addressing and Byte Ordering

- Na maquina virtual, um objeto multi-byte e armazenado como uma sequencia continua de bytes, com o endereco do objeto sendo o menor endereco dos bytes usados

exemplo:
type (int x) tem endereco 0x100, assumindo uma representacao de 32-bit, 4 bytes de x vao ser armazenados em 0x101, 0x102, 0x103.

- cada byte tem 8 bits que o valor maximo e 255 = (11111111)_2

## Little endian

- Uma convencao de que o byte menos significante vem primeiro: ou seja a ordem de armazenamento da informacao e ordenada em que a memoria comeca o byte menos significativo
  Considere um w-bit inteiro: [x_(w-1), x_(w-2), ..., x_1, x_0], x_(w-1) e o bit mais significativo e x_0 e o menos sigificativo, esse bits podem ser agrupados em bytes

**aritimetica de ponteiro:** permite navegar em forma de indice pela memoria alocada, entao dado um endereco inicial start = 0x100, no caso do int que possui 4 bytes, o compilado transforma start[1] = 0x100 + (1*4) e com isso acessamos o endereco de memoria posterior.

exemplo:

int x -> address 0x100
x -> 0x01234567 (em hex)

big endian: 0x100 -> (01), 0x101 -> (23), 0x102 -> (45), 0x103 -> (67)

little endian: 0x100 -> (67), 0x101 -> (45), 0x102 -> (23), 0x103 -> (01)

cada 0x100 -> tem 8 bits - cada valor em hex tem exatamente 4 bits, f = (1111), cada um fica com doi digitos do valor em hex para completar os 8 bits do byte

## Bit wise operation

- Operadores:
  and => &
  or => |
  xor => ^
  not => ~
