#include "PPPheaders.h"

int main()
{
    for (int i = 0; 'a' + i <= 'z'; ++i)
    {
        cout << char('a' + i) << '\t' << 'a' + i << '\n';
    }
}