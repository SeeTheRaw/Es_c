#include<stdio.h>
int main(void){

struct Bottle {
  char* name;
  int maxCapacity;
  int currentCapacity;
};
 
struct Bottle bottle1 = {"Medium Bottle", 24, 0};
struct Bottle bottle2 = {"Large Bottle", 48, 20};
bottle1.currentCapacity = 15;
printf("bottle1 current capacity is %d", bottle1.currentCapacity);
}
