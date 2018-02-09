//
// Created by Frazzlectra on 2/4/2018.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class list{

public:
    node *head, *tail;

    list() {
        head = NULL;
        tail = NULL;
    }

    virtual void add(char op, int value);
    virtual void print();
    virtual void remove(int pos);
    virtual int search(int value);
};

#endif //LINKEDLIST_H
