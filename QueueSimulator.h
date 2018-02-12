//
// Created by Bronwyn on 2/4/2018.
//

#include <iostream>
using namespace std;

#ifndef LINKEDLIST_QUEUE_H
#define LINKEDLIST_QUEUE_H

class Queue{

private:

    struct node{
        //arrival time of the customer to the queue
        int arrival;
        int serviceTime;
        //next refers to the next node starting with the next one after front etc
        node *next;
        //previous would refer to the previously added node
        node *prev;
    };

    //holds the length of the queue, is changed in offer and poll
    int size;


public:

    //Node pointer for the beginning and end of the queue
    node *front , *rear;

    //initiates front and rear
    Queue();

    //Add an item to the rear of the queue
    void offer(int _arrival,  int _serviceTime);

    //Return arrival of customer at front of queue without removing it.
    int peekArrival();

    int peekServiceTime();

    //take the item from the front of the queue
    int poll();

    //accessor for the size of the queue
    int getSize();
};

class Simulator{

public:

    Queue* customerQueue = new Queue();
    Queue* customerPool = new Queue();


    //keeps track of the number of customers that go through the service line
    int customerTotal = 0;

    int currerntNumOfCustomers = 0;

    //holds the maximum number in the customer queue at any given time
    int maxQueueSize = 0;

    //holds time maximum time a customer has ever waited
    int maxWaitTime = 0;

    //holds the temp value for the last generated customer arrival time
    int customerArrival;

    //holds the previous arrival time to increment the simulation in an organized fashion
    int previousArrivalTime;

    //keep track of when the current customer will leave.
    int currentCustomerExit;

    // total time that will be simulated in minutes
    const int TOTAL_TIME_SIMULATED = 720;

    void simulateDay(int maxServiceTime, int maxTimeBetweenCustomers);

    /**
     *  Schedule the arrival time of the next customer;
     *  as well as Determine customer’s service time (random integer from 1 to x);
     * @return random arival time
     */
    int scheduleTime(int minTime, int maxTime);

    /**
     * compares the arrival time of the next customer vs the exit time of the current customer
     */
    void serviceCustomers();

    //push a customer to the customer queue
    void addToCustomerQueue();

    //calculates if this customer has waited more then the maximum wait time and update maxWaitTime if appropriate
    void calculateWait();
};

#endif //LINKEDLIST_QUEUE_H
