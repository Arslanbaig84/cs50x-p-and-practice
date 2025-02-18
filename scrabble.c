#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int letters = 26;
int small_letters[letters];
int capital_letters[letters];

int compute_score(string word);

int main(void)
{

    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    for (int i = 0; i < letters; i++)
    {
        small_letters[i] = i + 97;
    }

    for (int i = 0; i < letters; i++)
    {
        capital_letters[i] = i + 65;
    }

    int ascii[strlen(word)];

    for (int i = 0; i < strlen(word); i++)
    {
        ascii[i] = word[i];
    }

    int score = 0;
    for (int i = 0 ; i < strlen(word); i++)
    {
        for (int j = 0; j < letters; j++)
        {
            if (ascii[i] == small_letters[j])
            {
                score += POINTS[j];
            }
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < letters; j++)
        {
            if (ascii[i] == capital_letters[j])
            {
                score += POINTS[j];
            }
        }
    }
    return score;
}
