/*Scrivere la funzione C che riceve in ingresso un array di float A, un array di unsigned short int B, e la
loro dimensione N ed opera nel modo seguente:
• Alloca un array C e lo restituisce tra i parametri formali della funzione;
• I valori degli elementi di C sono ottenuti come prodotto tra il valore degli elementi di A e degli elementi
di B con stesso indice (i valori di B possono essere solo 0 od 1, in caso contrario la funzione termina).
La funzione deve anche restituire tra i parametri formali il numero di elementi di C che hanno valore calcolato >
di 0. Il valore restituito dalla funzione è TRUE nel caso di esecuzione corretta, FALSE altrimenti.
(Esempio: A={1,2,3,4,5}, B={0,1,0,1,1}, N=5 -> C={0,2,0,4,5}) */



#include<stdlib.h>
#include<stdio.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0
Boolean ArrayProduct1(int *A, unsigned short int *B, int **C, int N, int zerocount);
int main(void){
    int N;
    printf("inserisci N: ");
    scanf("%d", &N);
    int  A[N];
    for (int i = 0; i < N; ++i) {
        printf("inserisci valore di A: ");
        scanf("%d",&A[i]);
    }
    unsigned short int B[N];
    for (int i = 0; i < N; ++i) {
        printf("inserisci valore di B: ");
        scanf("%hd",&B[i]);
    }
    int *C;
    int zerocount=0;
    ArrayProduct1(A,B,&C,N,zerocount);
    printf("C=[");
    for (int i = 0; i < N; ++i) {
        printf("%d ",C[i]);
    }
    printf("]");
}
Boolean ArrayProduct1(int *A, unsigned short int *B, int **C, int N, int zerocount){
    if(N==0)
        return FALSE;
    *C=(int *)malloc(sizeof(int)*N);
    if(*C==NULL)
        return FALSE;
        for (int i = 0; i < N; ++i) {
            (*C)[i]=A[i]*B[i];
            if((*C)[i]>0)
                (zerocount+=1);
        }

    return TRUE;
}