#include <iostream>

using namespace std;

int main()
{
    int size = 10;
    int schools[size] = {0};

    for(int i = 0; i < size; i++)
    {
        cout<< "Enter number school " << i+1 << endl;
        cin >> schools[i];
    }

    int number;
    cout << "Enter number you school: " ;
    cin >> number;

    for(int i = 0; i < size; i++)
    {
        if(schools[i] == number)
        {
            cout << "I know a number of the school!";
            return 1;
        }
    }
    cout << "I do not know the number of that school!";

    return 0;
}
