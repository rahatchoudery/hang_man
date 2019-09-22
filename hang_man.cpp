#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;

//function defintions
void  PrintLetters (vector <char> a) { //print out letters the user gets right or wrong
   for (unsigned i = 0; i < a.size(); ++i) {
      cout << a.at(i) << " ";
    }
 }

bool Check (vector <char> b) {
   for (unsigned i = 0; i < b.size(); ++i) { //check whether a character is a blank space or not
      if (b.at(i) == '_') {
         return false;
      }
    }
    return true;
  }
 
bool PlayGame () {
string words[10] = {"spring", "bloom", "flowers", "rabbit", "blossoming", "pastel", "showers", "sunshine", "rainbow", "butterfly" };

srand(time(NULL));
int temp = rand() % 10; //pick random number from 0-9

string picked = words[temp]; //the word that is randomly picked

vector <char> letters; //vector that holds each individual letter of the word

for (unsigned i = 0; i < picked.size(); ++i) { //vector of letters in random word
    letters.push_back(picked[i]);
    }
   
 char input; //the character that user guesses

 vector <char> correct; //vector holding the correct letters guessed by user
 vector <char> wrong; //vector holding the incorrect letters guessed by user
 vector <char> location(letters.size()); //vector that will be used to check the location of each letter in word
 
 for (unsigned i = 0; i < location.size(); ++i) { //starts words with all dashes
    location.at(i) = '_';
 }

int chances = 10; //user has 10 chances to begin with

while (chances > 0) {
   bool RorW = false; //RorW stands for "Right or Wrong"
   //int score = 0;
   cout << "You have " << chances << " tries left." << endl;
   cout << "Pick a letter:" << endl;
   cin >> input;
   
   for (unsigned i = 0; i < letters.size(); ++i) {
           if (input == letters.at(i)) { //if the letter is in the word, RorW is true
             cout << input << " is correct!" << endl;
             correct.push_back(input); //add correct letter to vector
             RorW = true;
             location.at(i) = input; //put the correct letter in the right spot in the word
          }
        }
        
        if (RorW == false) { //if letter is not in word
           cout << input << " is incorrect!" << endl;  
           wrong.push_back(input); // add wrong letters to vector
           chances = chances - 1; //decrease user's tries by 1 everytime they guess incorrectly
        }
        
      cout << "Word Progress: "; //print out correct letters in the order they are guessed
      PrintLetters(correct);
      cout << endl;
      
      cout << "Incorrect letters: "; //print incorrect letters in the order they are guessed
      PrintLetters(wrong);
      cout << endl;
      
      cout << "Blank Spaces: "; //print out correct letters in the order of the word
      PrintLetters(location); 
      cout << endl;
      
      
      bool temp = true; 
      if (Check(location) == temp) { //check if all letters have been guessed (there are no dashes remaining)
         cout << "You guessed it! The word was " << picked << ". Good job!" << endl;
         return true;
      }        
}
   cout << "You lost :( The word was " << picked << "." << endl; //user ran out of tries
   return false;
}


//main starts here
int main() {
cout << "Welcome to Hangman!" << endl;
cout << "Enter one letter at a time until you guess the hidden word correctly. You have 10 incorrect guesses before you lose!" << endl;
int score = 0;

if (PlayGame()) { //add 1 point to score if game returns true (person wins game)
   score ++ ;
}

cout << "Your score is: " << score << endl;
cout << "Would you like to play again? Type yes or no." << endl;

string answer;
cin >> answer;

while (answer == "yes") { //keep playing the game while player answers "yes"
   if (PlayGame()) {
   score ++ ;
   cout << "Your score is: " << score << endl;
   }
   
   cout << "Would you like to play again? Type yes or no." << endl;
   cin >> answer;
   
   } 
}
