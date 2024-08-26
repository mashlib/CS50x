#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickles(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarter_count = calculate_quarters(cents);
    cents -= (quarter_count * 25);

    int dime_count = calculate_dimes(cents);
    cents -= (dime_count * 10);

    int nickle_count = calculate_nickles(cents);
    cents -= (nickle_count * 5);

    int penny_count = calculate_pennies(cents);
    cents -= (penny_count * 1);

    int amount = quarter_count + dime_count + nickle_count + penny_count;
    printf("%i\n", amount);
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarter_count = 0;
    while (cents >= 25)
    {
        quarter_count++;
        cents -= 25;
    }
    return quarter_count;
}

int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give customer
    int dime_count = 0;
    while (cents >= 10)
    {
        dime_count++;
        cents -= 10;
    }
    return dime_count;
}

int calculate_nickles(int cents)
{
    // Calculate how many nickles you should give customer
    int nickle_count = 0;
    while (cents >= 5)
    {
        nickle_count++;
        cents -= 5;
    }
    return nickle_count;
}

int calculate_pennies(int cents)
{
    // Calculate how many pennies you should give customer
    int penny_count = 0;
    while (cents >= 1)
    {
        penny_count++;
        cents -= 1;
    }
    return penny_count;
}
