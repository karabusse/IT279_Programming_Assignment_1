//
// Created by bhbro on 2/4/2018.
//

#include <iostream>
#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

class Queue{

private:

    struct node{
        int arrival;//arrival time of the customer to the queue
        node *next;//next refers to the next node starting with the next one after front etc
        node *prev;//previous would refer to the previously added node
    };

    //Node pointer for the beginning and end of the queue
    node *front, *rear;

    //holds the length of the queue, is changed in offer and poll
    int size;



public:
    //initiates front and rear
    Queue();
    //Add an item to the rear of the queue
    void offer(int element);
    //Return element at front of queue without removing it.
    int peek();
    //take the item from the front of the queue
    int poll();

    //accessor for the size of the queue
    int getSize();
};

#endif //LINKEDLIST_QUEUE_H
