#include <iostream>

using namespace std;

int main()
{
    int money = 0;
    cout << "kakaya u tebya zarplata? ";
    cin >> money;

    if(money > 1000000)
        cout << "\nti milioner!\n";
    else if(money > 1000)
        cout << "\nti bogat!\n";
    else
        cout << "\nti beden!\n";

    return 0;
}
