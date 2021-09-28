#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "geracao.h"

// Preencher um vetor com elementos em ordem crescente
void crescente(int *vet, int n) {
  for (int i = 0; i < n; i++) {
    vet[i] = i;
  }
}

// Preencher um vetor com elementos em ordem decrescente
void decrescente(int *vet, int n) {
  int i=0, x=n-1;

  while(n>i){
    vet[i] = x;
    i++;
    x--;
  }
}

// Preencher um vetor com elementos em ordem aleatória
void aleatorio(int *vet, int n) {
  crescente(vet, n);
  srand(time(NULL));
  
  for (int i = 0; i < n; i++) {
    int aux = vet[i];
    vet[i] = vet[rand() % n];
    vet[rand() % n] = aux;
  }
}

// Preencher para mostrar um vetor
void mostrar(int *vet, int n) {

  printf("[ ");
  for (int i = 0; i < n; i++) {
    printf("%d ", vet[i]);
  }
  printf("]\n");
}