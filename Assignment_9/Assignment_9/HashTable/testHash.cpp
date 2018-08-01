#include <iostream>
#include <ctime>
#include <cstdlib>
#include "HashTable.h"

using namespace std;

int main()
{
	HashTable Table;

	srand(time (NULL));

	if(Table.isEmpty())
		cout << "Table is empty" << endl;
	else
		cout << "Table is not empty" << endl;
	cout << endl;

	for(int i = 0; i < 20; i++)
	{
		Table.hashCode(rand()%50+1);
	}

	cout << endl;
	if(Table.isEmpty())
		cout << "Table is empty" << endl;
	else
		cout << "Table is not empty" << endl;
	cout << endl;

	for(int i = 0; i < 20; i++)
	{
		Table.get(rand() % 10+1);
	}
	cout << endl;
	

	if(Table.isEmpty())
		cout << "Table is empty" << endl;
	else
		cout << "Table is not empty" << endl;
	
	return 0;
}