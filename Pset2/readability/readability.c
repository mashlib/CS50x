#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Count the number of letters, words, and sentences in the text
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
        if ((text[i]) == ' ')
        {
            words++;
        }
        if ((text[i]) == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Compute the Coleman-Liau index
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    // Print the grade level
    if (index < 1)
        printf("Before Grade 1\n");
    else if (index > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", (int) index);
}
