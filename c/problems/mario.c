#include <stdio.h>

int main(void)
{
    int h = 8;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
           printf("#");
        }
        printf("\n");
    }
}
