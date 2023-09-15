#include <stdio.h>

int main(void)
{
    char i[10];
    char j[10];
    printf("i: ");
    scanf("%s", i);
    printf("j: ");
    scanf("%s", j);

    printf("%p\n", i);
    printf("%p\n", j);

    return 0;
}
