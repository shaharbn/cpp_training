#include "PPPheaders.h"

int main()
{
    cout << "Enter operator and 2 operands (nums)\n";
    string operation;
    double num1 {0};
    double num2 {0};
    double res {0};
    cin >> operation >> num1 >> num2;
    if (operation == "+")
    {
        res = num1 + num2;
    }
    else if (operation == "-")
    {
        res = num1 - num2;
    }
    else if (operation == "*")
    {
        res = num1 * num2;
    }
    else if (operation == "/")
    {
        res = num1 / num2;
    }

    cout << "result: " << res << '\n';
}