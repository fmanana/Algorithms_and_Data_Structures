/*
    Author: Fezile Manana
    Note: the max_heapify and heapSort functions are variantions
    of the functions found on this site:
    https://www.geeksforgeeks.org/heap-sort/
    The rest of the code is my own work.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#define SIZE 10

using namespace std;

typedef class Node
{
    public:
        int pos;
        int var;
        Node *parent;
        Node *left_child;
        Node *right_child;
}Node;

void swap(int *parent, int *child)
{
    int temp = *parent;
    *parent = *child;
    *child = temp;
}

void max_heapify(Node *heap, int size, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < size && ((heap+l)->var < (heap+largest)->var))
    {
        largest = l;
    }

    if(r < size && ((heap+r)->var < (heap+largest)->var))
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(&(heap+i)->var, &(heap+largest)->var);

        max_heapify(heap, size, largest);
    }
}

void heapSort(Node *heap, int size)
{
    int i;

    for(i = (size/2)-1; i >= 0; i--)
    {
        max_heapify(heap, size, i);
    }

    for(i = size - 1; i >= 0; i--)
    {
        swap(&(heap)->var, &(heap+i)->var);

        max_heapify(heap, i, 0);
    }
}


int main()
{
    Node *heap;
    heap = new Node[SIZE];

    srand((unsigned)time(0));
    int i, j;

    //Linking nodes into a bunary tree
    for(i = 0; i < SIZE; i++)
    {
        /*Initialising root node with children and
          pointing to itself
        */
        if(i == 0)
        {
            (heap+i)->pos = 1;
            (heap+i)->var = rand() % 1000000 +1;
            (heap+i)->parent = heap;
            (heap+i)->left_child = (heap+1);
            (heap+i)->right_child = (heap+2);
        }
        else
        {
            j = (floor((i+1)/2)) - 1;
            (heap+i)->pos = i+1;
            (heap+i)->var = rand() % 100000000 + 1;
            (heap+i)->parent = (heap + j);
            (heap+i)->left_child = (heap + (i*2) + 1);
            (heap+i)->right_child = (heap + ((i*2) + 2));
            /* Since all variables in the heap are modulo plus 1
            zero entries indicate NULL pointers from parents with
            no children. */
        }
    }

    //Printing the numbers
    cout << "Heap:" << endl;
    for(i = 0; i < SIZE; i++)
    {
        cout << (heap+i)->var << endl;
    }

    cout << endl;
    clock_t start = clock();
    heapSort(heap, SIZE);
    clock_t stop = clock();

    cout << "Sorted heap:" << endl;
    for(i = 0; i < SIZE; i++)
    {
        cout << (heap+i)->var << endl;
    }
    cout << endl;
    cout << "Run time for size " << SIZE << " is: ";
    cout << (stop-start)/(double)CLOCKS_PER_SEC << "s" << endl;

    delete[]heap;
    return 0;
}
