#include "PPPheaders.h"

int main()
{
    cout << "Enter spell out num: ";
    string num;
    while (cin >> num)
    {
        if ("zero" == num)
        {
            cout << 0 << '\n';
        }
        else if ("one" == num)
        {
            cout << 1 << '\n';
        }
        else if ("two" == num)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << "not a number I know\n";
        }
    }
}