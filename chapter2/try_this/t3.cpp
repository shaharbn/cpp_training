#include "PPPheaders.h"

int main()
{
    string prev;
    string curr;
    while (cin >> curr)
    {
        if (prev == curr)
        {
            cout << curr << "\n";
        }
        prev = curr;
    }

    return 0;
}