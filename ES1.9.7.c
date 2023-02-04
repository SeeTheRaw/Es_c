/* si definisca la funzione c che riceve in ingresso due vettori di numeri interi A1 e A2, di lunghezza N1 e N2
 rispettivamente (N1>N2), e verifica se A2 è contenuto in A1*/

#include<stdlib.h>
#include<stdio.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean arrayComparison(int *A1, int *A2, int N1, int N2);

int main(void){
    int *A1, *A2, N1, N2;
    do {
        printf("\ninserisci dimensione A1: ");
        scanf("%d", &N1);
    } while (N1<=0);
    do {
        printf("\ninserisci dimensione A2: ");
        scanf("%d", &N2);
    }while(N2>N1);

    A1=(int *) malloc(sizeof(int)*N1);
    A2=(int *) malloc(sizeof(int)*N2);

    for (int i = 0; i < N1; ++i) {
        printf("\ninserisci un valore di A1: ");
        scanf("%d", &A1[i]);
    }
    for (int i = 0; i < N2; ++i) {
        printf("\ninserisci un valore di A2: ");
        scanf("%d", &A2[i]);
    }

    Boolean result = arrayComparison(A1,A2,N1,N2);

    if(result == 1){
        printf("\nL'array A2 e' contenuto in A1");
    }else{
        printf("\nL'array A2 non e' contenuto in A1");
    }

    return 0;
}

Boolean arrayComparison(int *A1, int *A2, int N1, int N2){
    Boolean found;
    found = FALSE;
    for (int i = 0; i < N1-N2  ; ++i) {
        if(A1[i]==A2[0]){
            for (int j = 1; j < N2 ; ++j) {
                if(A2[j]!=A1[i+j]) break;
                if(j==(N2-1)) found = TRUE;
            }
        }
    }
return found;
}