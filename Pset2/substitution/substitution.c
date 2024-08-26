#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int key_length = strlen(argv[1]);
    // checks for length
    if (key_length != 26)
    {
        printf("Key must contain 26 charaters.\n");
        return 1;
    }
    // checks if cars are alphabetical
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetical characters.\n");
            return 1;
        }
        // checks for duplicates
        for (int j = i + 1; j < key_length; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters.");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    int plaintext_length = strlen(plaintext);

    printf("ciphertext: ");
    // shifts the character accordingly and prints out the ciphertext
    for (int i = 0; i < plaintext_length; i++)
    {

        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(argv[1][plaintext[i] - 'A']));
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(argv[1][plaintext[i] - 'a']));
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");
}
