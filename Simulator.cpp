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

    Queue* customerTimeQueue = new Queue();

    int input;
    char choice;
    cout << "Enter the Max number of minutes for the customer service Time "<< endl;

    //The following takes in a number and converts it to an integer using string stream
    getline(cin,tempInput);
    stringstream ss(tempInput);
    ss>>maxServiceTime;

    //Test
    cout<<"Test:"<<endl;

    customerTimeQueue->offer(6);
    customerTimeQueue->offer(18);

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

    cout<<q->peek()<<endl;
}

void simulateDay(int maxTime){
    // total time that will be simulated in minutes
    const int TOTAL_TIME_SIMULATED = 720;

    mt19937 mt;//not quite sure what this is honestly
    uniform_int_distribution<int> dist(0,maxTime);//distribution for random values
    int firstCustomerArrival = dist(mt);

    cout<<"First Customer Arrives at: "<<firstCustomerArrival<<endl;

}