////
////  Calculator.cpp
////  StackPractice
////
////  Created by David Mancol on 2/11/18.
////  Copyright © 2018 David Mancol. All rights reserved.
////
//
//#include <iostream>
//#include "Calculator.h"
//using namespace std;
//
//// Main function
//int main()
//{
//    Calculator::stack s;
//    s.createHead(0);
//    s.push();
//    s.push();
//    s.show();
//    return 0;
//}
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;
};

template<class T>
class Stack {
public:
    Stack();
    int size;
    Node<T> *top;
    void push(T val);
    T pop();
    T peek();
};

template<class T>
Stack<T>::Stack() {
    size = 0;
    top = NULL;
}

template<class T>
void Stack<T>::push(T val) {
    auto *n = new Node<T>;
    n->data = val;
    if (top) {
        n->next = top;
    } else {
        n->next = NULL;
    }
    top = n;
    size++;
}

template<class T>
T Stack<T>::pop() {
    T val = top->data;
    if (top->next == NULL) {
        delete top;
    } else {
        Node<T> *tmp = top->next;
        delete top;
        top = tmp;
    }
    size--;
    return val;
}

template<class T>
T Stack<T>::peek() {
    return top->data;
}

int main() {
    auto *activeStack = new Stack<int>;
    auto *inactiveStack = new Stack<int>;
    string arr[] = {"+", "-", "*", "/", "%"};
    std::set<string> operators(arr, arr + sizeof(arr) / sizeof(arr[0]));
    string input;
    cout << "> ";
    cin >> input;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    int current = 0;
    activeStack->push(current);
    while (input != "q") {
        Node<int> *root;
        if (input == "c") {
            current = 0;
            activeStack->push(current);
        } else if (input == "u") {
            int prev = activeStack->pop();
            inactiveStack->push(prev);
            current = activeStack->peek();
        } else if (input == "r") {
            if (inactiveStack->size == 0) {
                cout << "No operations to redo" << endl;
            } else {
                current = inactiveStack->pop();
                activeStack->push(current);
            }
        } else {
            string oper = input.substr(0, 1);
            if (operators.find(oper) == operators.end()) {
                cout << "Invalid operator. Please try again." << endl;
                cin >> input;
            }
            int operand = atoi(input.substr(1).c_str());
            if (!operand) {
                cout << "Invalid input. Please try again." << endl;
                cin >> input;
            }
            if (oper == "+")
                current += operand;
            else if (oper == "-")
                current -= operand;
            else if (oper == "*")
                current *= operand;
            else if (oper == "/")
                current /= operand;
            else
                current %= operand;
            activeStack->push(current);
            while (inactiveStack->size > 0)
                inactiveStack->pop();
            inactiveStack->size = 0;
        }
        cout << current << endl;
        cout << "> ";
        cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    }
    cout << "Goodbye" << endl;
}