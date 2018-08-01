#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    Stack<int> int_stack(10);

    for(int i = 0; i < 7; i++)
    {
        int_stack.push(rand()%12);
    }
   
   int_stack.reverse();
    cout << endl;
    int_stack.getNumEntries();
    cout << endl;

    for(int i = 0; i < 9; i++)
    {
        int_stack.pop();
    }

    cout << endl;
    cout << int_stack.isEmpty() << endl;
    cout << endl;

    for(int i = 0; i < 11; i++)
    {
        int_stack.push(rand()%15 + 1);
    }

    Stack<char> char_stack(5);

    for(int i = 0; i < 7; i++)
    {
         //Characters within the range of a - z in ASCII table
        char_stack.push((char)((rand()%26) + 97));
    }

    char_stack.pop();

    cout << char_stack.isEmpty() << endl;
    cout << int_stack.isEmpty() << endl;

    cout << endl;
    Stack<float> f_stack;

   return 0;
}