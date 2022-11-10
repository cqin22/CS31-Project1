#include "utilities.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int MAXWORDS = 10000;

int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
{
    if (nWords <= 0 || nWords < 0 || wordnum >= nWords)
        return -1;

    const int MAX = 99999;
    char guess[MAX];
    char target[MAXWORDLEN + 1];
    int silver = 0, gold = 0, score = 0, i = 0;
    bool isValid = true, isWord = false;

    while (true)
    {
        cout << words[wordnum] << endl;
        cout << "Probe word: ";
        cin.getline(guess, MAX, '\n');
        score++;

        isValid = true;
        if (strlen(guess) < MINWORDLEN || strlen(guess) > MAXWORDLEN)
            isValid = false;
        for (i = 0; i < strlen(guess); i++)
        {
            if (!islower(guess[i]))
                isValid = false;
        }

        isWord = false;
        for (i = 0; i < nWords; i++)
        {
            if (strcmp(guess, words[i]) == 0)
                isWord = true;
        }
        if (!isValid)
        {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            score--;
        }
        else if (!isWord)
        {
            cout << "I don't know that word." << endl;
            score--;
        }

        if (isValid && isWord)
        {
            gold = 0;
            silver = 0;

            strcpy(target, words[wordnum]);

            for (i = 0; i < strlen(guess) && i < strlen(words[wordnum]); i++)
            {
                if (target[i] == guess[i])
                {
                    guess[i] = '#';
                    target[i] = '#';
                    gold++;
                }
            }

            for (i = 0; i < strlen(guess); i++)
            {
                for (int j = 0; j < strlen(words[wordnum]); j++)
                {
                    if (guess[i] != '#' && target[j] == (guess[i]))
                    {
                        target[j] = '#';
                        silver++;
                        break;
                    }
                }
            }
        }

        if (gold == strlen(words[wordnum]) && strlen(guess) == strlen(words[wordnum]))
            return score;
        if (isValid && isWord)
            cout << "Golds: " << gold << ", Silvers: " << silver << endl;
    }
}

int main()
{

    char wordList[MAXWORDS][MAXWORDLEN + 1];
    const char WORDFILENAME[] = "/Users/learningcenters/Desktop/Charles Folder/P5/game/word.txt";

    int min = 0, max = 0, rounds = 0, s = 0, num = 0, numberWords = getWords(wordList, MAXWORDS, WORDFILENAME);
    double avg = 0;

    if (numberWords < 1)
        cout << "No words were loaded, so I can't play the game.";

    cout << "How many rounds do you want to play? ";
    cin >> rounds;
    cin.ignore(10000, '\n');
    if (rounds < 0)
    {
        cout << "The number of rounds must be positive.";
        return 0;
    }

    for (int i = 0; i < rounds; i++)
    {
        num = randInt(0, numberWords - 1); // do i have the -1 here?
        cout << "Round " << i + 1 << endl
             << "The hidden word is " << strlen(wordList[num]) << " letters long." << endl;
        s = playOneRound(wordList, numberWords, num);

        if (s == 1)
        {
            cout << "You got it in 1 try." << endl;
        }
        else
        {
            cout << "You got it in " << s << " tries." << endl;
        }
        avg += s;

        if (i == 0)
        {
            min = s;
            max = s;
        }
        else if (s < min)
        {
            min = s;
        }
        else if (s > max)
        {
            max = s;
        }

        cout << "Average: " << fixed << setprecision(2) << avg / (i + 1);
        cout << ", minimum: " << min << ", maximum: " << max << endl;
    }
}
