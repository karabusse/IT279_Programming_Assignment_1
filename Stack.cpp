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
    void push(char op,int num);
    void pop();
    void display();
};

void stack :: push(char op,int num) //need help
{
    struct Node *newNode=new Node;
    //fill data part
    newNode->op=op;
    newNode->currentValue=num;
    //link part
    newNode->next=top;
    //make newnode as top/head
    top=newNode;
}

void stack ::pop()
{
    if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    cout<<top<<" is removed."<<endl;
    top=top->next;
}

void stack:: display()
{
    if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct Node *temp=top;
    while(temp!=NULL){
        cout<<temp->oldValue<<" ";
        cout<<temp->op<<" ";
        cout<<temp->currentValue<<" ";
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

