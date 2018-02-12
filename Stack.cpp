//
//  main.cpp
//  StackPractice
//
//  Created by David Mancol on 2/11/18.
//  Copyright © 2018 David Mancol. All rights reserved.
//

#include <iostream>
#include "Calculator.h"
using namespace std;

void Calculator::stack::createHead(int currentValue) {
    struct node *ptr = new node;
    ptr->oldValue = 0;
    ptr->op = ' ';
    ptr->currentValue = currentValue;
    top=ptr;
}

// PUSH Operation
void Calculator::stack::push()
{
    int temp = top->currentValue; //set temp to current top value
    top->oldValue=temp; //sets previous current value to old value

    char op;
    int currentValue;

    struct node *ptr;
    int temp1=0;
    int temp2=0;
    int temp3=0;

    //prompt
    cout<<"\nPUSH Operation";
    cout<<"Enter an operation followed by an integer: ";

    //input values by typing
    cin>>op;
    cin>>currentValue;

    //operations
    if(ptr->op=='+'){
        cout<<"hi"<<endl;
        temp1 = ptr->oldValue;
        temp2 = ptr->currentValue;
        temp3 = temp1+temp2;
        ptr->currentValue = temp3;
        ptr->oldValue = 0;
        ptr->op = ' ';
        top=ptr;
    }

    ptr=new node;
    ptr->currentValue=currentValue;
    ptr->op=op;
    ptr->next=NULL;
    if(top!=NULL){
        ptr->next=top;
    }
    top=ptr;
    cout<<"\nNew item is inserted to the stack!!!";

}

// POP Operation
void Calculator::stack::pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"\nThe stack is empty!!!";
    }
    temp=top;
    top=top->next;
    cout<<"\nPOP Operation........\nPoped value is "<<temp->currentValue;
    delete temp;
}

// Show stack
void Calculator::stack::show()
{
    struct node *ptr1=top;
    cout<<"\nThe stack is\n";
    while(ptr1!=NULL)
    {
        cout<<ptr1->currentValue<<" ->";
        ptr1=ptr1->next;
    }
    cout<<"NULL\n";
}

