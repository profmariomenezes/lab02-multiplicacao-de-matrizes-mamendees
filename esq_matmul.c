#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void popularMatriz(int **matriz, int tamanhoMatriz) {
  int i,j;
  
  for (i = 0; i < tamanhoMatriz; i++) {
    for (int j = 0; j < tamanhoMatriz; j++) {
      matriz[i][j] = rand() % 11;
    }
  }
}

void imprimirMatriz(int **matriz, int tamanhoMatriz) {
  int i, j;
  for (i = 0; i < tamanhoMatriz; i++) {
    for (int j = 0; j < tamanhoMatriz; j++) {
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void multiplicarMatrizSemOtimizarL1L2 (int **matrizA, int **matrizB, int **matrizResultante, int tamanhoMatriz){ 
  int i, j, k;
  
  for (i = 0; i < tamanhoMatriz; i++) 
    for (j = 0; j < tamanhoMatriz; j++) 
      for (k = 0; k < tamanhoMatriz; k++) 
        matrizResultante[i][j] += matrizA[i][k] * matrizB[k][j];
}

void multiplicarMatrizOtimizandoL1L2 (int **matrizA, int **matrizB, int **matrizResultante, int tamanhoMatriz){ 
  int i, j, k;
  
  for (i = 0; i < tamanhoMatriz; i++) 
    for (k = 0; k < tamanhoMatriz; k++) 
      for (j = 0; j < tamanhoMatriz; j++) 
        matrizResultante[i][j] += matrizA[i][k] * matrizB[k][j];
}

int main() {

  int i;
  struct timeval tv;
  double start_t, end_t, tempo_gasto;
  
  int ordemDaMatrizQuadrada = 1000;

  //Matriz A
  int **matrizA = calloc(ordemDaMatrizQuadrada, sizeof(int *));
  for(i = 0; i < ordemDaMatrizQuadrada; i++)
    matrizA[i] = calloc(ordemDaMatrizQuadrada, sizeof(int *));
    
  popularMatriz(matrizA, ordemDaMatrizQuadrada);
  //printf("Matriz A: \n");
  //imprimirMatriz(matrizA, ordemDaMatrizQuadrada);

  //Matriz B
  int **matrizB = calloc(ordemDaMatrizQuadrada, sizeof(int *));
  for(i = 0; i < ordemDaMatrizQuadrada; i++)
    matrizB[i] = calloc(ordemDaMatrizQuadrada, sizeof(int *));
    
  popularMatriz(matrizB, ordemDaMatrizQuadrada);
  //printf("Matriz B: \n");
  //imprimirMatriz(matrizB, ordemDaMatrizQuadrada);

  //Matriz Resultante
  int **matrizResultante = calloc(ordemDaMatrizQuadrada, sizeof(int *));
  for(i = 0; i < ordemDaMatrizQuadrada; i++)
    matrizResultante[i] = calloc(ordemDaMatrizQuadrada, sizeof(int *));

  printf("===========   Iniciando execucao  ============\n");     
  gettimeofday(&tv, NULL);
  start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;

  multiplicarMatrizOtimizandoL1L2 (matrizA, matrizB, matrizResultante, ordemDaMatrizQuadrada);

  gettimeofday(&tv,NULL); 
  end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
  tempo_gasto = end_t - start_t;
  
  //printf("Matriz Resultante: \n");
  //imprimirMatriz(matrizResultante, ordemDaMatrizQuadrada);
  
  printf("Tempo Gasto: %f Segundos.", tempo_gasto);
  printf("\n");
  printf("===========  Finalizando execucao ============\n"); 
  
  return 0;
}

//Sem Otimização -> gcc esq_matmul.c -std=gnu99 -O0 -o esq_matmul_saida
//Com Otimização -> gcc esq_matmul.c -std=gnu99 -O3 -o esq_matmul_saida

