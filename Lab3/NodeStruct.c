
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>// for mac comment out this line to work 

struct Node {
    int iValue;
    float fValue ;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert extra code here
    printf("address of head %p\n",&head);
    printf("value of head %p\n",&head);
    printf("address of iValue %p\n",&(head ->iValue));
    printf("address of fValue %p\n",&(head ->fValue));
    printf("address of next %p\n",&(head ->next));
 
	
	
	return 0;
}
