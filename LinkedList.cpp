#include <iostream>
//Linked list class
using namespace std;

struct node{
    char op;
    int oldValue;
    int currentValue;
    node *next;
};

class list{
public:
    node *head, *tail;

    list() {
        head = NULL;
        tail = NULL;
    }

    virtual void add(char op, int value);
    virtual void print();
    virtual void remove(int pos);
    virtual int search(int value);
};

/*
 * Add new node containing x to the head (front) of the list
 */
void list::add(char op, int x) {
    node *temp = new node;
    temp->op = op;
    temp->currentValue=x;
    if (list::head != NULL)
        temp->oldValue=list::head->currentValue;
    temp->next=NULL;
    if(head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        temp->next=head;
        head=temp;
    }
}

/*
 * Return position of number x in the list
 * First node at position 0, second node at position 1, etc.
 * If x is not found in the list, search should return -1
 */
int list::search(int x){
    node *searchNum = nullptr;
    node *temp = new node;
    node *current = new node;
    temp = head;
    current = head;
    int i = 0;
    while(current != NULL && current->currentValue != x){
        temp = current;
        current = current->next;
        i++;
    }
    if(current != NULL) {
        searchNum = current;
        current = current->next;
        return i;
    }
    else{
        return -1;
    }
}

/*
 * Prints the list out
 */
void list::print(){
    node *temp = head;
    while(temp!=NULL) {
        cout << temp->currentValue << "\t";
        temp = temp->next;
    }
    cout << endl;
}

/*
 * Deletes node at specific position
 * If int pos = 0, then the first node in the list is deleted
 * Function does nothing if int pos >= length of list
 */
void list::remove(int pos){
    node *current = head;
    node *previous = new node;
    for(int i = 0; i < pos; i++) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}

/*
 * Prompt user to enter ints, and adds them to linked list (using add function)
 * Print linked list (using print function)
 * Calculate and output sum of elements and average(float)
 *(Must traverse linked list to calculate sum and average)
 * Prompt user for value that should be deleted (using search and remove)
 * Print final linked list
 */

/*
int main() {
    list* l = new list();
    int input;
    char choice;
    cout << "Enter a list of integers in order to add them to the linked list. When you are done entering numbers, enter the letter n"<< endl;
    for (;;) {
        cin >> choice;
        if (choice != 'n') {
            input = atoi(&choice);
            l->add(input);
        }
        else {
            break;
        }
    }
    l->print();

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
    l->remove(l->search(input));
    l->print();
    return 0;
}
 */