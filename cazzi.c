#include <stdio.h>
#include<stdlib.h>

// genera randomicamente da 1 a 1000 quanti cazzi ti stai rompendo per passare l'esame di informatica
int cazzi() {
  int howManyCazzi = rand() % 1000 + 1;
  return howManyCazzi;  
}
int main(){
    srand(time(NULL));
int ProvaFin = cazzi();
printf("%d", ProvaFin);
}