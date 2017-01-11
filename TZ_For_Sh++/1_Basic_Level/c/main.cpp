#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0, branch = 0, result = 0;

    cout << "wwedi 1e chislo: ";
    cin >> a;
    cout << "\nwwedi 2e chislo: ";
    cin >> b;
    cout << "\nwwedi 1 chtob naiti summu, 2 chtobi naiti raznicu, 3 dlya deleniya: 3" << endl;
    cin >> branch;

    switch (branch)
    {
        case 1:
            {
                result = a + b;
                break;
            }
        case 2:
            {
                result = a - b;
                break;
            }
        case 3:
            {
                result = a / b;
                break;
            }
        default:
            {
                cout << "Error!\n";
                return 1;
                break;
            }
    }

    cout << "resultat = " << result << endl;
    return 0;
}

