#include<iostream>

#ifndef _BST_H_
#define _BST_H_
//Definition of Node for Binary search tree
struct Node
{
	int data; 
	Node* left;
	Node* right;
};

// Function to create a new Node in heap
Node* CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
Node* Insert(Node* root, int data)
{
	if(root == NULL) //If the tree is empty
		root = CreateNode(data);

	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data)
		root->left = Insert(root->left, data);

	// else, insert in right subtree. 
	else
		root->right = Insert(root->right, data);

	return root;
}

/*
    Converting the BST to a linked list:
    The asymptotic runtime for this algorithm is
    O(n) as the recursive function needs to pass
    through every node and change the pointers.
*/
void ConvertToLinkedList(Node *root, Node **head)
{
    //  If tree is empty do nothing
    if(root == NULL)
        return;

    static Node *prev = NULL;
    //First recursively convert the left subtree
    ConvertToLinkedList(root->left, head);
    if(prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    //Convert the right subrtree
    ConvertToLinkedList(root->right, head);   
}

/*
    This function countes the number of elements
    in the linked list. This information is used in 
    the algorithm to convert the sorted linked list
    into a BST.
*/
int countNodes_L(Node *node)
{
    int counter = 0;
    while (node!=NULL)
    {
        counter++;
        node = node->right;
    }
    return counter;
}

/*
    head is the head of the linked list,
    start is the index of the first element in the linked list,
    end is the index of the last element in the linked list.
*/
Node* ListToBST_Func(Node **head, int start, int end)
{
    //  If the list is empty do nothing
    if(start > end)
        return NULL;
    /*
        Getting the middle element of the linked list
        in order to make it the root of the tree we want
        to construct.
    */
    int root_index = start+(end-start/2);
    Node *cursor = *head;

    int i = 0;
    while(i < root_index && cursor->right != NULL)
    {
        cursor = cursor->right;
        i++;
    }
    Node *root = CreateNode(cursor->data);

    /*
        Here the algorihtm recursively gets the element halfway
        between the current root(middle of the list) and the
        start, and then assigns this to the left node of the current root.
    */
    root->left = ListToBST_Func(head, start, root_index-1);

    //  Same logic only for right nodes of the tree
    root->right = ListToBST_Func(head, root_index+1, end);

    return root;
    //  The Overall time complexity of the algorithm is O(nlogn)
}

Node* ListToBST(Node *head)
{
    int n = countNodes_L(head);
    return ListToBST_Func(&head, 0, n-1);
}

//  Printing functions

void printBST(Node *root) // Print by level
{
    if(root != NULL)
    {
        std::cout << root->data << " ";
        printBST(root->left);
        printBST(root->right);
    }
}

void printList(Node *node)
{
    while (node!=NULL)
    {
        std::cout << node->data << " ";
        node = node->right;
    }
}

#endif