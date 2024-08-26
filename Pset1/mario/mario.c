#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);
void print_spaces(int spaces);

int main(void)
{
    int input;

    do
    {
        input = get_int("Height: ");
    }
    while (input < 1);

    for (int i = 0; i < input; i++)
    {
        print_spaces(input - i - 1);
        print_row(i + 1);
        printf("  ");
        print_row(i + 1);
        printf("\n");
    }
}
void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}
void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}
