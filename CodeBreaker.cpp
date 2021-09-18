#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty) {
    cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room..." << endl;
    cout << "Enter the correct code to continue" << endl;
}

bool PlayGame(int Difficulty) {
    //Introduction
    PrintIntroduction(Difficulty);

    //Assigning three numbers
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //Creating sums and products
    const int Sum = CodeA + CodeB + CodeC;
    const int Product = CodeA * CodeB * CodeC;

    //Presenting the Sum and product to the user
    cout << "\n---------------------------------------------" << endl;
    cout << "\nThere are three numbers in the code" << endl;
    cout << "The numbers add up to: " << Sum << endl;
    cout << "The numbers multiply to: " << Product << endl;

    //Asking for the user's input
    int GuessA, GuessB, GuessC;
    cin >> GuessA;
    cin >> GuessB;
    cin >> GuessC;

    //creating the user's Sum and Product based on their input values
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Checks if the user's guess is correct
    cout << "\n---------------------------------------------" << endl;
    if (GuessSum == Sum && GuessProduct == Product) {
        cout << "\nThe code was correct! Congratulations!" << endl;
        return true;
    }
    else {
        cout << "\nThe code was incorrect and you died in a horrible explosion" << endl;
        return false;
    }
    
}

int main() {
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) {
        bool LevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); //Clears errors
        cin.ignore(); //Discards buffer

        if (LevelComplete) {
            //Increase level difficulty
            LevelDifficulty++;
        }
    }
    return 0;
}
