/*
    Author: Fezile Manana
*/

#include <iostream>
#include <cstring>

template <class T>
class Stack
{
    struct StackNode
    {
        T data;
        StackNode *next;
    };
    StackNode *top;
    int size;
    int current_size = 0;
    
    public:
        //Stack constructor

        //Initialising size to -1 if not set
        Stack(int size = -1);
        Stack(const Stack&);
        ~Stack(){};
        //Methods
        bool push(T element);
        T pop();
        T show(void); //Shows what's on the top of the stack
        int getNumEntries();
        bool isEmpty();
        void reverse();
};

template<class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    top = NULL;
}

template<class T>
bool Stack<T>::push(T element)
{
    //Checking to see if the array is full.
    if(current_size == size)
    {
        try
        {
            throw "Stack full!";
        }
        catch(char const* a)
        {
            std::cerr << "Stack overflow!" << std::endl;
            return false;
        }
    }
    /*
        else is also valid for undeclared size (i.e. size = -1)
        as current_size will never be -1
    */
    else
    {
        //Creating new node
        StackNode *node;
        node = new StackNode;
        node->data = element;
        node->next = nullptr;
        if(top != NULL)
            node->next = top;
        top = node;

        //Incrementing current size after pushing
        current_size++;
        std::cout << "Pushing: " << element << std::endl;
        return true;
    }
}

template<class T>
T Stack<T>::pop()
{
    if(top == NULL)
        {
            try
            {
                throw "Stack empty!";
            }
            catch(char const* b)
            {
                std::cerr << "Stack underflow!" << std::endl;
                return false;
            }
        }
    else
    {
        StackNode *temp;
        temp = top;
        T out = temp->data;
        std::cout << "Popping: " << out << std::endl;
        delete temp;
        top = top->next;

        //Decrement current size when popping
        current_size--;

        return out;
    }
}

template<class T>
bool Stack<T>::isEmpty()
{
    if(top == NULL)
        return true;
    else
        return false;
}

template<class T>
T Stack<T>::show(void)
{
    std::cout << "The last element: " << top->data << std::endl;
    return (top->data);
}

template<class T>
int Stack<T>::getNumEntries()
{
    std::cout << "Number of elements: " << current_size << std::endl;
    return (current_size);
}

//Reverse algorithm
template<class T>
void Stack<T>::reverse()
{
    if(top == NULL) //If stack is empty do nothing
        return;
    /*
        Algorithm uses constant storage to reverse a stack
        of any size by using three helping nodes to switch pointers
    */
    StackNode *prev = NULL;
    StackNode *current = NULL;
    StackNode *next = NULL;
    
    std::cout << "Stack is being reversed." << std::endl;
    current = top;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        /*
            In the while loop, no extra storage is being reserved
            to copy elements. As the loop tranverses the stack, the
            pointers are being swapped in order to reverse the stack.
            Therefore, this algorithm is in situ as it only needs
            3 helping nodes to reverse a stack of any size.
            The asymptotic run time is O(n) as the stack is only
            traversed once.
        */
    }
    top = prev;
}