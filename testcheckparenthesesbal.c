#include <stdio.h>
#include <string.h>

//function declaration so the compiler knows about it
int strcheckparenthsbal(char *str, int bufsize, char *strfirst,
	char *strlast, int *testr);

int main(void)
{
    struct {
        char *expression;
        char *desc;
    } tests[] = {
        { "(x^2)+(8*x^3)-x", "Balanced expression" },
        { "((3+4)*2", "Unbalanced - missing closing" },
        { "3+4)*2", "Unbalanced - extra closing" },
        { "((3+4)*2)", "Balanced nested" },
        { "x + y", "No parentheses" },
        { NULL, NULL } // Sentinel
    };

    int i = 0;
    while (tests[i].expression != NULL)
    {
        char *expr = tests[i].expression;
        int balanced;

        int err = strcheckparenthsbal(expr, strlen(expr) + 1,
                                       expr, expr + strlen(expr) - 1,
                                       &balanced);

        printf("Test %d: %s\n", i + 1, tests[i].desc);
        if (err)
        {
            printf("Input error detected\n");
        }
        else if (balanced)
        {
            printf("Balanced: \"%s\"\n", expr);
        }
        else
        {
            printf("Not balanced: \"%s\"\n", expr);
        }
        i++;
    }

    return 0;
}
