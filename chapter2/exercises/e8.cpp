#include "PPPheaders.h"

int main()
{
    cout << "Enter an int: ";
    int val {0};
    cin >> val;
    cout << "The value " << val << " is an " << (val % 2 == 0 ? "even" : "odd" ) << '\n';
}