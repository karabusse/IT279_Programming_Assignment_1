//
// Created by David Mancol on 2/5/18.
//

#include <iostream>
#include "Calculator.h"
using namespace std;

int main(){
    Calculator* calc = new Calculator();
    cout<<"hi"<<endl;
    calc->createHead(8);
    cout<<"hi"<<endl;
    calc->push('+', 123);
    cout<<"hi"<<endl;
    calc->display();
    cout<<"hi"<<endl;
    cout<<"value equals: " << calc->getCurrentValue()<<endl;
};
