#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i <= argc; i++)
    {
        printf("%c\n", argv[i][0]);
    }

    return 0;
}
