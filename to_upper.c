#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100

char *Toupper(char*);

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
    char *temp = Toupper(str);
    printf("\nString after toupper():%s\n", temp);
    free(str);
    str = NULL;
    return 0;
}

char *Toupper(char *str)
{
	char *temp = str;
    int i = 0;
    while (*str != '\0') {
    	if ( (*str >= 'a') && (*str <= 'z')) {
        	*str = *str - 32;
        }
       	*str++;
    }
    return temp;
}
