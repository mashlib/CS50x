#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{

    // Make sure program was run with just-.. one command-line argument
    // Make sure every character in argv[1] is a digit
    if (argc == 2)
    {
        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            // Returns error message if key includes anything other than digits
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // converts the key into an int
        int key = atoi(argv[1]);

        string text = get_string("Plaintext: ");
        printf("ciphertext: ");
        // Rotate the character if it's a letter
        for (int i = 0, length = strlen(text); length > i; i++)
        {
            printf("%c", rotate(text[i], key));
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

char rotate(char c, int n)
{
    // will move the char into the order of 0-25 and shift it according to the key
    // at last moves the char back into the correct position in the ascii table
    if (islower(c))
    {
        c -= 'a';
        c = (c + n) % 26;
        c += 'a';
    }
    else if (isupper(c))
    {
        c -= 'A';
        c = (c + n) % 26;
        c += 'A';
    }
    return c;
}
