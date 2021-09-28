#include "quicksort.h"

void quicksortRec(int *vet, int esq, int dir) {
  int i = esq, j = dir;
  int pivo = vet[(dir+esq)/2];
  while (i <= j) {
    while (vet[i] < pivo) i++;
    while (vet[j] > pivo) j--;
    if (i <= j) {
      int aux = vet[i];
      vet[i] = vet[j];
      vet[j] = aux;
      i++;
      j--;
    }
  }
  if (j > esq)  quicksortRec(vet, esq, j);
  if (i < dir)  quicksortRec(vet, i, dir);
}

void quicksort(int *vet, int n) {
  quicksortRec(vet, 0, n-1);
}