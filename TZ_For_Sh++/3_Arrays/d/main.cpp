#include <iostream>
using namespace std;

int main()
{
    int arrayInput[5] = {0};
    for(int i = 0; i < 5; i++)
        cin >> arrayInput[i];

    char array[5][100];
    char space = ' ', star = '*';

    for(int row = 0; row < 5; row++)
        for(int col = 0; col < 25; col++)
            array[row][col] = space;

    for(int row = 0; row < 5; row++)
        for(int col = 0; col < arrayInput[row]; col++)
            array[row][col] = star;

    int max_element = 0;
    for(int col = 0; col < 5; col++)
        if(arrayInput[col] > max_element)
            max_element = arrayInput[col];

    for(int row = 0; row < max_element; row++)
    {
        for(int col = 0; col < 5; col++)
            cout << array[col][row];

        cout << endl;
    }

    return 0;
}

