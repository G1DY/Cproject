#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void pointernullcheck(char *pointer, int *nullpointer);
int raiseargeorrornullpointer(char *pointer);
int raiseargeorrornulldpointer(char **pointer);
int raiseargerrornegativeint(int value);
int raiseargerrornotpositiveint(int value);
void grthanzerocheck(int number, int *greaterthanzero);
int raiseargeorrornotegrthanzerobuf(char *bufbegin, int bufsize);
int bufchecknullterminated(char *bufbegin, int bufsize,
int *bufnullterminated);
int raiseargerrornotnullterminatedbuffer(char *bufbegin, int bufsize);
int strlength(char *str, int bufsize, int *strl);
int strcheckparenthsbal(char *str, int bufsize,
char *strfirst, char *strlast, int *testr);

char testbuf[500] = "(x^2)+(8*x^3)-x";

int main(int argc, char *argv[])
{
	int balanced;

	if (strcheckparenthsbal(testbuf, sizeof(testbuf), testbuf,
	testbuf + 5, &balanced))
	{
		printf("argument error\n");
		return (1);
	}
	printf("Parentheses in %s check, test result: %i\n", testbuf, balanced);
	return (0);
}


void pointernullcheck(char *pointer, int *nullpointer)
{
	if (pointer == NULL)
	{
		*nullpointer = 1;
	}
	else
	{
		*nullpointer = 0;
	}
}

int raiseargeorrornullpointer(char *pointer)
{
	int nullpointer;

	pointernullcheck(pointer, &nullpointer);

	if (nullpointer)
	{
		printf("NULL pointer\n");
		return (1);
	}
	else
	{
		return (0);
	}
}

int raiseargeorrornulldpointer(char **pointer)
{
	int nullpointer;

	if (*pointer == NULL)
	{
		printf("NULL pointer to pointer\n");
		return (1);
	}
	else
	{
		return (0);
	}
}

int raiseargerrornegativeint(int value)
{
	if (value < 0)
	{
		printf("negative int arg\n");
		return (1);
	}
	else
	{
		return (0);
	}
}

int raiseargerrornotpositiveint(int value)
{
	if (value <= 0)
	{
		printf("not positive int arg\n");
		return (1);
	}
	else
	{
		return (0);
	}
}

void grthanzerocheck(int number, int *greaterthanzero)
{
	if (number > 0)
	{
		*greaterthanzero = 1;
	}
	else
	{
		*greaterthanzero = 0;
	}
}

int raiseargeorrornotegrthanzerobuf(char *bufbegin, int bufsize)
{
	if (raiseargeorrornullpointer(bufbegin))
	{
		printf("raiseargeorrornotegrthanzerobuf\n");
		return (1);
	}
	int greaterthanzero;

	grthanzerocheck(bufsize, &greaterthanzero);

	if (!greaterthanzero)
	{
		printf("Buffer size is not greater than zero\n");
		return (1);
	}
	return (0);
}

int bufchecknullterminated(char *bufbegin, int bufsize,
	int *bufnullterminated)
{
	if (raiseargeorrornotegrthanzerobuf(bufbegin, bufsize))
	{
		printf("bufchecknullterminated\n");
		return (1);
	}
	char *chrp = bufbegin;

	while (*chrp != '\0')
	{
		chrp++;
		if (chrp > bufbegin + bufsize - 1)
		{
			*bufnullterminated = 0;
			return (1);
		}
	}
	*bufnullterminated = 1;
	return (0);
}

int raiseargerrornotnullterminatedbuffer(char *bufbegin, int bufsize)
{
	int bufnullterminated;

	if (bufchecknullterminated(bufbegin, bufsize, &bufnullterminated))
	{
		printf("raiseargerrornotnullterminatedbuffer");
		return (1);
	}
	if (!bufnullterminated)
	{
		printf("Buffer is not null terminated\n");
		return (1);
	}
}

int strlength(char *str, int bufsize, int *strl)
{
	if (raiseargerrornotnullterminatedbuffer(str, bufsize))
	{
		printf("strlength\n");
		return (1);
	}
	*strl = strlen(str);
	return (0);
}

int raiseargerrornotnullterminatedtwopointedbuf(char *str,
	int bufsize, char *strlocbegin, char *strlocterm)
{
	int strl;

	if (strlength(str, bufsize, &strl))
	{
		printf("raiseargerrornotnullterminatedtwopointedbuf\n");
		return (1);
	}
	if (raiseargeorrornullpointer(strlocbegin))
	{
		printf("raiseargerrornotnullterminatedtwopointedbuf\n");
		return (1);
	}
	if (raiseargeorrornullpointer(strlocterm))
	{
		printf("raiseargerrornotnullterminatedtwopointedbuf\n");
		return (1);
	}
	if (strlocbegin < str)
	{
		printf("raiseargerrornotnullterminatedtwopointedbuf: ");
		printf("strlocbegin points before str beginning\n");
		return (1);
	}
	if (strlocterm < strlocbegin)
	{
		printf("raiseargerrornotnullterminatedtwopointedbuf: ");
		printf("strlocterm points before str strlocbegin\n");
		return (1);
	}
	if (str + strl < strlocterm)
	{
		printf("raiseargerrornotnullterminatedtwopointedbuf: ");
		printf("strlocterm points after str ending null character\n");
		return (1);
	}
	return (0);
}

int strcheckparenthsbal(char *str, int bufsize, char *strfirst,
	char *strlast, int *testr)
{

}
