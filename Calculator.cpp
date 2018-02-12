//
//  Calculator.cpp
//  StackPractice
//
//  Created by David Mancol on 2/11/18.
//  Copyright © 2018 David Mancol. All rights reserved.
//

#include <iostream>
#include "Calculator.h"
using namespace std;

// Main function
int main()
{
    Calculator::stack s;
    s.createHead(0);
    s.push();
    s.push();
    s.show();
    return 0;
}
