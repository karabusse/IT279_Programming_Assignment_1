//
// Created by David Mancol on 2/5/18.
//

#ifndef LINKEDLIST_CALCULATOR_H
#define LINKEDLIST_CALCULATOR_H
#include <iostream>
using namespace std;


class Calculator {
public:

    struct Node {
        int oldValue;
        char op;
        int currentValue;
        Node *next;
    };
    Node *top;

    Calculator() {
        top = 0;
    }

    void createHead(int currentValue);
    void push(char op, int currentValue);
    void pop();
    int getOldValue();
    int getCurrentValue();
    char getOp();

    void display();
};


#endif //LINKEDLIST_CALCULATOR_H

