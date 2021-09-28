#include <stdlib.h>
#include "heapsort.h"

void constroi(int *vet, int tamHeap){
  for(int i = tamHeap; i > 1 && vet[i] > vet[i/2]; i /= 2){
    int aux = vet[i];
    vet[i] = vet[i/2];
    vet[i/2] = aux;
  }
}

int getMaiorFilho(int *vet, int i, int tamHeap){
  int filho;
  if (2*i == tamHeap || vet[2*i] > vet[2*i+1]){
    filho = 2*i;
  } 
  else {
    filho = 2*i + 1;
  }
  return filho;
}

void reconstroi(int *vet, int tamHeap){
  int i = 1;
  while(i <= (tamHeap/2)){
    int filho = getMaiorFilho(vet, i, tamHeap);
    if(vet[i] < vet[filho]){
      int aux = vet[i];
      vet[i] = vet[filho];
      vet[filho] = aux;

      i = filho;
    }
    else{
      i = tamHeap;
    }
  }
}

void heapsort(int *vet, int n) {
  //Alterar o vetor ignorando a posicao zero
  int *arrayTmp = (int*)malloc((n+1)*sizeof(int));
  for(int i = 0; i < n; i++){
    arrayTmp[i+1] = vet[i];
  }

  //Contrucao do heap
  for(int tamHeap = 2; tamHeap <= n; tamHeap++){
    constroi(arrayTmp, tamHeap);
  }

  //Ordenacao propriamente dita
  int tamHeap = n;
  while(tamHeap > 1){
    int aux = arrayTmp[1];
    arrayTmp[1] = arrayTmp[tamHeap--];
    arrayTmp[tamHeap--] = aux;

    reconstroi(arrayTmp, tamHeap);
  }

  //Alterar o vetor para voltar a posicao zero
  for(int i = 0; i < n; i++){
    vet[i] = arrayTmp[i+1];
  }
  free(arrayTmp);
}