#include <stdio.h>
#include <sys/time.h> 
#include <stdlib.h>





int main(){
    
    /* exemplos de tamanhos das matrizes a serem geradas */ 
    int tamanhos[] = {32, 64, 128, 256, 512, 640, 768, 896, 1024, 1536};
    int n, i, j, par;
    int **a;
    
    struct timeval tv;
    double start_t, end_t, tempo_gasto;
    
    /* aloca espaco para a matriz a */
    /* MAX eh inicializado com um dos tamanhos do vetor acima */
    
    int **a =   calloc(MAX, sizeof(int* ));
    for(i=0; i< MAX; i++)
        a[i] = calloc(MAX, sizeof(int *));
    
    /* inicializa a matriz */
    
   
    /* exemplo de como calcular o tempo de execução somente do trecho
     * especifico que faz a operacao com as matrizes 
     */
    printf("===========  Iniciando execucao ============\n");            
    gettimeofday(&tv, NULL);
    start_t = (double) tv.tv_sec + (double)tv.tv_usec / 1000000.0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if ( a[i][j] % 2 == 0)
                par += 1;
            gettimeofday(&tv,NULL); 
        end_t = (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
    tempo_gasto = end_t - start_t;
    printf(" %d pares, tempo %f usecs\n", par,tempo_gasto);
    
}
