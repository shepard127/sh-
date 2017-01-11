#include <iostream>

using namespace std;

int main()
{
    int array[100] = {0}, max_element = 0;
    int amountSpace = 0, currentElement = 1;

    for(int k = 0; currentElement != 0; k++)       // юзер заполняет массив
    {
        cin >> currentElement;
        array[k] = currentElement;
    }

    int control = array[0];
    for(int i = 0; control > 0; i++)               // находим макс. элемент
    {
        if(array[i] > max_element)
        {
            max_element = array[i];
        }
        control = array[i+1];
    }

    int centerStarMaxElem  = (max_element + 1) / 2;
    int centerStarCurrElem = 0;

    control = array[0];
    for(int j = 0; control > 0; j++)               // тут мозги(считаем сколько звезд и пробелов нам нужно, потом выводим)
    {
        if(array[j] == max_element)
            amountSpace = 0;
        else
        {
            centerStarCurrElem = (array[j] + 1) / 2;
            amountSpace = centerStarMaxElem - centerStarCurrElem;
        }

        for(int count = 0; count < amountSpace; count++)
            cout << " ";

        for(int count = 0; count < array[j]; count++)
            cout << "*";

        control = array[j+1];
        amountSpace = 0;
        cout << endl;
    }

    return 0;
}

