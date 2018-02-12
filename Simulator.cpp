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

//the different integer x for the time between customers
int maxTimeBetweenCustomers;

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
   // Queue* customerTimeQueue = new Queue();

    int input;
    char choice;
    cout << "Enter the Max number of minutes for the customer service Time "<< endl;

    //The following takes in a number and converts it to an integer using string stream
    getline(cin,tempInput);
    stringstream ss(tempInput);
    ss>>maxServiceTime;


    cout << "Enter the Max number of minutes between customers "<< endl;

    //The following takes in a number and converts it to an integer using string stream
    getline(cin,tempInput);
    stringstream ss2(tempInput);
    ss2>>maxTimeBetweenCustomers;


    //for real program
    Simulator sim;
    sim.simulateDay(maxServiceTime, maxTimeBetweenCustomers);


    /*Test
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
    */

}

void printQueueFront(Queue *q){

    cout<<"Customer Arrives at: "<<q->peekArrival()<<" Service Time: "<<endl;
}

void Simulator::simulateDay(int maxServiceTime, int maxTimeBetweenCustomers){

    /**
     *      1.	Choose a random integer between 1 and x to determine the minute at which the first customer arrives.
     *      At the first customer’s arrival time:
     *      Print an arrival message;
     *      Determine customer’s service time (random integer from 1 to x);
     *      Begin servicing the customer;
     */
    customerArrival = scheduleTime(0, maxTimeBetweenCustomers);

    previousArrivalTime = customerArrival;
    cout<<"First Customer Arrives at: "<<customerArrival<<endl;
    currerntNumOfCustomers++;
    maxQueueSize++;

    int serviceTime = scheduleTime(0, maxServiceTime);
    customerQueue->offer(customerArrival, serviceTime);
    /**
     * Schedule the arrival time of the next customer (random integer 1 to x added to the current time)
     */

    while(customerArrival < TOTAL_TIME_SIMULATED){

        /**
         *      Enqueue the customer;
         *      Schedule the arrival time of the next customer;
         */
        // generate arrival times
        int temp = previousArrivalTime + maxTimeBetweenCustomers;

        //make sure customers aren't arriving after we close
        if(temp > TOTAL_TIME_SIMULATED){

            customerArrival = scheduleTime(previousArrivalTime,TOTAL_TIME_SIMULATED);
        }
        else{
            customerArrival = scheduleTime(previousArrivalTime,temp);
        }


        serviceTime = scheduleTime(0, maxServiceTime);

        //add new customer to queue
        //cout<<"New Customer Arrival Time: "<<customerArrival<<" New Customer Service Time: "<<serviceTime<<endl;
        customerPool->offer(customerArrival, serviceTime);

        //sets the previous arrival time so customers wont arrive before the previous customer arrived
        previousArrivalTime = customerArrival;
    }


    //set the number of customers to the complete queue.
    customerTotal = customerPool->getSize()+1;

    //get the fist customer exit time and remove them from the queue
    currentCustomerExit = customerQueue->peekArrival() + customerQueue->peekServiceTime();

    /**
     * 3.	For each subsequent minute of the day:
     *      If the next customer arrives,
     *      Print an arrival message;
     */
    while (customerPool->getSize() != 0 || customerQueue->getSize() != 0) {

        cout<<"\nPool size: "<<customerPool->getSize()<<"\nQueue Size (minus customer being served): "<<customerQueue->getSize() - 1<<endl;

        //loops through checks to see when customers come and go
        serviceCustomers();
    }

    /**
     *    At the end of the simulation, your program must print out the maximum number of customers in the queue at any one time, and the longest wait any one customer experienced.
     */
    cout<<"\nCustomers served today: "<<customerTotal<<"\nMax Size of Queue: "<<maxQueueSize<<"\nMax Time a Customer Waited: "<<maxWaitTime<<endl;
}


/**
 *  Schedule the arrival time of the next customer;
 *  as well as Determine customer’s service time (random integer from 1 to x);
 * @return random arival time
 */
int Simulator::scheduleTime(int minTime, int maxTime){

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(minTime, maxTime);

    int random = dis(gen);

    return random;
}

/**
 * checks the exit time of the current customer and compares it to the arrival time of the next customer.
 * If the next customer arrives sooner, print arrival message. and increment time. Otherwise just print exit
 */
//sorry it's a bit sloppy
void Simulator::serviceCustomers(){
    //cout<<"Customer Exit Time: "<<currentCustomerExit<<" Next Customer Arrival: "<<customerPool->peekArrival()<<endl;

    //prevents it from breaking at customerPool->peekArrival();
    if(customerPool->getSize() <= 0){

        //no more customers arriving, next customer leaves
        cout<<"Customer "<<currerntNumOfCustomers<<" Left at: "<<currentCustomerExit;
        /**
         *      Dequeue the next customer to be serviced;
         *      Determine customer’s service completion time;
         */

        if (customerQueue->getSize() > 1){

            cout<<" Serving Next Customer"<<endl;

            customerQueue->poll();

            //check to see if this customers wait time is greater then the maximum wait time
            calculateWait();

            currentCustomerExit = currentCustomerExit + customerQueue->peekServiceTime();

            //increment customer # served
            currerntNumOfCustomers++;

        }
        else{
            cout<<"\nLast Customer Served Exiting"<<endl;

            customerQueue->poll();
        }

    }
    else if( currentCustomerExit > customerPool->peekArrival() ){

        addToCustomerQueue();
    }
    else{
        /**
         *      If service was completed for the last customer:
         *      Print a departure message;
         *
         *      Dequeue the next customer to be serviced;
         *      Determine customer’s service completion time;
         *
         */
        cout<<"Customer "<<currerntNumOfCustomers<<" Left at: "<<currentCustomerExit<<" Serving Next Customer"<<endl;

        customerQueue->poll();

        //customer queue is empty therefore we need to wait till the next customer arrives
        if (customerQueue->getSize() <= 0){

            addToCustomerQueue();
            //update exit time to new customer
            currentCustomerExit = customerQueue->peekArrival() + customerQueue->peekServiceTime();
        }
        else{

            //check to see if this customers wait time is greater then the maximum wait time
            calculateWait();

            //get exit time
            currentCustomerExit = currentCustomerExit + customerQueue->peekServiceTime();
        }
        currerntNumOfCustomers++;
    }
}

void Simulator::addToCustomerQueue(){
    //arrival message
    cout << "\nNext Customer Arrives at: " << customerPool->peekArrival() << endl;

    //move customer from the pool to the customers waiting
    customerQueue->offer(customerPool->peekArrival(), customerPool->peekServiceTime());
    customerPool->poll();

    if(customerQueue->getSize() > maxQueueSize){
        maxQueueSize = customerQueue->getSize();
    }

}


//calculates if this customer has waited more then the maximum wait time and update maxWaitTime if appropriate
void Simulator::calculateWait(){

    //get max wait time of waiting customer
    if(maxWaitTime < currentCustomerExit - customerQueue->peekArrival()){

        maxWaitTime = currentCustomerExit - customerQueue->peekArrival();
    }
}

