#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main(void)
{
    int num;
    printf("Type a number: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("Fatorial of %d is %d\n", num, result);

    return 0;
}
