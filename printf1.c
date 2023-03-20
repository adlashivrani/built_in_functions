#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
//#define itoa(s) #s

int print (char *, ...);
char* itoa (unsigned long long ,  char[],  int );

int main()
{
	int num;
	char ch;
	print("Enter a number & char\n");
	scanf("%d %c", &num, &ch);
	print("Printf:\nnum:%d\nch: %c\n", num, ch);
	return 0;
}

int print (char * str, ...)
{
	va_list vl;
	int i = 0, j=0;
		char buff[100]={0};
		char tmp[20];
		va_start( vl, str ); 
		while (str && str[i])
		{
		  	if(str[i] == '%')
		  	{
 		    i++;
 		    switch (str[i]) 
 		    {
	 		    case 'c': 
	 		    {
	 		        buff[j] = (char)va_arg( vl, int );
	 		        j++;
	 		        break;
	 		    }
	 		    case 'd': 
	 		    {
	 		        itoa(va_arg( vl, int ), tmp, 10);
				//	tmp = itoa(va_arg(vl, int));
	 		        strcpy(&buff[j], tmp);
	 		        j += strlen(tmp);
		           break;
		        }
				case 'X':
		        case 'x': 
		        {
		           itoa(va_arg( vl, int ), tmp, 16);
				//	tmp = itoa(va_arg(vl, int));
		           	strcpy(&buff[j], tmp);
		           	j += strlen(tmp);
		           	break;
		        }
        	}
     	} 
     	else 
	    {
	       	buff[j] =str[i];
	       	j++;
	    }
	    i++;
	} 
    fwrite(buff, j, 1, stdout); 
    va_end(vl);
    return j;
}

char* itoa (unsigned long long  value,  char str[],  int radix)
{
    char        buf [66];
    char*       dest = buf + sizeof(buf);
    char     sign = FALSE;

    if (value == 0) {
        memcpy (str, "0", 2);
        return str;
    }

    if (radix < 0) {
        radix = -radix;
        if ( (long long) value < 0) {
            value = -value;
            sign = TRUE;
        }
    }

    *--dest = '\0';

    switch (radix)
    {
    case 16:
        while (value) {
            * --dest = '0' + (value & 0xF);
            if (*dest > '9') *dest += 'A' - '9' - 1;
            value >>= 4;
        }
        break;
    case 10:
        while (value) {
            *--dest = '0' + (value % 10);
            value /= 10;
        }
        break;

    case 8:
        while (value) {
            *--dest = '0' + (value & 7);
            value >>= 3;
        }
        break;

    case 2:
        while (value) {
            *--dest = '0' + (value & 1);
            value >>= 1;
        }
        break;

    default:            // The slow version, but universal
        while (value) {
            *--dest = '0' + (value % radix);
            if (*dest > '9') *dest += 'A' - '9' - 1;
            value /= radix;
        }
        break;
    }

    if (sign) *--dest = '-';
    memcpy (str, dest, buf + sizeof(buf) - dest);
    return str;
}
