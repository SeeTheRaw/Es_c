/*Scrivere la funzione C che riceve in ingresso un array di valori interi V e la sua dimensione N, ed opera nel modo
seguente:
• Alloca e calcola un nuovo array di valori float W i cui elementi sono dati dal rapporto tra due elementi
consecutivi di V. L’ultimo elemento di V è diviso per il primo;
• Ritorna FALSE nel caso sia presente una divisione per 0, TRUE altrimenti;
• Restituisce tra i parametri formali l’array W.
(Esempio: V= {4, 2, 2, 4, 6, 1}, N = 6 --> W = {4/2, 2/2, 2/4, 4/6, 6/1, 1/4} = {2, 1.0, 0.5, 0.6666666, 6.0, 0.25})*/

#include<stdlib.h>
#include<stdio.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0
Boolean ArrayDivFloat2(int *V, int N, float *W);
int main(void){
    int V[6]={4,2,2,4,6,1};
    int N=6;
    float *W;
    W=(float *) malloc(sizeof (float)*N);
    printf("N=%d \n", N);
    printf("V=[");
    for (int i = 0; i < N; ++i) {
        printf("%d ", V[i]);
    }
    printf("]");
    ArrayDivFloat2(V,N,W);
    printf("\n");
    printf("W=[");
    for (int i = 0; i < N; ++i) {
        printf("%f ", W[i]);
    }
    printf("]");
    return 0;
}

Boolean ArrayDivFloat2(int *V, int N, float *W){
    int primo=0;
    int secondo=1;
    int i=0;
    while(i<N && primo<5){
        W[i] = (float)V[primo]/V[secondo];
        i++;
        primo++;
        secondo++;
        }
    W[5]=(float)V[primo]/V[0];
    }

    //Made by Lorenzo ChadSittaro