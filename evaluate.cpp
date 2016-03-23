#include <iostream>
#include <string>
#include <sstream>
#include "Calculator.h"

int main (){
    
    string infixExpression;
    
    cout << "Enter an arithmetic expression ";
    cout << "(operators and operands must be separated with a space character and the expression must end with a \';\' character)";
    cout << endl << ": ";
    getline(cin, infixExpression);
    
    Calculator *calculator = new Calculator(infixExpression);
    
    cout << "Postfix form: " << calculator->getPostfix() << endl;
    cout << "Result: " << calculator->calculate() << endl;
    
    delete calculator;
    
    return 0;
}