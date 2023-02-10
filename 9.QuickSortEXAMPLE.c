#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

int partition(int *V, int size);
void swap(int *V, int a, int b);
void quickSort(int *V, int size);

int main(void){
    int V[10]={8,23,1,67,77,2,8,9,12,78};
    int size=10;
    printf("V= ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", V[i]);
    }
    printf("\n\n");

    quickSort(V,size);

    printf("V ordinato= ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", V[i]);
    }

    return 0;
}

int partition(int *V, int size){
    int pivot = V[0];
    int l = 0;
    int r = size;

    while(l < r){
        do{
            r--;
        }while(V[r] > pivot && r > l);

        if(r != l) {
            do {
                l++;
            } while (V[l] <= pivot && l < r);
            swap(V, r, l);
        }
    }
    swap(V, l, 0);  //swap pivot
    return l;   //restituisce la posizione del pivot
}

void swap(int *V, int a, int b){
    int tmp = V[a];
    V[a] = V[b];
    V[b] = tmp;
}

void quickSort(int *V, int size){
    int q;    //posizione del pivot ritornata dalla quickSort
    if(size > 1){
        q = partition(V, size);
        quickSort(V, q);
        quickSort(&V[q + 1], size - q - 1);
    }
}
