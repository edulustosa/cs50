#include <stdio.h>

int main(void)
{
    char name[20];
    int age;
    long int phone_number;

    printf("What's your name? ");
    scanf("%s", name);
    printf("What's your age? ");
    scanf("%d", &age);
    printf("What's your phonenumber? ");
    scanf("%ld", &phone_number);

    printf("%s %d %ld", name, age, phone_number);

    return 0;
}
