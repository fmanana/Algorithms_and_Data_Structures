/*
	Author: Fezile Manana
*/

#include <iostream>
#include "rbt.h"


// Helper function to create a new node
Node* CreateNode(int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	/*
		By default a node's color is red as we
		always insert red nodes in the red-black tree.
		The restore function will take care of RBT property
		violations while inserting.
	*/
	newNode->color = RED;
	newNode->parent = newNode->left = newNode->right = nullptr;
	return newNode;
}

void RedBlackTree::rotateLeft(Node *&root, Node *&x)
{
	Node *y = x->right;

	x->right = y->left;

	if(x->right != nullptr)
		x->right->parent = x;

	y->parent = x->parent;

	if(x->parent == nullptr)
		root = y;

	else if (x == x->parent->left)
		x->parent->left = y;

	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
	
}

void RedBlackTree::rotateRight(Node *& root, Node *&x)
{
	Node *y = x->left;
	x->left = y->right;

	if(x->left != nullptr)
		x->left->parent = x;
	
	y->parent = x->parent;

	if(x->parent == nullptr)
		root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->right = x;
	x->parent = y;
}

void RedBlackTree::InsertFixUp(Node *&root, Node *&z)
{
	Node *parent = nullptr;
	Node *grandparent = nullptr;

	while((z != root) && (z->color == RED) && (z->parent != nullptr) && (z->parent->color == RED))
	{
		parent = z->parent;
		grandparent = z->parent->parent;

		if(parent == grandparent->left)
		{
			Node *uncle = grandparent->right;
			/*
				Case 1: The current node's uncle is red.
				Just recolor the parent and uncle.
			*/
			if(uncle != nullptr && uncle->color == RED)
			{
				grandparent->color = RED;
				parent->color = BLACK;
				uncle->color = BLACK;
				z = grandparent;
			}
			else
			{
				/*
					Case 2: The current node is a right child.
					Then we need to left rotate
				*/
				if (z == parent->right)
				{
					z = parent;
					rotateLeft(root, parent);
					parent = z->parent;					
				}
				/*
					Case 3: The current node(z) is a left child.
					Then we right rotate.
				*/
				parent->color = BLACK;
				grandparent->color = RED;
				rotateRight(root, grandparent);
				z = parent;
			}
		}
		else
		{
			Node *uncle = grandparent->left;
			/*
				Case 1: The current node's uncle is red.
				Just recolor the parent and uncle.
			*/
			if(uncle != nullptr && uncle->color == RED)
			{
				grandparent->color = RED;
				parent->color = BLACK;
				uncle->color = BLACK;
				z = grandparent;
			}
			else
			{
				/*
					Case 2: The current node is a right child.
					Then we need to left rotate
				*/
				if (z == parent->left)
				{
					rotateRight(root, parent);
					z = parent;
					parent = z->parent;					
				}
				/*
					Case 3: The current node(z) is a left child.
					Then we right rotate.
				*/	
				parent->color = BLACK;
				grandparent->color = RED;
				rotateLeft(root, grandparent);
				z = parent;
			}
		}
	}
	root->color = BLACK;
}

Node* RedBlackTree::BSTInsert(Node *&root, Node *&newNode)
{
	if (root == nullptr)
        return newNode;

    if (newNode->data < root->data)
	{
        root->left = BSTInsert(root->left, newNode);
        root->left->parent = root;
    }
	else if (newNode->data > root->data)
	{
        root->right = BSTInsert(root->right, newNode);
        root->right->parent = root;
    }

	return root;
}

void RedBlackTree::insert(int data)
{
	Node *newNode = CreateNode(data);
	std::cout << "Inserting: " << data << std::endl;
	root = BSTInsert(root, newNode);
	InsertFixUp(root, newNode);
}

