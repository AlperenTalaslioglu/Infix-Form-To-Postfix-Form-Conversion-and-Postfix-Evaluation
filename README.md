# Infix-Form-To-Postfix-Form-Conversion-and-Postfix-Evaluation

This is an implementation of converstion of infix form expressions to postfix form expressions and evaluations of this postfix form expression. <br />

### Details <br />

The program will ask for an arithmetic expression in infix form. All the operators and operands of the input expression should be separated with a space character and the expression should end with a ‘;’ character. The input format is strict to be able to parse the expression easily. The program will first print out the input expression in postfix form, following the same formatting rules. Then, the result of the arithmetic expression will be printed. A sample run of the program can be as follows.<br />

> Stack is implemented with a linked list data structure. <br />

> The program supports the basic four operators (i.e., +, -, *, /) and the use of parenthesis.  <br />


### Example Input and outputs <br />

Enter an arithmetic expression: 4 * 1 + 5 + 6 * 1 ;  <br />
Input expression in postfix form: 4 1 * 5 + 6 1 * + ; <br /> 
The result is: 15 <br /> <br />
> The program supports the basic four operators (i.e., +, -, *, /) and the use of parenthesis.  <br />


Enter an arithmetic expression (operators and operands must be separated with a space character and the expression must end with a ';' character)
: 4 * 1 + 5 + 6 * 1 ; <br />
Postfix form:  4 1 * 5 + 6 1 * + ; <br />
Result:  15 <br />
Program ended with exit code: 0 <br />


