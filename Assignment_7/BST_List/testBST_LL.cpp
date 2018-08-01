#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BstList.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    Node* tree = NULL;
    for(int i = 0; i < 15; i++)
    {
        //  Inserting random integers
        tree = Insert(tree, rand()%40+1);
    }

    cout << "Printing BST:" << endl;
    printBST(tree);
    cout << endl;
    Node* List = NULL;
    //Coverting to linked list
    ConvertToLinkedList(tree, &List);
    cout << "Printing List:" << endl;
    printList(List);
    cout << endl;
    cout << "Printing tree converted from linked list" << endl;
    List = ListToBST(List);
    printBST(List);
    cout << endl;

    return 0;
}