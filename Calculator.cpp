#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <iostream>
#include "Stack.h"

using namespace std;

/*
 * Instantiate two stacks (the inactive one is used for storing information)
 * Takes input from the user and evaluates it
 * If Undo is activated, nodes from activeStack are moved to the inactiveStack
 * If Redo is activates, nodes fom inactiveStack are moved to the activeStack
 */
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

    // Loop until user inputs quit command
    while (input != "q") {
        Node<int> *root;
        // Clear the calculator back to zero
        if (input == "c") {
            current = 0;
            activeStack->push(current);
        }
        else if (input == "u") {
            int prev = activeStack->pop();
            inactiveStack->push(prev);
            current = activeStack->peek();
        }
        else if (input == "r") {
            if (inactiveStack->size == 0) {
                cout << "No operations to redo" << endl;
            }
            else {
                current = inactiveStack->pop();
                activeStack->push(current);
            }
        }
        else {
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