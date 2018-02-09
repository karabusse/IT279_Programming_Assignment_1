//
//  main.cpp
//  Stack
//
//  Created by David Mancol on 2/2/18.
//  Copyright © 2018 David Mancol. All rights reserved.
//
#include <iostream>
#include "Calculator.h"
using namespace std;

/**
 * creates head - sets oldVal and op to NULL
 * @param currentValue
 */
void Calculator::createHead(int currentValue) {
    struct Node *newNode = new Node;
    newNode->oldValue = 0;
    newNode->op = ' ';
    newNode->currentValue = currentValue;
}

/**
 * pushes op and current into a node with 3 data pieces
 * @param op
 * @param currentValue
 */
void Calculator::push(char op, int currentValue) {
    int temp = top->currentValue;
    struct Node *newNode = new Node;
    newNode->oldValue = temp; //takes current value of previous and makes it oldVal
    newNode->op = op;
    newNode->currentValue = currentValue;

    if(op=='+'){
        int temp = newNode->oldValue + newNode->currentValue;
        newNode->currentValue = temp;
        newNode->oldValue = 0;
        newNode->op = ' ';
    }
    if(op=='-') {
        int temp = newNode->oldValue - newNode->currentValue;
        newNode->currentValue = temp;
        newNode->oldValue = 0;
    }
    if(op=='*') {
        int temp = newNode->oldValue * newNode->currentValue;
        newNode->currentValue = temp;
        newNode->oldValue = 0;
    }
    if(op=='/') {
        int temp = newNode->oldValue - newNode->currentValue;
        newNode->currentValue = temp;
        newNode->oldValue = 0;
    }
    if(op=='%') {
        int temp = newNode->oldValue % newNode->currentValue;
        newNode->currentValue = temp;
        newNode->oldValue = 0;
    }
    //link part
    newNode->next = top;
    //make newnode as top/head
    top = newNode;
}

void Calculator::pop() {
    if (top == 0) {
        cout << "List is empty!" << endl;
        return;
    }
    cout << top << " is removed." << endl;
    top = top->next;
}

int Calculator::getCurrentValue() {
    return top->currentValue;
}

int Calculator::getOldValue() {
    return top->oldValue;
}

char Calculator::getOp() {
    return top->op;
}

void Calculator::display(){
    Node temp = *top;
    cout<<temp.currentValue<<endl;
}
