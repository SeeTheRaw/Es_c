#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned short int Boolean;
#define PRECISION .000000119
#define TRUE 1
#define FALSE 0

Boolean isEqual(float Value,float target);
Boolean sequentialSearch(float *V, int size, float target);

int main(void){
    float V[7]={9,4,2,8,1,5,7};
    int size=7;
    printf("V= ");
    for (int i = 0; i < size; ++i) {
        printf("%f ", V[i]);
    }
    float target;
    printf("\nche target vuoi cercare?: \n");
    scanf("%f", &target);
    Boolean Result = sequentialSearch(V,size,target);
    if(Result==1){
        printf("\ntarget TROVATO!");
    } else printf("\ntarget NON TROVATO");
    return 0;
}



Boolean isEqual(float value, float target){
    if(value-target >= -PRECISION && value-target <= PRECISION)
        return TRUE;

    return FALSE;
}
Boolean sequentialSearch(float *V, int size, float target){
    Boolean found = FALSE;
    int index = 0;
    while(!found && index<size){
        found = isEqual(V[index], target);
        index++;
    }

    return found;
}
