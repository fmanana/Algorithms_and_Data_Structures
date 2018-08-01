/*
	Author; Fezile Manana
*/

#include <iostream>

#ifndef _RBT_H_
#define _RBT_H_

enum Color { RED, BLACK };

struct Node
{
	int data;
	Color color;
	Node *left, *right, *parent;
};

class RedBlackTree
{
	private:
		Node *root;
	protected:
		void rotateLeft(Node *&, Node *&);
		void rotateRight(Node *&, Node *&);
		Node* BSTInsert(Node *&, Node *&);
		void InsertFixUp(Node *&, Node *&);
		void deleteFixup(Node *&, Node*&);
		void Transplant(Node *&, Node *&, Node *&);
		Node* TreeMin(Node *);
		Node* TreeMax(Node *);
	public:
		RedBlackTree() { root = nullptr; };
		void insert(int);
		void deleteNode(Node *);
		Node* predecessor(Node *);
		Node* successor(Node *);
		Node* getMinimum();
		Node* getMaximum();
		Node* search(int);
		void levelOrder();
		void PrintNode();
};

#endif