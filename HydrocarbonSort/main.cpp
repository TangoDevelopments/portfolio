/*
 Andrew Tang
 This is a program that takes and sorts a text file of different hydrocarbons.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Molecule {
    vector<string> names;
    int numCarb;
    int numHydro;
};

void fillVector(vector<Molecule>& molecules, ifstream& stream);

void sortMolecules(vector<Molecule>& molecules);

void insertInfo(const string& name, const vector<int>& formula, vector<Molecule>& molecules);

size_t locateFormula(const vector<Molecule>& molecules, const vector<int>& formula);

void openStream(ifstream& stream);

void swap(vector<Molecule>& molecules, int i, int j);

void printMolecules(const vector<Molecule>& molecules);

void printFormula(const Molecule& m);

int main() {
    vector<Molecule> test;
    ifstream stream;
    openStream(stream);
    fillVector(test, stream);
    stream.close();
    sortMolecules(test);
    printMolecules(test);
}

void openStream(ifstream& stream) {
    string fileName;
    cout << "enter a file name:" << endl;
    cin >> fileName;
    stream.open(fileName);
    while (!stream) {
        stream.clear();
        cout << "Please re-enter a file name:" << endl;
        cin >> fileName;
        stream.open(fileName);
    }
}

void fillVector(vector<Molecule>& molecules, ifstream& stream) {
    vector<vector<int>> formulas;
    vector<vector<string>> names;
    string name;
    while (stream >> name) {
        char C;
        stream >> C;
        int cNum;
        stream >> cNum;
        char H;
        stream >> H;
        int hNum;
        stream >> hNum;
        vector<int> currFormula{cNum, hNum};
        insertInfo(name, currFormula, molecules);
    }

}

void insertInfo(const string& name, const vector<int>& formula, vector<Molecule>& molecules) {
    size_t index = locateFormula(molecules, formula);
    if (index == molecules.size()) {
        Molecule mol;
        mol.names = vector<string>{name};
        mol.numCarb = formula[0];
        mol.numHydro = formula[1];
        molecules.push_back(mol);
    }
    else {
        molecules[index].names.push_back(name);
    }
}

size_t locateFormula(const vector<Molecule>& molecules, const vector<int>& formula) {
    for (size_t i = 0; i < molecules.size(); i++) {
        vector<int> molFormula{molecules[i].numCarb, molecules[i].numHydro};
        if (formula == molFormula) {
            return i;
        }
    }
    return molecules.size();
}

void sortMolecules(vector<Molecule>& molecules) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (size_t i = 0; i < molecules.size() - 1; i++) {
            if (molecules[i].numCarb > molecules[i + 1].numCarb) {
                swap(molecules, i, i + 1);
                swapped = true;
            }
            else if (molecules[i].numCarb == molecules[i + 1].numCarb && molecules[i].numHydro > molecules[i + 1].numHydro) {
                swap(molecules, i, i + 1);
                swapped = true;
            }
        }
    }
}

void swap(vector<Molecule>& molecules, int i, int j) {
    Molecule temp = molecules[i];
    molecules[i] = molecules[j];
    molecules[j] = temp;
}

void printMolecules(const vector<Molecule>& molecules) {
    for (const Molecule& m : molecules) {
        printFormula(m);
    }
}

void printFormula(const Molecule& m) {
    cout << "C" << m.numCarb << "H" << m.numHydro << " ";
    if (m.names.size() > 1) {
        for (const string& s : m.names) {
            cout << s << " ";
        }
        cout << endl;
    }
    else {
        cout << m.names[0] << endl;
    }
}
