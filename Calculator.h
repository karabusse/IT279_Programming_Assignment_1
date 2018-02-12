//
//  Calculator.h
//  StackPractice
//
//  Created by David Mancol on 2/11/18.
//  Copyright © 2018 David Mancol. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h
#include <iostream>
using namespace std;

class Calculator{

public:
    //   Creating a NODE Structure
    struct node
    {
        int currentValue;
        char op;
        int oldValue;
        struct node *next;
    };

    // Creating a class STACK
    class stack
    {
    public:
        struct node *top;

        stack() // constructor
        {
            top=nullptr;
        }
        void push(); // to insert an element
        void pop();  // to delete an element
        void show(); // to show the stack
        void createHead(int currentValue);
    };

};

#endif /* Header_h */
