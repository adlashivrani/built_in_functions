#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20

char *Tolower(char*);

int main()
{
	char *str = NULL;
	str = (char*) malloc (SIZE * sizeof(char));
	if (NULL == str) {
		printf("\nMalloc failed\n");
		exit(1);
	}
	printf("\nEnter a string:\n");
	if ((fgets(str, SIZE, stdin) == NULL)) {
		printf("\nfgets failed!\n");
		exit(1);
	}
	*(str +(strlen(str) - 1)) = '\0';
	char *temp = Tolower(str);
	printf("\nString after tolower():%s\n", temp);
	free(str);
	str = NULL;
	return 0;
}

char *Tolower(char *str)
{
	char *temp = str;
	int i = 0;
	while (*str != '\0') {
		if ( (*str >= 'A') && (*str <= 'Z')) {
			*str = *str + 32;
		} 
		*str++;
	}
	return temp;
}
	
