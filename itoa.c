#include <stdio.h>
#define myitoa(x) #x

int main()
{
	char* temp;
	temp = myitoa(-21432567);
	printf("\nAfter itoa: %s\n",temp);
	return 0;
}

