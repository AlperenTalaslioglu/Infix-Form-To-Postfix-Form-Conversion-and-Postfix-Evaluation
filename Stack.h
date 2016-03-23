#ifndef __STACK__
#define __STACK__

#include <string>
#include "StackItem.h"

using namespace std;

class Stack {
public:
    Stack();
    ~Stack();
    bool isEmpty();  // Tests if this stack is empty.
    StackItem* peek(); // Looks at the object at the top of this stack without removing it from the stack.
    StackItem* pop(); // Removes the object at the top of this stack and returns that object as the value of this function.
    void push(StackItem*); // Pushes an item onto the top of this stack.
    void displayStack(); // Printing stack into console
private:
    StackItem* stackHead;
};

#endif
