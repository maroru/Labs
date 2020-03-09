// Matthew Ruiz
#include <iostream>
#include <string>
#include <stack>

int postfixCalculator(std::string expression);
void userInput();

int main()
{
    std::cout << "\nValid operands: single digit non-negative integers (zero th"
              << "rough nine)\n";
    std::cout << "Valid operators: +, -, *, and /\n";
    std::cout << "To terminate program enter no expression\n";
    std::cout << "Example of a valid postfix expression: 22+38+*2/9-\n";
    std::cout << "Example in infix format: ([2+2] * [3+8])/2 - 9 = 13\n\n";

    userInput();
    return 0;
}

int postfixCalculator(std::string expression)
{
    int result{0};
    std::stack<int> intStack;

    for (int i{0} ; i < expression.length() ; i++)
    {
        if (isdigit(expression[i]))
            intStack.push(expression[i] - '0');
        else // ch is an operator named op
        {
            // Evaluate and push the result
            int operand2 { intStack.top() }; 
            intStack.pop();

            int operand1 { intStack.top() };
            intStack.pop();

            // calculator
            switch (expression[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        std::cout << "Error divide by ";
                        return 0;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    std::cout << "Use symbols +, -, *, or /.\n";
                    return 0;
            }

            intStack.push(result);
        }
    }
    return intStack.top();
}

void userInput()
{
    std::string expression;

    while(true)
    {
        std::cout << "Enter a postfix expression: ";
        std::getline(std::cin, expression);
        if (expression == "")
            break;
        std::cout << "Result: " << postfixCalculator(expression) << '\n';
    }
}
