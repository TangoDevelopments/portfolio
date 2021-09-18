#include "Polynomial.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


//Friend functions

//output operator for Polynomial class
ostream& operator<<(ostream& os, const Polynomial& poly) {
    if (poly.degree < 0) {
        os << 0;
        return os;
    }
    else if (poly.degree == 0) {
        Polynomial::Node* cursor = poly.headptr;
        while (cursor->data == 0) {
            cursor = cursor->next;
        }
        os << cursor->data;
        return os;
    }
    else {
        Polynomial::Node* cursor = poly.headptr;
        int degreeCount = poly.degree;
        while(degreeCount > 1) {
            if (cursor->data == 1) {
                os << "x^" << degreeCount << " + ";
            }
            else if (cursor->data != 0) {
                os << cursor->data << "x^" << degreeCount << " + ";
            }
            --degreeCount;
            cursor = cursor->next;
        }
        if (cursor->data == 1) {
            cout << "x";
        }
        else if (cursor->data != 0) {
            os << cursor->data << "x";
        }
        if ((cursor->next->data != 0) && cursor->data != 0) {
            os << " + " << cursor->next->data;
        }
        else if (cursor->next->data != 0) {
            cout << cursor->next->data;
        }
        return os;
    }
}

//equality operator
bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    if (lhs.degree != rhs.degree) {
        return false;
    }
    Polynomial::Node* leftCursor = lhs.headptr;
    Polynomial::Node* rightCursor = rhs.headptr;

    //first checks if there are any leading zeros that can be disregarded
    while (leftCursor != nullptr) {
        if (leftCursor->data == 0) {
            leftCursor = leftCursor->next;
        }
        else {
            break;
        }
    }
    while (rightCursor != nullptr) {
        if (rightCursor->data == 0) {
            rightCursor = rightCursor->next;
        }
        else {
            break;
        }
    }
    while (leftCursor != nullptr || rightCursor != nullptr) {
        if (leftCursor->data != rightCursor->data) {
            return false;
        }
        leftCursor = leftCursor->next;
        rightCursor = rightCursor->next;
    }
    return true;
}

//inequality operator
bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
    return !(lhs == rhs);
}

//Member functions:
Polynomial::Polynomial() {}

Polynomial::Polynomial(const vector<int>& coefficients) {
    if (!coefficients.empty()) {
        size_t startInd = 0;
        //checks for leasing zeros to be disregarded
        for (size_t i = 0; i < coefficients.size(); i++) {
            if (coefficients[i] == 0) {
                ++startInd;
            }
            else {
                break;
            }
        }
        //sets headpointer to the first nonzero coefficient
        //and links the rest
        for (size_t i = startInd; i < coefficients.size(); i++) {
            if (i == startInd) {
                headptr = new Node(coefficients[i]);
            }
            else {
                Node* cursor = headptr;
                while(cursor->next != nullptr) {
                    cursor = cursor->next;
                }
                cursor->next = new Node(coefficients[i]);
            }
            ++degree;
        }
    }
}

//copy constructor
Polynomial::Polynomial(const Polynomial& poly) : degree(poly.degree){
    headptr = new Node(poly.headptr->data);
    Node* cursor = headptr;
    Node* otherCursor = poly.headptr;
    //copies the data of poly into the new linked list
    while (otherCursor != nullptr) {
        if (otherCursor->next == nullptr) {
            cursor->next = nullptr;
        }
        else {
            cursor->next = new Node(otherCursor->next->data);
        }
        otherCursor = otherCursor->next;
        cursor = cursor->next;
    }
}


//destructor
Polynomial::~Polynomial() {
    Node* current = headptr;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    headptr = nullptr;
}

//assignment operator
Polynomial& Polynomial::operator=(const Polynomial& poly) {
    if (*this != poly) {
        //first deletes linked list
        Node* current = headptr;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        //copies the head of poly
        headptr = new Node(poly.headptr->data);
        Node* cursor = headptr;
        Node* otherCursor = poly.headptr->next;
        //links new copies of each node
        while (otherCursor != nullptr) {
            cursor->next = new Node(otherCursor->data);
            cursor = cursor->next;
            otherCursor = otherCursor->next;
        }
        degree = poly.degree;
    }
    return *this;
}

//+= operator
Polynomial& Polynomial::operator+=(const Polynomial& poly) {
    if (degree >= poly.degree) {
        int degreeDiff = degree - poly.degree;
        Node* cursor = headptr;

        //sets cursor to where the two polynomials have the same degree
        for (size_t i = 0; i < degreeDiff; i++) {
            cursor = cursor->next;
        }
        Node* otherCursor = poly.headptr;
        int degreeCounter = poly.degree;
        bool firstRun = true;
        //runs through headptr and poly's headptr add the nodes together
        //if it's the first run, makes sure that the first term is not a zero
        while (degreeCounter > -1) {
            cursor->data += otherCursor->data;
            if (firstRun && cursor->data == 0) {
                --degree;
            }
            else {
                firstRun = false;
            }
            cursor = cursor->next;
            otherCursor = otherCursor->next;
            --degreeCounter;
        }
    }
    else {
        int degreeDiff = poly.degree - degree;
        //adds dummy nodes to the front of the list to make the degree the same
        for (int i = 0; i < degreeDiff; i++) {
            Node* temp = headptr;
            headptr = new Node(0, temp);
        }
        degree = poly.degree;
        Node* cursor = headptr;
        Node* otherCursor = poly.headptr;
        bool firstRun = true;
        //uses for loop instead of while loop; same functionality though
        for (int i = 0; i < degree + 1; i++) {
            cursor->data += otherCursor->data;
            if (firstRun && cursor->data == 0) {
                --degree;
            }
            else {
                firstRun = false;
            }
            cursor = cursor->next;
            otherCursor = otherCursor->next;
        }
    }
    return *this;
}

//+ operator uses += on a copy
const Polynomial Polynomial::operator+(const Polynomial& poly) const {
    Polynomial result = *this;
    result += poly;
    return result;
}

//evaluate
int Polynomial::evaluate(int val) {
    if (degree > -1) {
        int result = 0;
        Node* cursor = headptr;
        int degreeCounter = degree;
        //adds val^degree multiplied by the coefficient
        while (cursor->next != nullptr) {
            result += ((cursor->data) * pow(val, degreeCounter));
            --degreeCounter;
            cursor = cursor->next;
        }
        //adds the final zeroth degree term
        result += cursor->data;
        return result;
    }
    else {
        //returns 0 if the polynomial is empty
        return 0;
    }

}
