//
// Created by Frazzlectra on 2/4/2018.
//
#include "QueueSimulator.h"

using namespace std;

void printQueue( Queue* q );

int main() {

    Queue* customerTimeQueue;

    customerTimeQueue->getSize();
    int input;
    char choice;
    cout << "Enter a list of integers in order to add them to the linked list. When you are done entering numbers, enter the letter n"<< endl;
    for (;;) {
        cin >> choice;
        if ( choice != 'n' ) {
            input = atoi( &choice );
            printQueue( customerTimeQueue );
        }
        else {
            break;
        }
    }
    printQueue( customerTimeQueue );

    /*
    int sum = 0;
    double counter = 0;
    node* current = l->head;
    while (current != nullptr) {
        sum += current->data;
        counter++;
        current = current->next;
    }
    cout << "The sum of the list is " << sum << endl;
    cout << "The average of the list is " << (sum / counter) << endl;

    cout << "Enter a value you'd like to delete " << endl;
    cin >> input;
    customerTimeQueue->remove(l->search(input));
    customerTimeQueue->print();
    return 0;

     */
}

void printQueue( Queue* q ){

    for (int i = 0; i < q->getSize(); ++i) {
        //lol this isn't even sort of close to working
        cout<<q->peek();
    }
}
