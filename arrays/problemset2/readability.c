#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[500];
    int letters = 0;
    int word = 0;
    int senteces = 0;
    float index;

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    word++;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            senteces++;
        }
    }

    float l = (float) letters / word * 100;
    float s = (float) senteces / word * 100;

    index = 0.0588 * l - 0.296 * s - 15.8;
    index = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        switch ((int) index)
        {
            case 1:
                printf("Grade 1\n");
                break;

            case 2:
                printf("Grade 2\n");
                break;

            case 3:
                printf("Grade 3\n");
                break;

            case 4:
                printf("Grade 4\n");
                break;

            case 5:
                printf("Grade 5\n");
                break;

            case 6:
                printf("Grade 6\n");
                break;

            case 7:
                printf("Grade 7\n");
                break;

            case 8:
                printf("Grade 8\n");
                break;

            case 9:
                printf("Grade 9\n");
                break;

            case 10:
                printf("Grade 10\n");
                break;

            case 11:
                printf("Grade 11\n");
                break;

            case 12:
                printf("Grade 12\n");
                break;

            case 13:
                printf("Grade 13\n");
                break;

            case 14:
                printf("Grade 14\n");
                break;

            case 15:
                printf("Grade 15\n");
                break;

            case 16:
                printf("Grade 16\n");
                break;

            default:
                printf("Grade 16+\n");
                break;
        }
    }

    return 0;
}
