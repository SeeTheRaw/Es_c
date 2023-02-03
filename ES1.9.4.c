
/*si definisca la funzione c che riceve da tastiera valori interi fino a quando il prodotto degli ultimi due valori
 inseriti non è uguale al valore del terz'ultimo valore inserito*/


#include<stdio.h>
int main(void){
    int new;
    int middle;
    int old;
    int product;
    printf("\ninserisci il primo numero:");
    scanf("%d", &middle);
    printf("\ninserisci il secondo numero:");
    scanf("%d", &new);
    do {
        old= middle;
        middle= new;
        printf("\ninserisci il terzo valore:");
        scanf("%d", &new);
        product= middle*new;
        printf("product= %d", product);
    } while (old != middle*new);
    printf("\nold= %d", old);
}
// Made by Lorenzo Sittaro