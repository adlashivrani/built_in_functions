#include<stdio.h>

int myfloor(float );

int main()
{
	float num;
    printf("\nEnter num\n");
    scanf("%f", &num);
    int res = myfloor(num);
    printf("%d\n", res);
    return 0;
}

int myfloor(float num)
{
    int temp = num;
    if ((float)temp != num && num < 0 ) {
    	return num - 1;
    }
    return num;
}
