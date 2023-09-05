#include <stdio.h>

int main(void)
{
    int n;

    printf("Number: ");
    do
    {
        scanf("%d", &n);
    } while (n < 1);

    int array[n];
    array[0] = 1;
    printf("%d\n", array[0]);

    for (int i = 1; i <= n; i++)
    {
        array[i] = array[i - 1] * 2;
        printf("%d\n", array[i]);
    }

    return 0;
}
