#include <iostream>
using namespace std;

void input(int* p_size)
{
    int inputValue;
    cin >> inputValue;
    *(p_size) = inputValue;
}

void printSpace(int l_countSpace);
void printStar (int l_countStar );
void totalPrintStar (int l_countStar);
void printPenyok(int l_size);

int main()
{
    int size = 0;


    cout << "Enter size fir-tree: ";
    input(&size);                           // func1

    int countSpace = size;
    int countStar  = 1;

    for(int i = 0; i < size; i++)
    {
        printSpace(countSpace);             // func2
        printStar (countStar );             // func3
        totalPrintStar(countStar);          // func4

        countStar++;
        countSpace--;
        cout << endl;
    }
    printPenyok(size);                      // func5

    return 0;
}

void printSpace(int l_countSpace)
{
    for(int k = 0; k < l_countSpace; k++)
        cout << " ";
}
void printStar (int l_countStar )
{
    for(int j = 0; j < l_countStar; j++)
        cout << "*";
}
void totalPrintStar (int l_countStar)
{
    if(l_countStar > 1)
    {
        for(int j = 0; j < l_countStar - 1; j++)
            cout << "*";
    }
}
void printPenyok(int l_size)
{
    for(int i = 0; i < l_size; i++)
        cout << " ";

    cout << "*" << endl;
}










