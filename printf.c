#include<stdio.h>
#include <stdarg.h>

struct new {
	int num;
	char ch;
};

void _printf(char *, ...);

//main function
int main()
{
    int num1 = 10; //can take user input
    double num2 = 123.23456;
    char num3 = 'a';
    char *str = "Hlooo!";
	struct new abc;
	abc.num = 3000;
	abc.ch = 'v';
	//_printf();
	_printf("After printf: %d \n %f \n %c \n %s \n", num1, num2, num3, str);
	_printf("---%d %c\n", abc.num, abc.ch);
    return 0;
}

void _printf( char *value, ...) //function for printf
{
//	char *value;
    va_list args; 
    va_start(args, value);

    int i = 0;
    while (value[i]) {
        if (value[i] == '%') {
            i++;
            switch (value[i]) {

                case 'd':
                {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    break;
                }
                case 'f':
                {
                    double num = va_arg(args, double);
                   	printf("%lf", num);
                    break;
                }
                case 'c':
                {
                    int num = va_arg(args, int);
                    printf("%c", num);
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char*);
                    printf("%s", str);
                    break;
                }
                case 'x':
                case 'X':
                {
                    int num = va_arg(args, int);
                    printf("%x", num);
                    break;
                }
                case 'p':
                {
                    void *str = va_arg(args, void*);
                    printf("%p", str);
                    break;
                }                
				case '%':
                    putchar('%');
                    break;
                default:
                    putchar(value[i]);
                    break;
            	}
        	} else {
            	putchar(value[i]);
        	}
        	i++;
    	}

    va_end(args);
}
