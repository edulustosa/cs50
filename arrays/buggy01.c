#include <stdio.h>

int get_negative_int(void)
{
    int n;

    do
    {
        printf("Negative Integer: ");
        scanf("%i", &n);
    } 
    while (n >= 0);
    return n;
}

int main(void)
{
    int i = get_negative_int();
    printf("%i\n", i);

    return 0;
}
