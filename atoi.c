#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20

int myatoi(char*);

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
        int temp = myatoi(str);
        printf("\nNum after atoi():%d\n", temp);
        free(str);
        str = NULL;
        return 0;
}

int myatoi(char *str)
{
	int temp = 0;
	while (*str != '\0') {
		temp = temp * 10 + (*str - '0');
		*str++;
	}
	return temp;
}
