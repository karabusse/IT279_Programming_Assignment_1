//
// Created by David Mancol on 2/5/18.
//

#ifndef LINKEDLIST_CALCULATOR_H
#define LINKEDLIST_CALCULATOR_H


class Calculator {
    class stack{

    public:
        void createHead(int currentValue);
        void push(char op,int currentValue);
        void pop();
        int getOldValue();
        int getCurrentValue();
        char getOp();

        string peek();
    };

};

#endif //LINKEDLIST_CALCULATOR_H
