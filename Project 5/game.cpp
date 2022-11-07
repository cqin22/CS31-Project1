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
      bool isValid = true, isWord = false, g = false, s = false;
      
      while (true)
      {
          cout << words[wordnum];
          cout << "Probe word: ";
          char guess[100];
          cin >> guess;
          score++;
//          cin.ignore(10000, '\n');
//          cin.getline(guess, 105);
//          cin.ignore(10000, '\n');
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
          if(!isWord)  cout << "I don't know that word." << endl;
          
          gold = 0;
          silver = 0;
          
          
          for(i = 0; i < strlen(guess); i++){
              g = false;
              s = false;
              for(int j = 0; j < strlen(words[wordnum]) && g != true && s != true; j++){
                  if(guess[i] == words[wordnum][i]){
                      gold++;
                      g = true;
                  }
                  else if(guess[j] == words[wordnum][i]){
                      silver++;
                      break;
                  }
                  
              }
              
          }
          if(gold == strlen(words[wordnum]) && strlen(guess) == strlen(words[wordnum]) && score ==1){
              cout << "You got it in 1 try." << endl;
              return score;
          }
          else if(gold == strlen(words[wordnum]) && strlen(guess) == strlen(words[wordnum])){
              cout << "You got it in " << score <<" tries." << endl;
              return score;
          }
          cout << "Golds: " << gold << ", Silvers: " << silver << endl;

      }
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
      
      
      for(int i = 0; i < rounds; i++){
          num = randInt(0, numberWords-1); //do i have the -1 here?
          playOneRound(wordList, numberWords, num);
      }
  }
