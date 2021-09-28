#include "bolha.h"

void bolha(int *vet, int n){
  int i, j;

  for(int i=(n-1); i>0; i--){
    for(int j=0; j<i; j++){
      if(vet[j] > vet[j+1]){
        int aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
      }
    }
  }
}