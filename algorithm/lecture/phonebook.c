#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[20];
    char number[20];
}
person;

int main(void)
{
    person people[2];

    strcpy(people[0].name, "Eduardo");
    strcpy(people[0].number, "61 99305-6510");

    strcpy(people[1].name, "Valdo");
    strcpy(people[1].number, "61 99169-2423");

    char name[20];
    printf("Name: ");
    scanf("%s", name);

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
