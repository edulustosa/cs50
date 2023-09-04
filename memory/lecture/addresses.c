#include <stdio.h>

int main(void)
{
    int n = 50;
    int *ptr = &n;
    *ptr = 49;
    printf("%d", *ptr);
    printf("%d", n);

    return 0;
}
