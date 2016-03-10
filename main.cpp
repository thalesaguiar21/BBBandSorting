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


//Arrays used by the sorting methods
int *vetorQuickSort;
int *vetorBubbleSort;
int *vetorSelectionSort;
int tamanho;

//Compare function used by qsort to compare two elements
int compare_ints( const void* a, const void* b ) {
     int* arg1 = (int*) a;
     int* arg2 = (int*) b;
     if( *arg1 < *arg2 ) return -1;
     else if( *arg1 == *arg2 ) return 0;
     else return 1;
}

//bubble sort algorithm
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

//Observe that the numbers are randomly generated based
//on a seed. If its used the same seed,
//the random numbers will be the same
void criarVetor(int tamanhoVetor, int semente){
	if(vetorQuickSort != NULL)
		delete[] vetorQuickSort;
	if(vetorSelectionSort != NULL)
		delete[] vetorSelectionSort;
	if(vetorBubbleSort != NULL)
		delete[] vetorBubbleSort;
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

  //array size
  long int n = 0;
	while(n <= 300000){
	if(n == 500000){
		return 0;
	}
	if(n < 100000){
		n += 5000;
	}
	else if(n < 100000){
		n += 50000;
	}
	else{
		n = 500000;
	}
  //Create array with random elements [0, n]
	for(int i = 1; i <= 10; i++){
  criarVetor(n,i);

	gettimeofday(&t0, NULL);

  //Sort using quickSort
  //qsort (vetorQuickSort, n, sizeof(int), compare_ints);
  
  //Sort using selectionSort
  selectionSort(vetorSelectionSort, n);

  //Sort using bubleSort
  //bubbleSort(vetorBubbleSort,n);
	gettimeofday(&t1, NULL);
	t1.tv_sec -= t0.tv_sec;
	t1.tv_usec -= t0.tv_usec;
	if(t1.tv_usec < 0){
		t1.tv_usec += 1000000;
		t1.tv_sec -= 1;
	}
	cout << n << ' ' << (int)t1.tv_sec << '.' << setw(6) << setfill('0') << (int)t1.tv_usec << endl;
	}
	}
	/*
	use the following code to check the time with the clock:
	clock_t t0, t1;
	t0 = clock();
  
	**sorting algorithm**
  
	t1 = clock();
	cout << n << ' ' << (((float)(t1 - t0)) / CLOCKS_PER_SEC) << endl;
	*/
  return 0;
}
