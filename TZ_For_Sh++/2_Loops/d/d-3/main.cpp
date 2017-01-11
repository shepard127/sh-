#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cout << "Enter size: ";
    cin >> size;

    int value = size;
    for(int i = 0; i < size; i++)
    {
        for(int k = 0; k < i; k++)
            cout << " ";

        for(int j = 0; j < size; j++)
            cout << "*";

        size--;
        cout << endl;
    }

    return 0;
}
