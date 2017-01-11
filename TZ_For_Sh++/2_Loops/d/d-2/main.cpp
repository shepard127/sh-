#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cout << "Enter size: ";
    cin >> size;

    int value = 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < value; j++)
            cout << "*";

        value++;
        cout << endl;
    }

    return 0;
}
