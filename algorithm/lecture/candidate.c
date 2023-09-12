#include <stdio.h>

typedef struct
{
    char name[20];
    int votes;
} candidate;

candidate get_candidate(char prompt[])
{
    printf("%s", prompt);

    candidate c;
    scanf("%s", c.name);
    printf("Enter a number: ");
    scanf("%d", &c.votes);

    return c;
}

int main(void)
{
    candidate candidates_arr[3];
    for (int i = 0; i < 3; i++)
    {
        candidates_arr[i] = get_candidate("Enter a candidate: ");
    }

    return 0;
}
