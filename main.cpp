/*
 * Universidade Federal do Rio Grande do Norte
 * Instituto Metropole Digital
 *
 * copyright: Ivanovitch Silva
 * e-mail: ivan@imd.ufrn.br
 *
 * Tópico: manipulação de tempo em c++
 * Programa: calcular o tempo de execução dos algoritmos
 */

#include <cstdlib>
#include  <time.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sys/time.h>
using namespace std;


//Vetores usados pelos metodos de ordenacao
int *vetorQuickSort;
int *vetorBubbleSort;
int *vetorSelectionSort;
int tamanho;

//Funcao usada pelo qsort para comparar dois numeros
int compare_ints( const void* a, const void* b ) {
     int* arg1 = (int*) a;
     int* arg2 = (int*) b;
     if( *arg1 < *arg2 ) return -1;
     else if( *arg1 == *arg2 ) return 0;
     else return 1;
}

//Algoritmos de ordenacao bubble sort
void bubbleSort(int *vetor, int tamanho) {
  int aux;
  for (int i = 0; i < tamanho-1; i++) {
     for (int j = 0; j < tamanho-1; j++) {
        if (vetor[j] > vetor[j+1]) {
          aux = vetor[j];
      vetor[j] = vetor[j+1];
      vetor[j+1] = aux;
        }
     }
  }
}

void selectionSort(int *vetor, int tamanho){
	int aux, min;
	for(int i = 0; i < tamanho; i++){
		min = i;
		for(int j = i + 1; j < tamanho; j++){
			if(vetor[min] > vetor[j]){
				min = j;
			}
		}
		aux = vetor[min];
		vetor[min] = vetor[i];
		vetor[i] = aux;
	}
}

//Observe que os numeros sao gerados aleatorios baseados
//em uma semente. Se for passado a mesma semente, os
//numeros aleatarios serao os mesmos
void criarVetor(int tamanhoVetor, int semente){
  srand (semente);
  vetorQuickSort = new int[tamanhoVetor];
  vetorBubbleSort = new int[tamanhoVetor];
  vetorSelectionSort = new int[tamanhoVetor];
  for (int i=0;i<tamanhoVetor;i++){
    vetorQuickSort[i] =  rand()%100000;
    vetorBubbleSort[i] = rand()%100000;
    vetorSelectionSort[i] = rand()%100000;
  }
}


int main(int argc, char *argv[])
{
	struct timeval t0, t1;

  //Tamanho do vetor
  long int n = 0;
	while(n <= 300000){
	if(n==20000)
		return 0;
	if(n < 100000){
		n += 5000;
	}
	else if(n < 100000){
		n += 50000;
	}
	/*else{
		n = 500000;
	}*/
  //Criar vetor com elementos aleatorios[0,100000]
  for(int i = 1; i <= 10; i++){
  criarVetor(n,i);

	gettimeofday(&t0, NULL);

  //Ordenar utilizando quickSort
  //qsort (vetorQuickSort, n, sizeof(int), compare_ints);
  
  selectionSort(vetorSelectionSort, n);

  //Ordenar utilizando bubleSort
  //bubbleSort(vetorBubbleSort,n);
	gettimeofday(&t1, NULL);
	t1.tv_sec -= t0.tv_sec;
	t1.tv_usec -= t0.tv_usec;
	if(t1.tv_usec < 0){
		t1.tv_usec += 1000000;
		t1.tv_sec -= 1;
	}
	cout << n << ' ' << (int)t1.tv_sec << '.' << setw(6) << setfill('0') << (int)t1.tv_usec << endl;
	
	/*
	Pro clock é só usar:
  clock_t t0, t1;
  t0 = clock();
  
  algoritmo de ordenação
  
  t1 = clock();
  printf("%f\n",((float)(t1 - t0)) / CLOCKS_PER_SEC);
	*/
  return 0;
}
