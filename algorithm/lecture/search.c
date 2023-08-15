#include <stdio.h>
#include <string.h>

int main(void)
{
    char strings[][20] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    char s[20];
    printf("String: ");
    scanf("%s", s);
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
