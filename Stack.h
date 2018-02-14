#ifndef STACK_H
#define STACK_H

/*
 * Creates a generic node with a pointer
 */
template<class T>
class Node {
public:
    T data;
    Node<T> *next;
};

/*
 * Creates a generic Stack class
 */
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

/*
 * Initializes Stack
 */
template<class T>
Stack<T>::Stack() {
    size = 0;
    top = NULL;
}

/*
 * Push method for Stack
 * Pushes value onto stack and re-adjusts stack so that top points to the top of stack
 * Increments size count
 */
template<class T>
void Stack<T>::push(T val) {
    auto *n = new Node<T>;
    n->data = val;
    if (top) {
        n->next = top;
    }
    else {
        n->next = NULL;
    }
    top = n;
    size++;
}

/*
 * Pop method from Stack
 * Removes nodes from the top of the Stack
 * Decrements the size of the Stack
 * Returns the value that has been popped
 */
template<class T>
T Stack<T>::pop() {
    T val = top->data;
    if (top->next == NULL) {
        delete top;
    }
    else {
        Node<T> *tmp = top->next;
        delete top;
        top = tmp;
    }
    size--;
    return val;
}

/*
 * Peek at the top of the Stack
 * Returns the data within the node at the top of the Stack
 */
template<class T>
T Stack<T>::peek() {
    return top->data;
}



#endif
