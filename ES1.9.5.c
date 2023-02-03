/* Si definisca la funzione c che riceve come parametro un valore N>1 e poi acquisisce numeri interi da tastiera fino a
 che gli ultimi N numeri inseriti sono tra loro uguali */


#include<stdio.h>
#include<stdlib.h>
void trap(int N);

int main(void){
    int N;
    printf("\ninserisci N:  ");
    scanf("%d", &N);
    while(N<=1){
        printf("NO BRO ONLY POSITIVE NUMBERS");
        printf("\ninserisci N di nuovo stronzo:  ");
        scanf("%d", &N);
    }
    trap(N);
    return 0;
}

void trap(int N){
    int *V;
    V=(int *)malloc(N*sizeof(int));
    int count = 0;
    while(count < N){
        printf("\ninserisci un numero: ");
        scanf("%d", &V[count]);
        if(V[0]==V[count]){
            count++;
        } else count=0;
    }
    printf("Good job Bro");
    free(V);
}
//made by Lorenzo ChadSittaro