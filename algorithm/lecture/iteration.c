#include <stdio.h>

void draw(int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main(void)
{
    int height;
    printf("Height: ");
    scanf("%i", &height);
    draw(height);

    return 0;
}
