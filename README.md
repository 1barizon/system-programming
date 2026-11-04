# Plano de Imersão em Systems Programming (CS:APP)


## Cronograma Diário: Teoria + Prática Intensa em C

### **Dia 1: A Representação de Dados e Bits**
* **Foco Teórico (CS:APP Capítulo 2):** Integers, complemento de dois, representação em ponto flutuante e limites de tamanho de tipos em arquiteturas de $32/64$ bits.
* **Tarefa Prática:** Escrever um programa em C chamado `bit_manipulator.c` que funcione como uma ferramenta de linha de comando para inspecionar a representação binária de qualquer tipo de dado (`int`, `float`, `double`). 
* **O que codar:** Implemente funções usando operações bitwise (`&`, `|`, `^`, `<<`, `>>`) para:
  1. Imprimir a representação binária de um byte/inteiro.
  2. Extrair e inspecionar os campos de sinal, expoente e mantissa de um `float` (seguindo o padrão IEEE 754).
  3. Implementar uma função que verifica se um número é potência de 2 **sem usar loops ou divisões** (apenas bitwise).

### **Dia 2: O Compilador por Dentro (Assembly e o Processo de Tradução)**
* **Foco Teórico (CS:APP Capítulo 3):** Como o GCC traduz C para Assembly x86-64, registradores (`%rax`, `%rsp`, etc.), pilha de chamadas (*call stack*) e convenções de chamada (*calling conventions*).
* **Tarefa Prática:** Escrever um pequeno programa em C com funções matemáticas e de alocação local. Use o comando `gcc -S` para gerar o arquivo assembly correspondente e analise-o.
* **O que codar:** Escreva uma função recursiva (ex: cálculo de Fibonacci ou Fatorial) em C. Em seguida, reescreva **diretamente em Assembly x86-64 inline** dentro de um arquivo C (`__asm__`) e faça o programa principal chamá-la, gerenciando manualmente os registradores e a pilha.

### **Dia 3: O Gerenciamento de Memória do Processo (Alocação Dinâmica)**
* **Foco Teórico (CS:APP Capítulo 9 - Parte 1):** O layout de memória de um processo (`Text`, `Data`, `BSS`, `Heap`, `Stack`), o comando `brk`/`sbrk` e o funcionamento básico de um alocador.
* **Tarefa Prática:** Implementar do zero o seu próprio alocador de memória heap minimalista (estilo `malloc` e `free` simplificados).
* **O que codar:** Crie um programa que gerencia um grande bloco de memória pré-alocado (ou obtido via `sbrk`/`mmap`) e implemente uma estratégia de lista encadeada simples (*First-Fit* ou *Best-Fit*) para alocar e liberar pedaços de memória sob demanda, prevenindo vazamentos básicos.

### **Dia 4: Arquivos e I/O de Baixo Nível (System Calls vs Standard I/O)**
* **Foco Teórico (CS:APP Capítulo 10):** Descritores de arquivo, chamadas de sistema de I/O (`open`, `read`, `write`, `close`, `lseek`) e a diferença para o buffer do `stdio.h` (`fopen`, `fread`).
* **Tarefa Prática:** Escrever o seu próprio clone do utilitário Unix `cat` ou `hexdump`.
* **O que codar:** Desenvolva um programa que lê um arquivo binário e imprime seu conteúdo formatado em formato hexadecimal e ASCII lado a lado (estilo `hexdump -C`). O programa deve usar **apenas** as system calls de baixo nível (`open`, `read`, `write`) operando sobre um buffer de tamanho fixo em memória.

### **Dia 5: Concorrência I/O e Redirecionamento (Multiplexação)**
* **Foco Teórico (CS:APP Capítulo 10 & 11):** Compartilhamento de arquivos, redirecionamento de entrada/saída (`dup2`) e multiplexação de I/O.
* **Tarefa Prática:** Criar um interpretador de comandos básico (*mini-shell*) capaz de lidar com redirecionamento de arquivos (`<` e `>`).
* **O que codar:** Um programa que lê um comando do usuário, faz o *parsing* dos argumentos, utiliza `fork()` e `execvp()` para rodá-lo, mas intercepta os operadores `>` ou `<` na linha de comando para redirecionar os descritores de arquivo padrão (`stdin`/`stdout`) usando `dup2` antes de executar o processo filho.

### **Dia 6: O Modelo de Processos do Sistema Operacional**
* **Foco Teórico (CS:APP Capítulo 8):** Processos, exceções, controle de fluxo, `fork()`, `waitpid()`, espaço de endereçamento virtual e a árvore de processos.
* **Tarefa Prática:** Construir um **Gerenciador de Tarefas / Monitor de Processos** minimalista em C (um mini `ps` ou `top` primitivo).
* **O que codar:** Faça seu programa ler o sistema de arquivos virtual do Linux (`/proc`) para listar todos os PID, nomes de processos ativos, uso de memória e estado atual, exibindo-os formatados no terminal em tempo real com atualização periódica (`sleep`).

