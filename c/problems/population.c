#include <stdio.h>

int start_size(void);
int end_size(n);
int calculate_time(pop, end);

int main(void)
{
    int n, e, result;

    n = start_size();
    e = end_size(n);

    result = calculate_time(n, e);

    printf("Years: %i", result);
}

int start_size(void)
{
    int i;
    do 
    {
        printf("Start size: ");
        scanf("%i", &i);
    } while (i < 9);
    return i;
}

int end_size(n)
{
    int i;
    do 
    {
        printf("End size: ");
        scanf("%i", &i);
    } while (i < n);    
    return i;
}

int calculate_time(pop, end)
{
    int year = 0;
    float gain, lose;

    while (pop < end)
    {
        gain = pop / 3;
        lose = pop / 4;
        pop += (int) gain;
        pop -= (int) lose;
        year++;
    }
    return year;
}
