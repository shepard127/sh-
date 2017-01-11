#include <iostream>

using namespace std;

void inputData(int* p_schools, int l_size);
bool search(int* p_schools, int l_size, int l_number);

int main()
{
    int size = 10;
    int schools[size] = {0};

    inputData(&schools[0], size);

    int number;
    cout << "Enter number you school: " ;
    cin >> number;

    if(search(&schools[0], size, number))
        return 1;

    cout << "I do not know the number of that school!";

    return 0;
}

void inputData(int* p_schools, int l_size)
{
    for(int i = 0; i < l_size; i++)
    {
        cout<< "Enter number school " << i+1 << endl;
        cin >> *(p_schools + i);
    }
}

bool search(int* p_schools, int l_size, int l_number)
{
    for(int i = 0; i < l_size; i++)
        if(*(p_schools + i) == l_number)
        {
            cout << "I know the number of that school!";
            return true;
        }
    return false;
}
