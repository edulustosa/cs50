#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[] = "abc";
    int aux;

    for (int i = 0; i < strlen(string) - 1; i++)
    {
        if (string[i] > string[i + 1])
        {
            aux = 1;
            break;
        }
        else
        {
            aux = 0;
        }
    }

    if (aux == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}
