#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string word);

// points for each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // get the words for each player
    string word_player1 = get_string("Player 1 enter your word, ");
    string word_player2 = get_string("Player 2 enter your word, ");

    // get the score for each word
    int score_player1 = get_score(word_player1);
    int score_player2 = get_score(word_player2);

    if (score_player1 > score_player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_player1 < score_player2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string word)
{
    // compute and return score for word
    int score = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
