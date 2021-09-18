//
// Created by asus on 4/29/2021.
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Polynomial {
    friend ostream& operator<<(ostream& os, const Polynomial& poly);
    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
    friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
private:
    struct Node{
        Node(int data = 0, Node* next = nullptr) : data(data), next(next){}
        int data;
        Node* next;
    };
    Node* headptr = nullptr;
    int degree = -1;
public:
    Polynomial();
    Polynomial(const vector<int>& coefficients);
    Polynomial& operator+=(const Polynomial& poly);
    Polynomial(const Polynomial& poly);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& poly);
    const Polynomial operator+(const Polynomial& poly) const;
    int evaluate(int val);
};


#endif
