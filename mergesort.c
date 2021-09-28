#include <stdlib.h>
#include "mergesort.h"

void intercalar(int *vet, int esq, int meio, int dir){
  int n1, n2, i, j, k;

  //Definir tamanho dos dois subarrays
  n1 = meio-esq+1;
  n2 = dir - meio;

  int *a1 = (int*) malloc((n1+1) * sizeof(int)); 
  int *a2 = (int*) malloc((n2+1) * sizeof(int));

  //Inicializar primeiro subarray
  for(i = 0; i < n1; i++){
    a1[i] = vet[esq+i];
  }

  //Inicializar segundo subarray
  for(j = 0; j < n2; j++){
    a2[j] = vet[meio+j+1];
  }

  //Sentinela no final dos dois arrays
  a1[i] = a2[j] = 0x7FFFFFFF;

  //Intercalacao propriamente dita
  for(i = j = 0, k = esq; k <= dir; k++){
    vet[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
  }

  free(a1);
  free(a2);
}

void mergesortRec(int *vet, int esq, int dir){
  if (esq < dir){
    int meio = (esq + dir) / 2;
    mergesortRec(vet, esq, meio);
    mergesortRec(vet, meio + 1, dir);
    intercalar(vet, esq, meio, dir);
  }
}

void mergesort(int *vet, int n) {
  mergesortRec(vet, 0, n-1);
}