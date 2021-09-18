/*
 hw01.cpp
 Andrew Tang
 This program will decrypt an encrypted text file
 that has its lowercase letters rotated by a certain
 given number.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*
 This function rotates a single character based on the given distance
 Takes a letter to be changed and a rotation as its parameters
 Returns the rotated character
 */
char rotateChar(const char& letter, const int& dist) {
    //Checks if the rotation can be made without wrapping
    int charAscii = int(letter);
    if (charAscii - dist >= 97 && charAscii - dist <= 122) {
        return char(charAscii - dist);
    }

    //Checks if it will wrap back to z (positive dist value must occur)
    else if (charAscii - dist < 97) {
        int distFromStart = charAscii - 97;

        //Checks if the new character must be wrapped from z
        if ((dist % 26) > distFromStart) {
            int newDist = (dist % 26) - distFromStart;
            return char(123 - newDist);
        }
        //This is for if the net displacement of the character does not require wrapping
        else {
            int newDist = (dist % 26);
            return char(charAscii - newDist);
        }

    }

    //This is for if it will wrap from a (negative dist value must occur)
    else {
        int distFromEnd = 122 - charAscii;

        //Checks if new character must be wrapped from a
        if (-(dist % 26) > distFromEnd) {
            int newDist = -(dist % 26) - distFromEnd;
            return char(96 + newDist);
        }
        //This is for if the net displacement of the character does not require wrapping
        else {
            int newDist = dist % 26;
            return char(charAscii - newDist);
        }
    }

}

/*
 This function Rotates an entire string based on the given dist (uses rotateChar)
 Takes a string to be rotated and a rotation distance as its parameters
 Nothing is returned because the string itself will be altered
 */
void rotateString(string& word, const int& dist) {

    //Rotates each individual letter, assumming it is lowercase
    for (char& letter : word) {
        if (int(letter) >= 97 && int(letter) <= 122) {
            letter = rotateChar(letter, dist);
        }
    }
}

/*
 This function prints out the decrypted text from the last line to the first line
 Takes the vector of decrypted strings as its parameters
 Nothing is returned because the entire decrypted message is printed into the console
 */
void printDecrypted(vector<string>& decrypted){

    //Prints from the last line to the first line, decrementing i by 1 each time
    for (int i = decrypted.size() - 1; i >= 0; i--) {
        cout << decrypted[i] << endl;
    }
}

int main() {
    ifstream encrypted("encrypted.txt");

    string line;
    int dist;
    vector<string> encryptedLines;

    //Initially reads the first integer value to assign dist
    encrypted >> dist;

    //Reads each non-empty line after the rotation value and adds it to a vector of strings
    while (getline(encrypted, line)) {
        if (!line.empty()) {
            encryptedLines.push_back(line);
        }
    }
    encrypted.close();

    //Rotates by each line of encryptedLines
    for (string& elem : encryptedLines) {
        rotateString(elem, dist);
    }

    printDecrypted(encryptedLines);
}
