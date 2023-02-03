
#include<stdio.h>

int addTwo(int number1, int number2) {
  int sum = number1 + number2;
  return sum;
}
 
int main() {
  int addedNumbers = addTwo(3, 6);
  printf("%d", addedNumbers);
}