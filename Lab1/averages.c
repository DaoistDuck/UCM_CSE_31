#include <stdio.h>

int main(){

int i, negSum = 0, posSum = 0, negCount = 0, posCount = 0;
  printf("Please enter an integer: ");
while(scanf("%d",&i) == 1 && i!=0){ // scanf("%d" ,&i) == 1 is testing the while and seeing if its true
  printf("Please enter an integer: ");
  if(i < 0){
    negSum += i;
    negCount++;
  } else{
    posSum += i;
    posCount++;
  }
}

  printf("Positive average: %d\n", posCount == 0 ? 0 : posSum/posCount);
                                   //posCount == 0 true its 0 not its avg
  printf("Negative average: %d\n", negCount == 0 ? 0 : negSum/negCount);
                                    //negCount == 0 true its 0 not its the avg

  return 0;
}
// help from these websites
//https://stackoverflow.com/questions/26094119/create-a-c-program-that-sums-up-the-positive-and-negative-numbers-without-arrays
//https://stackoverflow.com/questions/44116502/c-programming-conversion-of-type-condition-to-simple-if-else
