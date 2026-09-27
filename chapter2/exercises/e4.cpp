#include "PPPheaders.h"

int main()
{
    cout << "Enter 2 doubles\n";

    double val1 {0};
    double val2 {0};

    cin >> val1 >> val2;
    double bigger = val1 < val2 ? val2 : val1;
    double lowest = val1 < val2 ? val1 : val2;

    cout << "bigger num is: " << bigger << '\n';
    cout << "lowest num is: " << lowest << '\n';
    cout << "sum: " << val1 + val2 << '\n';
    cout << "diff: " << bigger - lowest << '\n';
    cout << "product: " << val1 * val2 << '\n';
    cout << "ratio: " << bigger / lowest << '\n';

    return 0;
}