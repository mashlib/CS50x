#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number = 0;
    int last_digit = 0;
    int sum_not_multiplied = 0;
    int sum_multiplied = 0;
    int multiplied_digit = 0;
    int sum = 0;

    // gets the card number
    do
    {
        card_number = get_long("Card number: ");
    }
    while (card_number < 0);

    // checks if the number has the correct length
    int i = 0;
    long cc = card_number;
    while (cc > 0)
    {
        cc /= 10;
        i++;
    }

    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // while theres more than 1 digit left runs the loop
    // assigns the cardnumber to nextnumber to store the next variable
    // after the last digit is removed.
    long next_number = card_number;
    while (next_number >= 10)
    {
        // gets the last digit and adds them to the sum of digits that wont get multiplied
        last_digit = next_number % 10;
        sum_not_multiplied += last_digit;

        // removes the last digit, the next one and multiplies them with each other
        next_number /= 10;
        last_digit = next_number % 10;

        // condition will check if its a 2 digit number and then adds the product of them together.
        multiplied_digit = last_digit * 2;
        if (multiplied_digit >= 10)
        {
            multiplied_digit = multiplied_digit / 10 + multiplied_digit % 10;
        }
        sum_multiplied += multiplied_digit;
        // removes the last digit again
        next_number /= 10;
    }
    // adds the last leftover digit to the not mutiplied sum
    // gets the total sum and checks if the cardnumber is valid.
    sum_not_multiplied += next_number;
    int totalsum = sum_not_multiplied + sum_multiplied;

    // check luhn algorithm
    if (totalsum % 10 != 0)
        printf("INVALID\n");
    else
    {
        // start is the first digit
        long start = card_number;
        do
        {
            start = start / 10;
        }
        while (start > 100);
        // check for Visa
        if ((i == 13 || i == 16) && (start / 10 == 4))
            printf("VISA\n");
        // check for Amex
        else if ((i == 15) && (start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
            printf("AMEX\n");
        // check for Mastercard
        else if ((i == 16) && (start / 10 == 5) && (0 < start % 10 && start % 10 <= 5))
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    }
}
