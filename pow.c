#include<stdio.h>

int mypow(int , int);

int main()
{
	int num;
	int pow;
	printf("\nEnter the number\n");
	scanf("%d", &num);
	printf("\nEnter the pow \n");
	scanf("%d", &pow);
	int res = mypow(num, pow);
	printf("RESULT:%d\n", res);
	return 0;
}

int mypow(int num, int pow)
{
	if (pow > 1) {
		num = num * mypow(num , (pow - 1));
	}
	return num;
}
