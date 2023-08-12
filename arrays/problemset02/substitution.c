#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        argv[1][i] = toupper(argv[1][i]);
        for (int j = 0; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j] && j != i)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }

            if (!(argv[1][i] >= 65 && argv[1][i] <= 90)) 
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1; 
            }
        }
    }

    char alfabet_upper[26], alfabet_lower[26], key_upper[26], key_lower[26];

    for (int i = 0; i < 26; i++) 
    {
        alfabet_upper[i] = 'A' + i;
        alfabet_lower[i] = 'a' + i;
    }

    for (int i = 0; i < 26; i++) 
    {
        key_lower[i] = tolower(argv[1][i]);
        key_upper[i] = toupper(argv[1][i]);
    }

    char text[100];    
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == alfabet_lower[j])
                {
                    text[i] = key_lower[j];
                    break;
                }
            }
        }

        if (isupper(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == alfabet_upper[j])
                {
                    text[i] = key_upper[j];
                    break;
                }
            }
        }
    }

    printf("ciphertext: %s", text);

    return 0;
}
