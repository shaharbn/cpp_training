#include "PPPheaders.h"

int main()
{
    cout << "Enter the name of the person you want to write to: ";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n";

    cout << "How are you? I am fine. I miss you.\n";

    cout << "Enter a friend name: ";
    string friend_name;
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n";

    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 110)
    {
        error("you're kidding!");
    }
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    if (age < 12)
    {
        cout << "Next year you will be " << age+1 << ".\n";
    }
    else if (age == 17)
    {
        cout << "Next year you will be able to vote.\n";
    }
    else if (age > 70)
    {
        cout << "Are you retired?\n";
    }

    cout << "Yours sincerely,\n\nShahar Bar Natan\n";

    return 0;
}