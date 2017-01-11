#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cout << "Enter size: ";
    cin >> size;

    int row = size, col = 0;
    while (row > 0)
    {
        while(col < size)
        {
            cout << "*";
            col++;
        }
        col = 0;
        size--;
        row--;
        cout << endl;
    }

    return 0;
}
