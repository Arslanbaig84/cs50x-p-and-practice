#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);
int main(void)
{
    // Prompting string
    string text = get_string("Text: ");


    int letters;
    int words;
    int sentences;
    float L;
    float S;

    //calculating letters, words, sentences
    letters = count_letters(text);

    words = count_words(text);

    sentences = count_sentences(text);

    //calculating (words per 100 letters & sentences per 100 letters) & Index
    L = ((float)letters / words) * 100;

    S = ((float)sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    //Defining Grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 1 && index <= 16)
    {
        int i = round(index);

        switch (i)
        {
            case  1:
                printf("Grade 1\n");
                break;

            case 2:
                printf("Grade 2\n");
                break;

            case 3:
                printf("Grade 3\n");
                break;

            case 4:
                printf("Grade 4\n");
                break;

            case 5:
                printf("Grade 5\n");
                break;

            case 6:
                printf("Grade 6\n");
                break;

            case 7:
                printf("Grade 7\n");
                break;

            case 8:
                printf("Grade 8\n");
                break;

            case 9:
                printf("Grade 9\n");
                break;

            case 10:
                printf("Grade 10\n");
                break;

            case 11:
                printf("Grade 11\n");
                break;

            case 12:
                printf("Grade 12\n");
                break;

            case 13:
                printf("Grade 13\n");
                break;

            case 14:
                printf("Grade 14\n");
                break;

            case 15:
                printf("Grade 15\n");
                break;

            case 16:
                printf("Grade 16\n");
                break;
        }
    }
    else
    {
        printf("Grade 16+\n");
    }

}

//definfing function to calculate letters
int count_letters(string s)
{
    int counter1 = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            counter1++;
        }
    }
    return counter1;
}

//defining function to calculate words
int count_words(string s)
{
    int counter2 = 1;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            counter2++;
        }
    }
    return counter2;
}

//defining function to calculate sentences
int count_sentences(string s)
{
    int counter3 = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == '.' || s[i] == '?' || s[i] == '!'))
        {
            counter3++;
        }
    }
    return counter3;
}