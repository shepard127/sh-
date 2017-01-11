#include <iostream>

using namespace std;

int main()
{
    int bankomat[10] = {0}, nomer, money, i;
    int moneyResult;

    while(1)
    {
        cout << "vvedi nomer kartochki: ";
        cin >> nomer;

        money = 0;
        cout << "\nskolko polozhit?\n";
        cin >> money;
        bankomat[nomer] = money;

        i = 0;
        moneyResult = 0;
        while(i < sizeof(bankomat) / sizeof(int))
        {
            moneyResult += bankomat[i];
            i++;
        }
        cout << "v summe na vseh kartah " << moneyResult << endl;
    }
    
    return 0;
}

