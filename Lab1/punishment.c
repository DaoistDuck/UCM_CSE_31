#include <stdio.h>

int main(){

  int a, b, c;

  printf("Enter the number of lines for the punishment: ");
  scanf("%d", &a);
  if(a < 0){
    printf("You have entered an incorrect value for the number of lines!");
  }
  else{
    printf("Enter the line for which we want to make a typo: ");
    scanf("%d", &b);
    if(b < 0){
      printf("You have entered an incorrect value for the line typo!");
    } else{
        b--;

        for(c = 0; c < a; c = c + 1){
           if(c != b){
             printf("C programming language is the best! ");
           } else{
             printf("C programming language is the bet! ");
           }
        }
    }

  }
  return 0;
}
