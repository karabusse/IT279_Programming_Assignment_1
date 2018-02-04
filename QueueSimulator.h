//
// Created by bhbro on 2/4/2018.
//

#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

template <typename X>
class Queue{

private:


public:
    Queue();
    //Add an item to the rear of the queue
    boolean offer(X element);
    //Return element at front of queue without removing it.
    X peek();
    //take the item from the front of the queue
    X poll();
};

#endif //LINKEDLIST_QUEUE_H
