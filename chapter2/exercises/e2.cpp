#include "PPPheaders.h"

int main()
{
    const double ratio {1.609};
    cout << "Welcome to converter from miles to km\n";
    cout << "Enter amount for miles: ";
    double amount_of_miles {0};
    cin >> amount_of_miles;
    cout << amount_of_miles << " miles = " << amount_of_miles * ratio << " km\n";
}