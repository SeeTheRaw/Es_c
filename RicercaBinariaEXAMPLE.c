#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned short int Boolean;
#define TRUE 1
#define FALSE 0

Boolean binarySearch(int* V, int size, int target);

int main(void){
    int V[7]={1,2,3,4,5,6,7};
    int size=7;
    printf("V= ");
    for (int i = 0; i < size; i++) {
        printf("%d ", V[i]);
    }
    int target;
    printf("\nche target vuoi cercare?: \n");
    scanf("%d", &target);
    printf("%d", target);
    Boolean Result = binarySearch(V,size,target);
    if(Result==1){
        printf("\ntarget TROVATO!");
    } else printf("\ntarget NON TROVATO");
    return 0;
}


Boolean binarySearch(int* V, int size, int target){
    if(size){
        if(V[size/2] == target)
            return TRUE;
        else
        if(V[size/2] > target)
            return binarySearch(V, size/2, target);
        else
            return binarySearch(&V[size/2 + 1], size - (size/2)-1, target);
    }else{
        return FALSE;
    }
}

