#include <iostream>

using namespace std;

int main()
{
    int number = 0, i = 1;

    cout << "Введите число? ";
    cin >> number;
    if(number > 0)
    {
        while(i < number)
        {
            cout << i << ",";
            i++;
        }
    }


    return 0;
}
