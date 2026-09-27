#include "PPPheaders.h"

static void swap_int(string& num1, string& num2)
{
    string temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    cout << "Enter 3 string\n";

    string val1;
    string val2;
    string val3;
    cin >> val1 >> val2 >> val3;

    if (val1 > val2)
    {
        swap_int(val1, val2);
    }

    if (val2 > val3)
    {
        swap_int(val2, val3);
    }

    if (val1 > val2)
    {
        swap_int(val1, val2);
    }

    cout << val1 << ", " << val2 << ", " << val3 << '\n';
}