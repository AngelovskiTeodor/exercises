#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int MAX_ERRORS = 5;

class Hangman {
private:
    string word;
    int errors;
    vector <bool> guessedLetters;
public:
    Hangman(string word = "") {
        this->word = word;
        errors = 0;
        guessedLetters = vector<bool>(word.size(), false);
    }
    bool checkLetter(const char letter) {
        bool guess = false;
        int n = word.size();
        for (int i=0; i<n; i++) {
            char currentLetter = word[i];
            if (currentLetter == letter) {
                guess = true;
                guessedLetters[i] = true; }
        }
        if (!guess) { ++errors; }
        return guess;
    }
    bool isWon() const {
        int n = word.size();
        for (int i=0; i<n; i++) {
            if (guessedLetters[i] == false) {
                return false;
            }
        }
        return true;
    }
    bool isGameOver() const {
        bool ret = errors >= MAX_ERRORS;
        return ret; }
    bool isFinished() const { return (isWon()) || (isGameOver()); }
    string getWordStateString() const {
        int n = word.size();
        stringstream ss;
        for (int i=0; i<n; i++) {
            ss << ((guessedLetters[i]) ? (word[i]) : ('-'));
        }
        string ret = ss.str();
        return ret;
    }
    friend ostream& operator<<(ostream& os, const Hangman& game) {
        os << MAX_ERRORS-game.errors << " errors remaining: " << game.getWordStateString() << endl;
        return os;
    }
};

int main()
{
    Hangman game = Hangman("programiranje");
    char letter;
    while (!game.isFinished()) {
        cout << game;
        cout << "Guess a letter: ";
        cin >> letter;
        game.checkLetter(letter);
    }
    if (game.isWon()) {
        cout << game << "Congratulations!!! You have guessed the word correctly." << endl;
    }
    else {
        cout << game << "You have made way to many wrong guesses. Try again." << endl;
    }
    cout << "" << endl;
    return 0;
}
