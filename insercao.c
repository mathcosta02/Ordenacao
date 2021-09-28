#include "insercao.h"

void insercao(int *vet, int n){
  for (int i = 1; i < n; i++) {
    int tmp = vet[i];
    int j = i - 1;

    while ((j >= 0) && (vet[j] > tmp)) {
      vet[j + 1] = vet[j];
      j--;
    }
    
    vet[j+1] = tmp;
  }
}