#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rbt.h"

using namespace std;

int main()
{
	srand((unsigned) time(0));

	RedBlackTree Tree;

	Node hello;
	hello.data = rand() % 50;
	hello.color = BLACK;
	hello.left = hello.right = hello.parent = nullptr;

	
	
	for(int i = 0; i < 10; i++)
	{
		Tree.insert( rand() % 50 + 1 );
	}
	
	Tree.levelOrder();
	cout << endl;


	//Tree.PrintNode();
	return 0;
}