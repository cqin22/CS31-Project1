#include "utilities.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Here's a random year from 1990 to 2022: " << randInt(1990, 2022) << endl;
}

// #include <iostream>
// #include "utilities.h"
// #include <cstring>
// using namespace std;

// const char WORDFILENAME[] = "/Users/charlesqin/Desktop/CSP5/word.txt";

// int main()
// {
//     char w[9000][7];
//     int n = getWords(w, 9000, WORDFILENAME);
//     if (n == 2)
//     {
//         cout << "getWords successfully found the file and read its two words." << endl;
//         cout << "You're ready to start working on Project 5." << endl;
//     }
//     else if (n == -1)
//         cout << "The path to your file of words is probably incorrect" << endl;
//     else
//         cout << "getWords found the file, but loaded " << n << " words instead of 2" << endl;
// }

// // const int MAXWORDS = 10000;

// // int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
// // {
// //     if (nWords <= 0 || nWords < 0 || wordnum >= nWords)
// //         return -1;

// //     // const int MAX_VALUE = 999999, ;
// //     char guess[100];
// //     int silver = 0, gold = 0;
// //     bool ans = true;
// //     bool isValid;

// //     while (ans)
// //     {
// //         cout << "Probe word: ";
// //         cin.getline(guess, 100, '\n');

// //         if (strlen(guess) < MINWORDLEN || strlen(guess) > MAXWORDLEN)
// //             isValid = false;
// //         for (int i = 0; i < strlen(guess); i++)
// //             if (!islower(guess[i]))
// //                 isValid = false;
// //         if (!isValid)
// //             cout << "Your probe word must be a word of 4 to 6 lower case letters.";
// //         isValid = true;
// //     }
// // }

// // int main()
// // {

// //     char wordList[MAXWORDS][MAXWORDLEN + 1];
// //     const char WORDFILENAME[] = "/Users/charlesqin/Desktop/CS P5/words.txt";

// //     int rounds = 0, numberWords = getWords(wordList, MAXWORDS, WORDFILENAME);

// //     cout << "How many rounds do you want to play?";
// //     cin >> rounds;

// //     if (rounds < 0)
// //     {
// //         cout << "The number of rounds must be positive.";
// //         return 0;
// //     }

// //     // for(int i = 0; i < rounds; i++) playOneRound(wordList, numberWords, num)
// // }
