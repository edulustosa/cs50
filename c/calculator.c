#include <stdio.h>

int main(void)
{
    long x, y;
    double z;

    printf("x: ");
    scanf("%li", &x);

    printf("y: ");
    scanf("%li", &y);

    z = (double) x / (double) y;
    printf("%.20f\n", z);
}
