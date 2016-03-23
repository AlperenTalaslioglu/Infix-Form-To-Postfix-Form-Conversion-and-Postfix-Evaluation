#include "Calculator.h"

Calculator::Calculator(string infixExpression){
    this->infixExpression = infixExpression;
    this->stack = new Stack();
}

Calculator::~Calculator(){
    delete this->stack;
}

string Calculator::convertInfixToPostfix(string infix){
    
    istringstream iss(infix);
    string item = "";
    
    while(1) {
        iss >> item;
        if(item == ";"){break;} // Finish loop
        
        StackItem *stackItem = new StackItem(item);
        
        if(!stackItem->isOperator){
            postfixExpression = postfixExpression +  item + " ";
        }else if(stackItem->isOperator){
            
            if(stack->isEmpty()){
                stack->push(stackItem);
            }else{
                
                if(item == "("){
                    stack->push(stackItem);
                }else if(item == ")"){
                    while(!stack->isEmpty()){
                        if(stack->peek()->toString() == "("){ stack->pop(); break;}
                        else{postfixExpression = postfixExpression +  stack->pop()->toString() + " ";}
                    }
                }else{
                    string topItemOnStack = stack->peek()->toString();
                
                    if(!canItemPutOnStack(topItemOnStack,item)){
                        while(!stack->isEmpty()){
                            if(stack->peek()->toString() == "("){ break;}
                            else{postfixExpression = postfixExpression +  stack->pop()->toString() + " ";}
                        }
                    }
                    stack->push(stackItem);
                }
            }
        }
    }
    
    // Empty the items in the stack
    while(!stack->isEmpty()){
        if(stack->peek()->toString() == "("){ stack->pop();}
        else{postfixExpression = postfixExpression +  stack->pop()->toString() + " ";}
    }
    postfixExpression += ";";
    
    return postfixExpression;
}


// Precedence check of operators
bool Calculator::canItemPutOnStack(string topOnStack, string currentItem){
    if((topOnStack == "+" || topOnStack == "-") && (currentItem == "+" || currentItem == "-")){
        return false;
    }else if((topOnStack == "*" || topOnStack == "/") && (currentItem == "*" || currentItem == "/")){
        return false;
    }else if((topOnStack == "+" || topOnStack == "-") && (currentItem == "*" || currentItem == "/")){
        return true;
    }else if((topOnStack == "*" || topOnStack == "/") && (currentItem == "+" || currentItem == "-")){
        return false;
    }
    return true;
}

string Calculator::getPostfix(){
    postfixExpression = convertInfixToPostfix(infixExpression);
    return postfixExpression;
}

int Calculator::calculate(){
    istringstream iss(postfixExpression);
    string item = "";
    
    while(1) {
        iss >> item;
        if(item == ";"){break;} // Finish loop
        
        StackItem *stackItem = new StackItem(item);
        
        if(stackItem->isOperator){
            int operand2 = stack->pop()->n;
            int operand1 = stack->pop()->n;
            
            if(item.compare("+") == 0){ stack->push(new StackItem(false, (operand1 + operand2))); }
            else if(item.compare("-") == 0){ stack->push(new StackItem(false, (operand1 - operand2)));}
            else if(item.compare("*") == 0){ stack->push(new StackItem(false, (operand1 * operand2))); }
            else if(item.compare("/") == 0){ stack->push(new StackItem(false, (operand1 / operand2))); }
        }else{
            stack->push(stackItem);
        }
    }
    return stack->pop()->n;
}