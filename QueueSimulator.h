//
// Created by bhbro on 2/4/2018.
//

#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

class Queue{

private:

    struct node{
        int arrival;//arrival time of the customer to the queue
        node *next;//next refers to the next node starting with the next one after front etc
        node *prev;//previous would refer to the previously added node
    };
    node *front, *rear;


public:
    //initiates front and rear
    Queue();
    //Add an item to the rear of the queue
    boolean offer(int element);
    //Return element at front of queue without removing it.
    int peek();
    //take the item from the front of the queue
    int poll();
};

#endif //LINKEDLIST_QUEUE_H