### **Dia 7: Sinais e Comunicação Interprocessos (IPC)**
* **Foco Teórico (CS:APP Capítulo 8 - Conclusão):** Sinais Unix (`SIGINT`, `SIGKILL`, `SIGSEGV`, `SIGALRM`), tratamento de sinais (`sigaction`), condições de corrida e concorrência básica.
* **Tarefa Prática:** Implementar um programa robusto de tratamento de sinais que implemente um "Timeout" para tarefas travadas.
* **O que codar:** Escreva um programa que executa uma tarefa demorada (ou simula um loop infinito). Use `alarm()` e `sigaction()` para capturar o sinal `SIGALRM` e interromper a operação de forma limpa caso ela ultrapasse um limite de tempo configurado, liberando recursos antes de fechar.

### **Dia 8: Gerenciamento de Memória Virtual e Mapeamento (`mmap`)**
* **Foco Teórico (CS:APP Capítulo 9 - Parte 2):** Paginação, falhas de página (*page faults*), tabela de páginas e a chamada de sistema `mmap`.
* **Tarefa Prática:** Escrever um programa que processe um arquivo gigante (maior que a memória RAM disponível) de forma eficiente usando mapeamento de memória.
* **O que codar:** Crie um programa que abre um arquivo de texto de grande porte usando `mmap()`. O programa deve buscar e substituir uma string específica diretamente na memória mapeada (modificando o arquivo no disco sem precisar ler ele inteiro para o heap com `malloc`).

### **Dia 9: A Camada de Rede — Sockets TCP/IP (O Começo)**
* **Foco Teórico (CS:APP Capítulo 11):** Arquitetura cliente-servidor, sockets de internet, endereços IP, portas, conversão de endianness (`htons`, `ntohl`) e a API de sockets BSD.
* **Tarefa Prática:** Escrever um servidor TCP eco (*Echo Server*) concorrente básico do zero em C.
* **O que codar:** Implemente um servidor que abre um socket TCP em uma porta local (`socket`, `bind`, `listen`, `accept`), aguarda conexões de clientes (você pode testar usando o comando `nc` ou `telnet`), lê os dados enviados pelo cliente e os devolve exatamente iguais (eco).

### **Dia 10: Concorrência Avançada — Threads POSIX (pthreads)**
* **Foco Teórico (CS:APP Capítulo 12 - Parte 1):** O modelo baseado em threads, criação de threads, compartilhamento de variáveis globais e o problema das condições de corrida (*race conditions*).
* **Tarefa Prática:** Implementar um somador/processador paralelo multi-threaded para processar arquivos em blocos.
* **O que codar:** Crie um programa que lê um grande vetor de números inteiros e utiliza `pthread_create` para dividir o trabalho pesado entre 4 ou 8 threads simultâneas. Implemente uma soma concorrente sem controle de concorrência primeiro para observar a corrupção de dados (race condition).

### **Dia 11: Sincronização de Threads (Mutexes e Semáforos)**
* **Foco Teórico (CS:APP Capítulo 12 - Parte 2):** Mutexes, semáforos, deadlock, exclusão mútua e o problema clássico de Produtor-Consumidor.
* **Tarefa Prática:** Corrigir o programa do Dia 10 e implementar um pool de threads produtor-consumidor clássico.
* **O que codar:** Reescreva a rotina paralela utilizando `pthread_mutex_t` para proteger as seções críticas. Em seguida, crie uma fila circular protegida por semáforos (`sem_t`) onde uma thread produtora insere tarefas e múltiplas threads consumidoras as processam concorrentemente.

### **Dia 12: Projeto Integrador Final — Um Web Server Concorrente**
* **Foco Teórico (CS:APP Revisão Geral):** Consolidar redes (Cap 11), concorrência (Cap 12), I/O (Cap 10) e tratamento de erros robusto.
* **Tarefa Prática:** Construir um **Servidor HTTP estático multithreaded** funcional do zero em C.
* **O que codar:** Um servidor web simples que aceita requisições HTTP GET, analisa o caminho do arquivo solicitado (ex: `/index.html`), lê o arquivo do disco usando I/O de baixo nível e o envia de volta ao navegador do usuário com os cabeçalhos HTTP corretos (`HTTP/1.1 200 OK`), utilizando o seu próprio pool de threads construído no Dia 11 para atender múltiplos navegadores simultaneamente.

---

## Dicas para Aproveitar ao Máximo

1. **Sem atalhos de IA no código:** Como você quer aprender a programar de verdade a fundo, use o seu ambiente terminal (Neovim/VS Code) e consulte estritamente os manuais do Linux (`man open`, `man mmap`, `man pthreads`) em vez de pedir códigos prontos.
2. **Compile com flags rigorosas:** Sempre compile seus códigos de teste ativando todos os avisos do compilador para pegar bugs de ponteiros e vazamentos logo cedo:
   ```bash
   gcc -Wall -Wextra -Werror -pedantic -std=gnu99 -pthread seu_programa.c -o seu_programa
   ```
3. **Use ferramentas de diagnóstico:** Incorpore o `valgrind` (`valgrind --leak-check=full ./seu_programa`) em todas as tarefas que envolvem alocação de memória ou sockets para garantir que você não tem nenhum *memory leak* ou *buffer overflow*.
