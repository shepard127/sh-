#include <iostream>
#include <stdio.h>
using namespace std;
struct linkedList
{
    int data;
    linkedList *next;
};

class List
{
public:
    List()
    {
      head = NULL;
    };
    void functionAddNode(int l_data)
    {
        linkedList *newNode = new linkedList;

        newNode->data = l_data;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            linkedList *jumper = head;
            while (jumper->next != NULL)
            {
                jumper = jumper->next;
            }
            jumper->next = newNode;
        }
    }
    void functionPrintLis()
    {
        linkedList *tempPrint = head;
        while (tempPrint != NULL)
        {
            cout << tempPrint->data << endl;
            tempPrint = tempPrint->next;
        }
    }

private:
    linkedList* head;

};

int main()
{
    List splitList;
    int i = 0;
    while (i < 200)
    {
        splitList.functionAddNode(i);
        i+= 9;
    }
    splitList.functionPrintLis();
    return 0;
}
