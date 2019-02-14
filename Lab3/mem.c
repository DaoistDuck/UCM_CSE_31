
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	*ptr = num; // *(ptr + 1) = 5;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;
	**handle = 5;// *mem2 = 5;
	*(*handle + 1) = 7;

	// Insert extra code here

	return 0;
} 

