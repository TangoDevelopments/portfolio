#include <iostream>
using namespace std;;

bool playGameBottomUp(int lowerLimit,int upperLimit,int correctNumber){
    int guess;
    int temp;
    if (lowerLimit > upperLimit) {
      temp = lowerLimit;
      lowerLimit = upperLimit;
      upperLimit = temp;
    }
    if (correctNumber > upperLimit || correctNumber < lowerLimit) {
      correctNumber = (lowerLimit + upperLimit) / 2;
    }
    cout << "Guess a number between " << lowerLimit << " and " << upperLimit << ": ";
    cin >> guess;
    if (guess == correctNumber){
        cout << "You got it!" << endl;
        return true;
    }
    else {
        cout << "Sorry, try again." << endl;
        return false;
    }
}

void playGame(int lowerLimit,int upperLimit,int correctNumber){
    bool quit = false;
    string response;

    while (!quit) {
        bool won = playGameBottomUp(lowerLimit,upperLimit,correctNumber);
        if (!won) {
            cout << "Press Q to quit or any other letter to play again: ";
            cin >> response;
            if (response == "Q" || response == "q")
                quit = true;
        }
        else
            quit = true; // won the game, so stop the loop
    }
}

int main() {
  playGame(200, -47, 10);
}
