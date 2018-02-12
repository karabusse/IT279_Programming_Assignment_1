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

        previousArrivalTime = customerArrival;
    }


    //set the number of customers to the complete queue.
    customerNumber = customerPool->getSize()+1;

    //get the fist customer exit time and remove them from the queue
    currentCustomerExit = customerQueue->peekArrival() + customerQueue->peekServiceTime();

    /**
     * 3.	For each subsequent minute of the day:
     *      If the next customer arrives,
     *      Print an arrival message;
     */

    cout<<"While Customers are left, loop through service customers"<<endl;
    while (customerPool->getSize() != 0 || customerQueue->getSize() != 0) {

        cout<<"\nPool size: "<<customerPool->getSize()<<"\nQueue Size (minus customer being served): "<<customerQueue->getSize() - 1<<endl;
        serviceCustomers();

    }

    /**
     *    At the end of the simulation, your program must print out the maximum number of customers in the queue at any one time, and the longest wait any one customer experienced.
     */
    cout<<"Customers served today: "<<customerNumber<<endl;
}


/**
 *  Schedule the arrival time of the next customer;
 *  as well as Determine customer’s service time (random integer from 1 to x);
 * @return random arival time
 */
int Simulator::scheduleTime(int minTime, int maxTime){

    int random;
    int range =(maxTime-minTime)+1;
    random = minTime+int(range*rand()/(RAND_MAX +1));


    return random;
}

/**
 * checks the exit time of the current customer and compares it to the arrival time of the next customer.
 * If the next customer arrives sooner, print arrival message. and increment time. Otherwise just print exit
 */
//sorry it's a bit slopy
void Simulator::serviceCustomers(){
    //cout<<"Customer Exit Time: "<<currentCustomerExit<<" Next Customer Arrival: "<<customerPool->peekArrival()<<endl;

    if(customerPool->getSize() <= 0){

        /**
         *      If service was completed for the last customer:
         *      Print a departure message;
         */
        cout<<"Customer Left at: "<<currentCustomerExit;
        /**
         *      Dequeue the next customer to be serviced;
         *      Determine customer’s service completion time;
         */

        if (customerQueue->getSize() > 1){

            cout<<" Serving Next Customer"<<endl;
            currentCustomerExit = currentCustomerExit + customerQueue->peekServiceTime();
        }
        else{
            cout<<"\nLast Customer Served Exiting"<<endl;
        }
        customerQueue->poll();
    }
    else if( currentCustomerExit > customerPool->peekArrival() ){
        //arrival message
        cout<<"\nNext Customer Arrives at: "<<customerPool->peekArrival()<<endl;
        //move customer from the pool to the customers waiting
        customerQueue->offer(customerPool->peekArrival(), customerPool->peekServiceTime());
        customerPool->poll();
    }
    else{
        /**
         *      If service was completed for the last customer:
         *      Print a departure message;
         */
        cout<<"Customer Left at: "<<currentCustomerExit<<" Serving Next Customer"<<endl;
        /**
         *      Dequeue the next customer to be serviced;
         *      Determine customer’s service completion time;
         */
        customerQueue->poll();
        //super gross way to handle it but it might just work

        if (customerQueue->getSize() <= 0) {

            //arrival message
            cout << "\nNext Customer Arrives at: " << customerPool->peekArrival() << endl;

            //move customer from the pool to the customers waiting
            customerQueue->offer(customerPool->peekArrival(), customerPool->peekServiceTime());
            customerPool->poll();

            currentCustomerExit = customerQueue->peekArrival() + customerQueue->peekServiceTime();
        }
        else{
            currentCustomerExit = currentCustomerExit + customerQueue->peekServiceTime();
        }
    }
}

