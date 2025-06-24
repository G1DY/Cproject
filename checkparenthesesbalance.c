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

/**
 * main- Programs entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 1 on argument error
 */
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

/**
 * pointernullcheck- Checks if a given pointer is NULL
 * @pointer: The pointer to check
 * @nullpointer: Pointer to int where result is stored
 * Return: 1 if null, 0 otherwise
 */
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

/**
 * raiseargeorrornullpointer- Raises error if pointer is NULL
 * @pointer: Pointer to validate
 * Return: 1 if NULL, 0 otherwise
 */
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

/**
 * raiseargeorrornulldpointer- Raises error if double pointer is NULL
 * @pointer: Pointer to a pointer to validate
 * Return: 1 if NULL, 0 otherwise
 */
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

/**
 * raiseargerrornegativeint- Raises error if integer is negative
 * @value: Interger to check
 * Return: 1 if negative, 0 otherwise
 */
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

/**
 * raiseargerrornotpositiveint- Raises error if int is 0 or negative
 * @value: Integer to check
 * Return: 1 if value is 0 or negative, 0 otherwise
 */
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

/**
 * grthanzerocheck- Checks if a number is greater than 0
 * @number: Number to check
 * @greaterthanzero: Pointer to result
 * Return: 1 if number is greater than 0, else 0
 */
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

/**
 * raiseargeorrornotegrthanzerobuf- Checks if buffer is valid and size > 0
 * @bufbegin: Pointer to beginning of buffer
 * @bufsize: Buffer size in bytes
 * Return: 1 on error, 0 otherwise
 */
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

/**
 * bufchecknullterminated- Checks if a buffer is null-terminated
 * @bufbegin: Pointer to buffer start
 * @bufsize: Size of the buffer
 * @bufnullterminated: Pointer to the result(1-null terminated, else 0)
 * Return: 1 on error, 0 if successful
 */
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

/**
 * raiseargerrornotnullterminatedbuffer- Checks buffer is not null-terminated
 * @bufbegin: Start of the buffer
 * @bufsize: Size of the buffer
 * Return: 1 if not null-terminated or invalid, 0 otherwise
 */
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

/**
 * strlength- Computes string length if null-terminated
 * @str: The string to measure
 * @bufsize: Buffer size
 * @strl: Pointer to store string length
 * Return: 1 on error, 0 on success
 */
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

/**
 * raiseargerrornotnullterminatedtwopointedbuf- Validates 2-pointer access
 * @str: Base buffer string
 * @bufsize: size of the buffer
 * @strlocbegin: Starting location within the buffer
 * @strlocterm: Ending location within buffer
 * Return: 1 on error, 0 otherwise
 */
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

/**
 * strcheckparenthsbal- Checks if parentheses are balanced in a substring
 * @str: Full buffer
 * @bufsize: Size of the buffer
 * @strfirst: Pointer to first character in target substring
 * @strlast: Pointer to last character in target substring
 * @testr: Pointer to int storing result (1 if balanced, 0 otherwise)
 * Return: 1 on input error, 0 on success
 */
int strcheckparenthsbal(char *str, int bufsize, char *strfirst,
	char *strlast, int *testr)

{
	int balance = 0;

	/*Check that the string is valid*/
	if (raiseargerrornotnullterminatedtwopointedbuf(str, bufsize, strfirst,
		 strlast))
	{
		printf("strcheckparenthsbal: input error\n");
		return (1);
	}

	while (strfirst <= strlast)
	{
		if (*strfirst == '(')
		balance++;
		else if (*strfirst == ')')
		balance--;

		/*if closing parenthesis comes before opening, it is unbalanced*/
		if (balance < 0)
		{
			*testr = 0;
			return (0);
		}
		strfirst++;

	}
	/*if balance is 0 out of loop, we have a closing bracket after opening*/
	if (balance == 0)
	{
		*testr = 1;
	}
	else
	{
		*testr = 0;
	}
	return (0);
}
