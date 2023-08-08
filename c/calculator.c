#include <stdio.h>

int main(void)
{
    long x, y;
    float z;

    printf("x: ");
    scanf("%li", &x);

    printf("y: ");
    scanf("%li", &y);

    z = (float) x / (float) y;
    printf("%f\n", z);
}
