#include "utilities.h"
#include <iostream>
#include <cstring>
using namespace std;


  const int MAXWORDS = 10000;

  int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
{
      if (nWords <= 0 || nWords < 0 || wordnum >= nWords)
          return -1;
      
      const int MAX_VALUE = 999999;
      char guess[100];
      int silver = 0, gold = 0, score = 0, i = 0;
      bool ans = true;
      bool isValid = true, isWord = false;
      
      while (ans)
      {
          cout << words[wordnum];
          cout << "Probe word: ";
          char guess[100];
          cin.ignore(10000, '\n');
          cin.getline(guess, 105);
          cin.ignore(10000, '\n');
          isValid = true;
          if (strlen(guess) < MINWORDLEN || strlen(guess) > MAXWORDLEN)
              isValid = false;
          for (i = 0; i < strlen(guess); i++){
              if (!islower(guess[i]))
                  isValid = false;
          }
          if (!isValid)
              cout << "Your probe word must be a word of 4 to 6 lower case letters.";
          isWord = false;
          for(i = 0; i < nWords; i++) {
              if(strcmp(guess, words[i]) == 0) isWord = true;
          }
          if(!isWord)  cout << "I don't know that word.";
          
          for(i = 0; i < strlen(guess); i++){
              for(int j = 0; j < strlen(words[wordnum]); j++){
                  if(guess[i] == words[wordnum][i]){
                      gold++;
                      break;
                  }
                  else if(guess[j] == words[wordnum][i]){
                      silver++;
                      break;
                      
                  }
                  
              }
              
          }
          cout << "Golds: " << gold << ", Silvers: " << silver << endl;

      }
      return -1;

  }

  int main()
  {

      char wordList[MAXWORDS][MAXWORDLEN + 1];
      const char WORDFILENAME[] = "/Users/learningcenters/Desktop/Charles Folder/P5/game/word.txt";

      int rounds = 0, num = 0, numberWords = getWords(wordList, MAXWORDS, WORDFILENAME);
      
      if(numberWords < 1) cout << "No words were loaded, so I can't play the game.";

      
      cout << "How many rounds do you want to play?";
      cin >> rounds;

      if (rounds < 0)
      {
          cout << "The number of rounds must be positive.";
          return 0;
      }
      
      num = randInt(0, numberWords-1); //do i have the -1 here?
      
      for(int i = 0; i < rounds; i++) playOneRound(wordList, numberWords, num);
  }
