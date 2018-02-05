//
//  main.cpp
//  Stack
//
//  Created by David Mancol on 2/2/18.
//  Copyright © 2018 David Mancol. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int oldValue;
    char op;
    int currentValue;
    Node *next;
};
Node *top;

class stack{

public:
    void createHead(int currentValue);
    void push(char op,int currentValue);
    void pop();
    int getOldValue();
    int getCurrentValue();
    char getOp();
    string peek();
};

/**
 * creates head - sets oldVal and op to NULL
 * @param currentValue
 */
void stack :: createHead(int currentValue){
    struct Node *newNode=new Node;
    newNode->oldValue=NULL;
    newNode->op=NULL;
    newNode->currentValue=currentValue;
}

/**
 * pushes op and current into a node with 3 data pieces
 * @param op
 * @param currentValue
 */
void stack :: push(char op,int currentValue){
    int temp = head::currentValue;
    struct Node *newNode=new Node;

    newNode->oldValue=temp; //takes current value of previous and makes it oldVal
    newNode->op=op;
    newNode->currentValue=currentValue;
    //link part
    newNode->next=top;
    //make newnode as top/head
    top=newNode;
}

void stack :: pop(){
    if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    cout<<top<<" is removed."<<endl;
    top=top->next;
}

int stack ::getCurrentValue() {

}



//void stack:: display(){
//    if(top==NULL){
//        cout<<"List is empty!"<<endl;
//        return;
//    }
//    struct Node *temp=top;
//    while(temp!=NULL){
//        cout<<temp->oldValue<<" ";
//        cout<<temp->op<<" ";
//        cout<<temp->currentValue<<" ";
//        cout<<endl;
//        temp=temp->next;
//    }
//    cout<<endl;
//}

