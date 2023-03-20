#include<stdio.h>

long int myabs(long int );

int main()
{
	long int num;
	printf("\nEnter number\n");
	scanf("%ld", &num);
	long int res = myabs(num);
	printf("\nAfter abs():%ld", res);
	return 0;
}

long int myabs(long int num)
{
	if ( num < 0) {
		num = (-1)*num;
	}
	return num;
}
		
