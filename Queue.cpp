//
// Created by Bronwyn on 2/4/2018.
//

#include "QueueSimulator.h"

Queue::Queue() {

    front = nullptr;
    rear = nullptr;
    size = 0;
}

/**
 * Adds a new arrival time to the rear of the queue. Arrival refers to the arrival time of a customer
 * @param _arrival
 * should return a boolean value but I'm not that good at what I do
 */
void Queue::offer(int _arrival, int _serviceTime){

    cout<<"Offering Sacrifice to Queue"<<endl;
    //initiate new node with element as arrival
    node *newNode = new node;
    newNode->arrival = _arrival;
    newNode->serviceTime = _serviceTime;
    newNode->next = nullptr;

    /*test
    cout<<"New Node Created"<<endl;

    cout<<"Node Arrival Time: "<<newNode->arrival<<endl;

    cout<<"Rear-null: "<<rear<<endl;
    cout<<"New Node prt: "<<newNode<<endl;
    rear = newNode;//breaking here with Access ...
    cout<<"Rear"<<rear<<endl;
    cout<<"rear = newNode: "<<rear->arrival;
    end test
     */

    //if it's the first node set it to front and rear
    if(front==nullptr){

        newNode->prev = nullptr;

        front = newNode;
        rear = newNode;
    }
    else{
        //if it's not the only node attach it to the rear of the queue
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    //adjust queue size
    size++;
}

/**
 * @return front of the queue arrival value
 */
int Queue::peekArrival(){

    return front->arrival;
}

/**
 * @return front of the queue service time value
 */
int Queue::peekServiceTime(){

    return front->serviceTime;
}

/**
 * @return front nodes arrival time and remove front node.
 */
int Queue::poll(){
    if(front == nullptr){
        cout<<"Empty Queue"<<endl;
    }
    else {
        //save the integer value from the front to return.
        int temp = front->arrival;
        //set the next nodes previous value to null (since the next nodes previous value should be the front if I'm not to dyslexic)
        //front->next->prev = nullptr;
        //set the front to next there by eliminating front (hopefully c++ can garbage collect enough for that)
        front = front->next;

        //adjust queue size
        size--;

        //return value of removed node
        return temp;

    }
}

/**
 * @return the size of the queue
 */
int Queue::getSize() {
    return size;
}
