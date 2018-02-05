//
// Created by bhbro on 2/4/2018.
//

#include "QueueSimulator.h"
#include "LinkedList.h"

//initiate Queue Head and Tail ie Front and Rear
Queue::Queue(){
    front = NULL;
    rear = NULL;
}
/**
 *
 * @param _arrival refers to the arrival time of a customer
 * should return a boolean value but I'm not that good at what I do
 *
 */
void Queue::offer(int _arrival){

    //initiate new node with element as arrival
    node *newNode = new node;
    newNode->arrival = _arrival;
    //if it's the first node set it to front and rear
    if(front == NULL & rear == NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        front = newNode;
        rear = newNode;
        newNode = NULL;
    }
    else{
        //if it's not the only node attach it to the rear of the queue
        newNode->next = NULL;
        newNode->prev = rear;
        rear->next = newNode;
        rear->newNode;
    }

}

/**
 * @return front of the queue arrival value
 */
int Queue::peek(){

    return front->arrival;
}

/**
 * @return front nodes arrival time and removing fornt node.
 */
int Queue::poll(){
    //save the integer value from the front to return.
    int temp = front->arrival;
    //set the next nodes previous value to null (since the next nodes previous value should be the front if I'm not to dyslexic)
    front->next->prev = Null;
    //set the front to next there by eliminating front (hopefully c++ can garbage collect enough for that)
    front = front->next;

    //return temp
    return arrival;
}