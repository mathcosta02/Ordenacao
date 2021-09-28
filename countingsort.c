#include <stdlib.h>
#include "countingsort.h"

int getMaior(int *vet, int n) {
  int maior = vet[0];

  for (int i = 0; i < n; i++) {
    if(maior < vet[i]){
      maior = vet[i];
    }
  }
  return maior;
}

void countingsort(int *vet, int n) {
  //Array para contar o numero de ocorrencias de cada elemento
  int tamCount = getMaior(vet, n) + 1;
  int *count = (int*)malloc(tamCount*sizeof(int));
  int *ordenado = (int*)malloc(n*sizeof(int));

  //Inicializar cada posicao do array de contagem 
  for (int i = 0; i < tamCount; count[i] = 0, i++);

  //Agora, o count[i] contem o numero de elemento iguais a i
  for (int i = 0; i < n; count[vet[i]]++, i++);

  //Agora, o count[i] contem o numero de elemento menores ou iguais a i
  for(int i = 1; i < tamCount; count[i] += count[i-1], i++);

  //Ordenando
  for(int i = n-1; i >= 0; ordenado[count[vet[i]]-1] = vet[i], count[vet[i]]--, i--);

  //Copiando para o array original
  for(int i = 0; i < n; vet[i] = ordenado[i], i++);

  free(count);
  free(ordenado);
}