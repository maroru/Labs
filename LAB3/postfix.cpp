// Matthew Ruiz
#include <iostream>
#include <string>
#include <stack>

int postfixCalculator(std::string expression)
{
    int result{0};
    std::stack<int> numStack;

    for (int i{0} ; i < expression.length() ; i++)
    {
        if (isdigit(expression[i]))
            numStack.push(expression[i] - '0');
        else // ch is an operator named op
        {
            // Evaluate and push the result
            int operand2 { numStack.top() }; 
            numStack.pop();

            int operand1 { numStack.top() };
            numStack.pop();

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
                    result = operand1 / operand2;
                    break;
                default:
                    return 0;
            }
            numStack.push(result);
        }
    }
    return numStack.top();
}

int main()
{
    std::string expression;
    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, expression);
    int result { postfixCalculator(expression) };
    std::cout << "Result: " << result << '\n';
    return 0;
}
