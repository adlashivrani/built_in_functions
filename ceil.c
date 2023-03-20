#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int myceil(float );

int main()
{
	float num;
	printf("\nEnter num\n");
	scanf("%f", &num);
	int res = myceil(num);
	printf("%d\n", res);
//	printf("%ld\n", ceil(num));
	return 0;
}

int myceil(float num)
{
	int temp = num;
	if ((float)temp != num && num > 0) {
		return num + 1;
	} 
	return num;
}
