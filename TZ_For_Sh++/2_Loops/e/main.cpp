#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cout << "Enter size fir-tree: ";
    cin >> size;

    int countSpace = size;
    int countStar  = 1;

    for(int i = 0; i < size; i++)
    {
        for(int k = 0; k < countSpace; k++)
            cout << " ";

        for(int j = 0; j < countStar; j++)
            cout << "*";

        if(countStar > 1)
        {
            for(int j = 0; j < countStar - 1; j++)
                cout << "*";
        }

        countStar++;
        countSpace--;
        cout << endl;
    }
    for(int i = 0; i < size; i++)
        cout << " ";

    cout << "*" << endl;

    return 0;
}
