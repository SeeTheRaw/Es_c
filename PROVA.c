#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

void bubbleSort(int *V, int size);
void swap(int *V, int a, int b);

int main(void){
    int V[10]={8,23,1,67,77,2,8,9,12,78};
    int size=10;
    printf("V= ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", V[i]);
    }
    printf("\n\n");
    bubbleSort(V,size);
    //confronta gli elementi adiacenti e in caso gli swappa. dopo N iterazioni gli elementi sono ordinati

    printf("V ordinato= ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", V[i]);
    }
    return 0;
}

void bubbleSort(int *V, int size){
    Boolean hasSwap;
    int iter = 0;
    do{
        hasSwap = FALSE;
        for(int i=0; i<size - iter -1; i++){
            if(V[i] > V[i + 1]) {
                swap(V, i, i + 1);
                hasSwap = TRUE;
            }
        }
        iter++;
    }while(hasSwap);
}

void swap(int *V, int a, int b){
    int tmp = V[a];
    V[a] = V[b];
    V[b] = tmp;
}