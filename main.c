#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#include "bolha.h"
#include "selecao.h"
#include "insercao.h"
#include "shellsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "countingsort.h"
#include "geracao.h"

struct rusage usage;

void teste(int n, char ordem){
  //Declaração dinamica de um vetor
  int *vet = (int*)malloc(n*sizeof(int));

  //Calcular o tempo
  clock_t inicio, fim;
  double total;

  //Geração do conjunto a ser ordenado
  switch(ordem){
    case 'C': crescente(vet, n);
    break;
    case 'D': decrescente(vet, n);
    break;
    case 'A': aleatorio(vet, n);
    break;
    default: aleatorio(vet, n);
  }

  //Mostrar o conjunto a ser ordenado
  //mostrar(vet, n);

  //Execução dos algoritmos de ordenação
  inicio = clock();
  //bolha(vet, n);
  //selecao(vet, n);
  //insercao(vet, n);
  //shellsort(vet, n);
  //mergesort(vet, n);
  quicksort(vet, n);
  //heapsort(vet, n);
  //countingsort(vet, n);
  fim = clock();
  total = ((fim - inicio) / (double)CLOCKS_PER_SEC);

  getrusage(RUSAGE_SELF, &usage);

  printf("N: %d - Tempo: %f segundos - Memoria: %0.2f KB - Ordem: %c.\n",n, total, usage.ru_maxrss/1024.0, ordem);
  //Mostrar o conjunto ordenado
  //mostrar(vet, n);

  //Desalocar o espaço de memória do vet
  free(vet);
}

int main(int argc, char **argv) {

  for(int i=1000000; i<=64000000; i=i*2){
    teste(i, 'C');
    teste(i, 'D');
    teste(i, 'A');
    printf("\n");
  }
  return 0;
}