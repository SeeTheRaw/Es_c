/* Scrivere la funzione C che riceve in ingresso un array di valori interi V e la sua dimensione N (N>0), ed opera nel
modo seguente:
• Alloca un nuovo array di valori float W i cui valori sono ottenuti dividendo un valore preso dalla testa di
V con un elemento preso dalla coda di V (nel caso in cui N sia dispari il valore centrale di V è escluso dal
calcolo);
• La funzione ritorna FALSE nel caso sia presente una divisione per 0, TRUE altrimenti;
• Restituisce tra i parametri formali il vettore W.
(Esempio: V = {4, 2, 2, 3, 4, 6, 1}, N = 7 --> W = {4/1, 2/6, 2/4} = {4.0, 0.333333, 0.5}) */

#include<stdlib.h>
#include<stdio.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0
Boolean ArrayDivFloat(int *V, int N, float *W);
int main(void){
    int V[6]={4,2,2,3,4, 6};
    int N=6;
    float *W;
    W=(float *) malloc(sizeof (float)*N/2);
    printf("N=%d \n", N);
    printf("V=");
    for (int i = 0; i < N; ++i) {
        printf("%d,", V[i]);
    }
    ArrayDivFloat(V,N,W);
    printf("\n");
    printf("W=");
    for (int i = 0; i < 3; ++i) {
        printf("%f,", W[i]);
    }
return 0;
}

Boolean ArrayDivFloat(int *V, int N, float *W){
    int l=0;
    int r=N-1;
    for (int i = 0; i < N/2; ++i) {
        W[i] = (float)V[l++]/V[r--];
    }
}