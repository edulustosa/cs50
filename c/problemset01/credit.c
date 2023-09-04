#include <stdio.h>

void valid_card(long long first_digits, int digits)
{
    for (int i = 0; i < digits - 2; i++)
    {
        first_digits /= 10;
    }

    if (digits == 15 && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && (first_digits >= 51 && first_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && (first_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

void calculate_checksum(long long number)
{
    long long first_number = number;
    int i = 0;
    int sum_even = 0;
    int sum_odd = 0;
    int digit, digit_odd, checksum;

    while (number > 0)
    {
        digit = number % 10;
        number /= 10;

        if (i % 2 == 0)
        {
            sum_even += digit;
        }
        else
        {
            digit *= 2;
            if (digit >= 10)
            {
                digit_odd = digit % 10;
                digit /= 10;
                sum_odd += digit + digit_odd;
            }
            else
            {
                sum_odd += digit;
            }
        }

        i++;
    }

    checksum = sum_even + sum_odd;
    if (checksum % 10 == 0)
    {
        valid_card(first_number, i);
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    long long card_number = 4003600000000014;

    calculate_checksum(card_number);

    return 0;
}
