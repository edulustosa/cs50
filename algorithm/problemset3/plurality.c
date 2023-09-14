#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    char name[10];
    int votes;
} candidate;

candidate candidates[MAX];
int candidates_count;

bool vote(char name[])
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int max_votes = 0;

    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

int main(int argc, char *argv[])
{
    int voters;
    char name[20];
    candidates_count = argc - 1;

    printf("Candidates: \n");
    for (int i = 1; i < argc; i++)
    {
        strcpy(candidates[i - 1].name, argv[i]);
        candidates[i - 1].votes = 0;
        printf("%s\n", candidates[i - 1].name);
    }

    printf("Number of voters: ");
    scanf("%d", &voters);

    for (int i = 0; i < voters; i++)
    {
        printf("Vote: ");
        scanf("%s", name);

        if (!(vote(name)))
        {
            i--;
            printf("Invalid vote\n");
        }
    }

    print_winner();

    return 0;
}
