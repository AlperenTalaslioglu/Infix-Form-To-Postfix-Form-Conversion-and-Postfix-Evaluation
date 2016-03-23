#include "Stack.h"


Stack::Stack(){
    stackHead = NULL;
}

Stack::~Stack(){
    delete stackHead;
}

// Tests if this stack is empty.
bool Stack::isEmpty(){
    if(stackHead == NULL){
        return true;
    }else{
        return false;
    }
}

// Looks at the object at the top of this stack and return value of this object
StackItem* Stack::peek(){
    StackItem *peekStackItem = stackHead;
    
    while(peekStackItem != NULL){
        if(peekStackItem->next == NULL){break;}
        peekStackItem = peekStackItem->next;
    }
    return peekStackItem;
}

// Removes the object at the top of this stack and returns this object
StackItem* Stack::pop(){
    StackItem *popStackItem = stackHead;
    
    // One item in stack case
    if(stackHead->next == NULL){
        stackHead = NULL;
        return popStackItem;
    }
    
    // More items in stack case
    while(popStackItem != NULL){
        if(popStackItem->next == NULL){break;} // Finish loop at the end of linked list
        if(popStackItem->next->next == NULL){  // Pop the top element and remove its link
            StackItem *pop =  popStackItem->next;
            popStackItem->next = NULL;
            return pop;
        }
        popStackItem = popStackItem->next;
    }
    return popStackItem;
}

void Stack::push(StackItem *item){
    if(stackHead == NULL){
        stackHead = item;
    }else{
        StackItem *temp = stackHead;
        
        while(1){
            if(temp->next == NULL){
                temp->next = item;
                break;
            }
            temp = temp->next;
        }
    }
}

/*
 
 Notation is like below
 
 |   |
 | * |
 | + |
  ---
 
 |   |
 | - |
  ---
 
 */
void Stack::displayStack(){
    cout << "|   |" << endl;
    
    // Empty Stack Display
    if(stackHead == NULL){
        cout << "|   |" << endl;
    }else{
        string stackBody = "";
        StackItem *temp = stackHead;
        
        while(temp != NULL){
            stackBody = ("| "  +  temp->toString() + " | \n") + stackBody;
            temp = temp->next;
        }
        cout << stackBody;
    }
    cout << " --- " << endl;
}