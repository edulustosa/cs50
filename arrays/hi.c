#include <stdio.h>
#include <string.h>

int main(void) 
{
    char words[2][20];

    strcpy(words[0], "HI!");
    strcpy(words[1], "BYE!");

    printf("%s %s", words[0], words[1]);

    return 0;
}
