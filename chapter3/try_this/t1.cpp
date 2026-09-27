#include "PPPheaders.h"

int main()
{
    int i {0};
    while ('a' + i <= 'z')
    {
        cout << char('a' + i) << '\t' << 'a' + i << '\n';
        ++i;
    }
}