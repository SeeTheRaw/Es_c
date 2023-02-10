#include <stdio.h>

void sequentialSort(int *V, int size, int *perm);
void swap(int *V, int indOfMax, int pos);


int main(void){
int V[10]={34,9,27,46,10,35,22,1,51,99};
int size=10;
int perm[size];
    printf("Lista: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d ",V[i]);

    }
    printf("\n");
    sequentialSort(V,size,perm);
    printf("\nLista ordinata: \n");
    for (int i = 0; i < size; ++i) {
        printf("%d ",V[perm[i]]);

    }
    return 0;
}



void sequentialSort(int *V, int size, int *perm) {
    int indOfMax;
    //inizializzo perm con l'ordine degli elementi
    for (int i = 0; i < size; i++)
        perm[i] = i;

    for (int i = 0; i < size-1; i++) {
        indOfMax = 0;
        for(int j=1; j<size - i; j++){
            if(V[perm[j]] > V[perm[indOfMax]])
                indOfMax = j;
        }
        swap(perm, indOfMax, size-i-1);
    }
}

void swap(int *V, int indOfMax, int pos){
    int tmp = V[pos];
    V[pos] = V[indOfMax];
    V[indOfMax] = tmp;
}

