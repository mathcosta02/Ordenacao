#include "shellsort.h"

void insercaoPorCor(int *vet, int n, int cor, int h){
  for (int i = (h + cor); i < n; i+=h) {
    int tmp = vet[i];
    int j = i - h;
    while ((j >= 0) && (vet[j] > tmp)) {
      vet[j + h] = vet[j];
      j-=h;
    }
    vet[j + h] = tmp;
    }
}

void shellsort(int *vet, int n) {
  int h = 1;

  do { 
    h = (h * 3) + 1; 
  } while (h < n);

  do {
    h /= 3;
    for(int cor = 0; cor < h; cor++){
       insercaoPorCor(vet, n, cor, h);
    }
  } while (h != 1);
}