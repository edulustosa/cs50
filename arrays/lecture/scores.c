#include <stdio.h>

const int N = 3;

float average(int array[])
{
    int sum = 0;
    for (int j = 0; j < N; j++)
    {
        sum += array[j];
    }

    return sum / (float) N;
}

int main(void)
{
    int scores[N];
    
    for (int i = 0; i < N; i++)
    {
        printf("Score %i: ", i);
        scanf("%i", &scores[i]);
    }

    printf("Average: %f\n", average(scores));

    return 0;
}
