#include <stdio.h>

int get_height(void);

int main(void)
{
    int h;

    h = get_height();

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

        printf(" ");

        for (int l = 0; l < i; l++)
        {
           printf("#");
        }
        
        printf("\n");
    }
}

int get_height(void)
{
    int i;

    do 
    {
        printf("Height: ");
        scanf("%d", &i);
    } while (i < 1 || i > 8);
    return i;
}
