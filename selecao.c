#include "selecao.h"

void selecao(int *vet, int n){
  for (int i = 0; i < (n - 1); i++) {
    int menor = i;
    for (int j = (i + 1); j < n; j++){
      if (vet[menor] > vet[j]){
        menor = j;
      }
    }
    int aux = vet[menor];
    vet[menor] = vet[i];
    vet[i] = aux;
  }
}