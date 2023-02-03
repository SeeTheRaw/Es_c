// SI DEFINISCA LA FUNZIONE C CHE RICEVE DUE VALORI INTERI N E Sum E POI ACQUISISCE NUMERI INTERI DA TASTIERA FINO A CHE
// LA SOMMA DEGLI ULTIMI N NUMERI INSERITI é UGUALE A Sum
#include<stdio.h>
#include<stdlib.h>
void trap_until_sum_is_over(int N, int Sum);

int main(void){
    int N;
    int Sum;
    printf("\ninserisci il valore di N:");
    scanf("%d", &N);
    printf("\ninserisci il valore di Sum:");
    scanf("%d", &Sum);
    trap_until_sum_is_over(N, Sum);
    return 0;
}

void trap_until_sum_is_over(int N, int Sum){
    int count;
    int *V;
    int sumTemp;
    count=0;
    V=(int *)malloc(N*sizeof(int));
    for (count=0, sumTemp=0; Sum!=sumTemp; count++) {
        sumTemp=0;
        count=0;
        while(count<N){
            printf("\ninserisci un numero n:");
            scanf("%d", &V[count]);
            sumTemp += V[count];
            count++;
        }
        printf("sumTemp=%d", sumTemp);
        if(sumTemp!=Sum){
            printf("\nsumTemp diverso da Sum!!!");
        }
    }
    printf("\nN= %d", N);
    printf("\nSum = %d", Sum);

    free(V);
}
// Made by Lorenzo ChadSittaro
