#include<stdio.h>

int main(){
	int m = 10;
	int n = 5;
	
	int a0 = &m;
	int a1 = &n;
	
	int total = sum(a0, a1);
	
	printf("%d " , total);

	


}

int sum(a, b){
	int total = a + b;
	return total;
}
