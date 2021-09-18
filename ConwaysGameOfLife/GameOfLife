//Andrew Tang
//rec02.cpp
/*This is an implementation of Conway's Game of Life, showing the next 10 generations
 * given the life.txt file as the initial world.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int countNeighbors(const vector<string>& world, int row, int col);

void makeWorld(vector<string>& world, ifstream& stream) {
    stream.open("life.txt");
    string lineOfCells;
    while (getline(stream, lineOfCells)) {
        world.push_back(lineOfCells);
    }
    stream.close();
}

void displayWorld(const vector<string>& world) {
    for (const string& s : world) {
        cout << s << endl;
    }
    cout << "===========================" << endl;
}

vector<string> nextGen(const vector<string>& currGen) {
    vector<string> result;
    for (string s : currGen) {
        result.push_back(s);
    }
    for (int row = 0; row < currGen.size(); row++) {
        for (int col = 0; col < currGen[0].size(); col++) {
            char cell = currGen[row][col];
            int neighbors = countNeighbors(currGen, row, col);
            if (cell == '*') {
                if (neighbors  != 2 && neighbors != 3) {
                    result[row][col] = '-';
                }
            }
            else {
                if (neighbors == 3) {
                    result[row][col] = '*';
                }
            }
        }
    }
    return result;

}

int countNeighbors(const vector<string>& world, int row, int col) {
    int result = 0;
    int rowMax = world.size();
    int colMax = world[0].size();
    vector<string> newWorld;
    string emptyRow = "";
    for (int i = 0; i < colMax; i++) {
        emptyRow.push_back('-');
    }
    newWorld.push_back(emptyRow);
    for (int i = 0; i < rowMax ; i++) {
        string newRow = "-" + world[i] + "-";
        newWorld.push_back(newRow);
    }
    newWorld.push_back(emptyRow);
    row++;
    col++;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            else if (newWorld[row + i][col + j] == '*') {
                result++;
            }
        }
    }
    return result;
}

int main() {
    vector<string> world;
    ifstream initialWorld;
    makeWorld(world, initialWorld);

    cout << "Initial World:" << endl;
    displayWorld(world);
    for (int i = 1; i < 11; i++) {
        world = nextGen(world);
        cout << "Generation: " << i << endl;
        displayWorld(world);
    }
}
