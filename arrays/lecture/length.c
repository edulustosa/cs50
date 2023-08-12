#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[20];

    printf("What's your name? ");
    scanf("%s", name);

    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }

    printf("%i\n", n);
    printf("%lli\n", strlen(name));
    
    return 0;
}