void RedBlackTree::deleteFixup(Node *&root, Node *&x)
{
	Node *w;
	while(x != nullptr && x->color == BLACK)
	{
		if(x == x->parent->left)
		{
			w = x->parent->right;
			if(w != nullptr && w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				rotateLeft(root, x->parent);
				w = x->parent->right;
			}
			if(w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else if(w->right->color == BLACK)
			{
				w->left->color = BLACK;
				w->color = RED;
				rotateRight(root, w);
				w = x->parent->right;
			}
			w->color = x->parent->color;
			x->parent->color = BLACK;
			w->right->color = BLACK;
			rotateLeft(root, x->parent);
			x = root;
		}
		else
		{
			w = x->parent->left;
			if(w != nullptr && w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				rotateRight(root, x->parent);
				w = x->parent->left;
			}
			if(w->right->color == BLACK && w->left->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else if(w->left->color == BLACK)
			{
				w->right->color = BLACK;
				w->color = RED;
				rotateLeft(root, w);
				w = x->parent->left;
			}
		}
		w->color = x->parent->color;
		x->parent->color = BLACK;
		w->left->color = BLACK;
		rotateRight(root, x->parent);
		x = root;
	}
	if(x != nullptr)
		x->color = BLACK;
}

void RedBlackTree::deleteNode(Node *z)
{
	//Exception: Cannot delete emtpy node
	if(z == nullptr)
		return;

	Node *y = search(z->data);
	Node *node = search(z->data);
	Color y_original = y->color;
	Node *x;

	if(node->left == nullptr)
	{
		x = node->right;
		Transplant(root, node, node->right);
	}
	else if(node->right == nullptr)
	{
		x = node->left;
		Transplant(root, node, node->left);
	}
	else
	{
		y = TreeMin(node->right);
		y_original = y->color;
		x = y->right;
		if(y->parent == node && x != nullptr)
			x->parent = y;
		else
		{
			Transplant(root, y, y->right);
			y->right = node->right;
			if(y->right != nullptr)
				y->right->parent = y;
		}
		Transplant(root, y, node);
		y->left = node->left;
		if(y->left != nullptr)
			y->left->parent = y;
		y->color = node->color;
	}

	if(y_original == BLACK)
		deleteFixup(root, x);
	
}

Node* RedBlackTree::getMaximum()
{	
	if(root == nullptr)
		throw "Tree is empty!";

	Node *max = root;
	while(max->right != nullptr)
		max = max->right;
	
	return max;
}

Node* RedBlackTree::getMinimum()
{
	if(root == nullptr)
		throw "Tree is empty!";
	
	Node *min = root;
	while(min->left != nullptr)
		min = min->left;
	
	return min;
}
void RedBlackTree::Transplant(Node *&root, Node *&u, Node *&v)
{
	if(v == nullptr)
		return;
	
	if(u->parent == nullptr)
		root = v;
	else if(u != nullptr && u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if(v != nullptr)
		v->parent = u->parent;
}

Node* RedBlackTree::successor(Node *node)
{
	Node *temp = nullptr;
	if (node->left != nullptr)
	{
		temp = node->left;
		while (temp->right != nullptr)
			temp = temp->right;
	}
	else
	{
		temp = node->right;
		while (temp->left != nullptr)
			temp = temp->left;
	}
	return temp;
}

Node* RedBlackTree::predecessor(Node *node)
{
	Node *temp = nullptr;
	if (node->right != nullptr)
	{
		temp = node->right;
		while (temp->left != nullptr)
			temp = temp->left;
	}
	else
	{
		temp = node->left;
		while (temp->right != nullptr)
			temp = temp->right;
	}
	return temp;
}

//	Helper function that finds the minimum value in a subtree
Node* RedBlackTree::TreeMin(Node *node)
{
	Node *min = node;

	while(min->left != nullptr)
		min = min->left;

	return min;
}

//	Helper function that finds the maximum value in a subtree
Node* RedBlackTree::TreeMax(Node *node)
{
	Node *max = node;

	while(max->right != nullptr)
		max = max->right;

	return max;	
}

Node* RedBlackTree::search(int value)
{
	Node *p = root;
	int flag = 0;
	if (root == nullptr)
	{
		std::cerr << "Tree is Empty" << std::endl;
		return root;
	}
	
	while (p != nullptr && flag == 0)
	{
		if (p->data == value)
			flag = 1;
		if (flag == 0)
		{
			if (p->data < value)
				p = p->right;
			else
				p = p->left;
		}
	}
	if (flag == 0)
	{
		std::cout << "Element is Not Found" << std::endl;
		return root;
	}
	else
	{
		
		std::cout << "Node was found." << std::endl;
		return p;
	}
}

void RedBlackTree::PrintNode()
{
	std::cout << root->parent->parent->data << std::endl;
}

void levelOrderHelper(Node *root) // Print in preorder
{   
	//Exception
	if(root == nullptr)
		return;
	
	if(root->color == BLACK)
		std::cout << root->data << "B ";
	else if(root->color == RED)
		std::cout << root->data << "R ";
	
	levelOrderHelper(root->left);
	
	levelOrderHelper(root->right);
}

void RedBlackTree::levelOrder()
{
	levelOrderHelper(root);
}