// Matthew Ruiz
#include <iostream>

int postfixCalculator(int stringArr[], int max)
{
    for (int i = 0; i < max ; i++)
    {
        if (stringArr[i] != ( '*' || '/' || '+' || '-' ))
            push(stringArr[i]);
        else // ch is an operator named op
        {
            // Evaluate and push the result
            operand2 = top;
            pop;

            operand1 = top;
            pop;

            result = operand1 op operand2;
        }
    }
    return result;
}

int main()
{
    std::string newString[];
    std::cout << "Enter: ";
    std::getline(std::cin, newString[]);
    std::cout << '\n';
    std::cout << "Result: " << postfixCalculator(newString[], max);
    return 0;
}
