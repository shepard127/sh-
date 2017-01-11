#include <iostream>

using namespace std;

int main()
{
    int star = 0, i = 0;
    cout << "Сколько звездочек? ";
    cin >> star;

    while (i < star)
    {
        cout << "*";
        i++;
    }

    return 0;
}

