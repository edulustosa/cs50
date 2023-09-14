#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
} pair;

char candidates[MAX][20];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_banana = true;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                is_banana = false;
                break;
            }

            if (is_banana)
            {
                printf("%s\n", candidates[i]);
                return;
            }
        }
    }

    return;
}

bool is_cycle(int winner, int loser)
{
    if (locked[loser][winner])
        return true;

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] && is_cycle(winner, i))
            return true;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
// This function was very difficult so I looked at some tutorials
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        if (!is_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int sort[pair_count];
    int position = 0;

    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            sort[position] = abs(preferences[i][j] - preferences[j][i]);
            position++;
        }
    }

    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            if (sort[i] < sort[j])
            {
                int aux = sort[i];
                sort[i] = sort[j];
                sort[j] = aux;

                pair aux2 = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = aux2;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }

            if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }

    return;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Update ranks given a new vote
bool vote(int rank, char name[], int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    int voter_count;

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i], argv[i + 1]);
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[20];
            printf("Rank %d: ", j + 1);
            scanf("%s", name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}
