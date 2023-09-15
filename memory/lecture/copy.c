#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[10];

    printf("s: ");
    scanf("%s", s);

    char *t = malloc(strlen(s) + 1);

    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(s) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);

    return 0; 
}
