#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i=0; i<4; i++)
        four_ints[i] = 2;

	printf("before: %x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i=0; i<4; i++)
        four_c[i] = 'A'; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:

	//printf("after: %x\n", four_ints[0]);


	//printf("after: %x\n", four_ints[1]);

	printf("four_int address: %p\n", four_ints);
	printf("four_c address: %p\n", four_c);
	
	/*for(i=0; i<4; i++)
	printf("four_ints[%d], address: %d, values: %x\n", i, &(four_ints[i]), four_ints[i]);

	for(i=0; i<4; i++)
	printf("four_c[%d], address: %d, values: %x\n", i, &(four_c[i]), four_c[i]);
*/
	return 0;

}
