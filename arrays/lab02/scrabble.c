#include <stdio.h>
#include <string.h>
#include <ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_word(void)
{
    int sum = 0;
    char alfabet[26], word[100];

    for (int i = 0; i < 26; i++)
    {
        alfabet[i] = 'A' + i;
    }

    scanf("%s", word);
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        word[i] = toupper(word[i]);
        if (word[i] >= 65 && word[i] <= 90)
        {
            for (int j = 0; j < 26; j++)
            {
                if (word[i] == alfabet[j])
                {
                    sum += POINTS[j];
                }
            }
        }
    }

    return sum;
}

int main(void)
{
    printf("Player 1: ");
    int player1 = get_word();

    printf("Player 2: ");
    int player2 = get_word();

    printf("P1: %i points\n", player1);
    printf("P2: %i points\n", player2);

    if (player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2 > player1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}
