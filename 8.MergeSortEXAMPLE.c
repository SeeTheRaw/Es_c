#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

void fusion(int *V, int N1, int size, int *tmp);
void merge_interface(int *V, int size);
void mergeSort(int *V, int size, int* tmp);

int main(void){
    int V[10]={8,23,1,67,77,2,8,9,12,78};
    int size=10;
    printf("V= ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", V[i]);
    }
    printf("\n\n");

    merge_interface(V,size);

    printf("V ordinato= ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", V[i]);
    }

    return 0;
}

void fusion(int *V, int N1, int size, int *tmp){
    for (int i = 0; i < N1; i++) {
        tmp[i] = V[i];
    }
    int r=0, l=0;

    while(l < N1 && r < size - N1){
        if(tmp[l] < V[N1 + r]){
            V[l + r] = tmp[l];
            l++;
        }else{
            V[l + r] = V[N1 + r];
            r++;
        }
    }

    while(l<N1){
        V[l + r] = tmp[l];
        l++;
    }
}


void merge_interface(int *V, int size){
    int *tmp;
    tmp = (int *)malloc(sizeof(int) * size);
    mergeSort(V, size, tmp);
    free(tmp);
}


void mergeSort(int *V, int size, int* tmp){
    if(size>1){
        mergeSort(V, size/2, tmp);
        mergeSort(&V[size/2],size - size/2, &tmp[size/2]);
        fusion(V, size/2, size, tmp);
    }
}
