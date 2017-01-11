#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cout << "Enter size: ";
    cin >> size;

    int row = 0, col = 0;
    while (row < size)
    {
        while(col < size)
        {
            cout << "*";
            col++;
        }
        col = 0;
        cout << endl;
        row++;
    }

    return 0;
}

