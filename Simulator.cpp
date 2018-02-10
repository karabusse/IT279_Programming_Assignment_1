//
// Created by Bronwyn on 2/4/2018.
//
#include <iostream>
#include "QueueSimulator.h"
#include <sstream>
#include <random>

using namespace std;

/**
 * defining main variables for simulator
 */
//the integer x required by the assignment
int maxServiceTime;
//string for temporarily holding input
string tempInput;

/**
 * defining classes of main
 */
//Prints contents of Queue
void printQueueFront(Queue *q);

void simulateDay(int maxTime);


int main() {

    //for test
    Queue* customerTimeQueue = new Queue();

    int input;
    char choice;
    cout << "Enter the Max number of minutes for the customer service Time "<< endl;

    //The following takes in a number and converts it to an integer using string stream
    getline(cin,tempInput);
    stringstream ss(tempInput);
    ss>>maxServiceTime;

    //for real program
    Simulator sim;
    sim.simulateDay(maxServiceTime);







    //Test
    cout<<"Queue Test:"<<endl;

    customerTimeQueue->offer(6, 12);
    customerTimeQueue->offer(18, 12);

    cout<<"Queue Size: "<<customerTimeQueue->getSize();

    cout<<"TestPrint:"<<endl;
    printQueueFront(customerTimeQueue);

    cout<<"Test Poll: "<<customerTimeQueue->poll()<<endl;

    cout<<"TestPrint:"<<endl;
    printQueueFront(customerTimeQueue);
    //End Test

    simulateDay(maxServiceTime);

}

void printQueueFront(Queue *q){

    cout<<"Customer Arrives at: "<<q->peekArrival()<<" Service Time: "<<endl;
}

void Simulator::simulateDay(int maxTime){

    Queue* customerTimeQueue = new Queue();

    //keeps track of the number of customers that go through the service line
    int customerNumber;

    // total time that will be simulated in minutes
    const int TOTAL_TIME_SIMULATED = 720;


    /**
     *      1.	Choose a random integer between 1 and x to determine the minute at which the first customer arrives.
     *      At the first customer’s arrival time:
     *      Print an arrival message;
     *      Determine customer’s service time (random integer from 1 to x);
     *      Begin servicing the customer;
     */
    int firstCustomerArrival = scheduleTime(0,maxTime);

    cout<<"First Customer Arrives at: "<<firstCustomerArrival<<endl;

    int serviceT = scheduleTime(0, maxTime);

    /**
     * Schedule the arrival time of the next customer (random integer 1 to x added to the current time)
     */

    //based on Li's version of this we should generate the whole queue at this point and then cycle through it

    /**
     * 3.	For each subsequent minute of the day:
     *      If the next customer arrives,
     *      Print an arrival message;
     */


    /**
     *      Enqueue the customer;
     *      Schedule the arrival time of the next customer;
     */

    /**
     *      If service was completed for the last customer:
     *      Print a departure message;
     */

     /**
     *      Dequeue the next customer to be serviced;
     *      Determine customer’s service completion time;
     */


    /**
     *    At the end of the simulation, your program must print out the maximum number of customers in the queue at any one time, and the longest wait any one customer experienced.
     */
}


/**
 *  Schedule the arrival time of the next customer;
 *  as well as Determine customer’s service time (random integer from 1 to x);
 * @return random arival time
 */
int Simulator::scheduleTime(int minTime, int maxTime){

    mt19937 mt;//not quite sure what this is honestly
    uniform_int_distribution<int> dist(minTime,maxTime);//distribution for random values

    return dist(mt);
}