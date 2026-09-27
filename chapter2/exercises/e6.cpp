#include "PPPheaders.h"

static void swap_int(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    cout << "Enter 3 ints\n";

    int val1 {0};
    int val2 {0};
    int val3 {0};
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