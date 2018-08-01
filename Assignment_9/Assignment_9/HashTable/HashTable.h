/*
	Author: Fezile Manana
*/

#include <iostream>

#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

class Node
{
  public:
	int key;
	int value;

	// Constructors
	Node(){};
	Node(int key, int value);
	~Node(){};
};

class HashTable
{
  private:
	Node **arr;
	int maxSize = 37; // Define m to be prime
	int currentSize = 0;

  public:
	int hashFunc(int key);
	int hashCode(int key);
	void insertNode(int key, int value);
	int get(int key);
	bool isEmpty();

	// Constructors & Destructors
	HashTable();
	~HashTable();
};

HashTable::HashTable()
{
	arr = new Node *[maxSize];
}

HashTable::~HashTable()
{
	delete[] arr;
}

int HashTable::hashFunc(int key)
{
	return ((key % 31) + (key % 13)); // Arbitrary hash function
}

void HashTable::insertNode(int key, int value)
{
	Node *newNode = new Node;
	newNode->key = key;
	newNode->value = value;
	std::cout << "Inserting: " << key << std::endl;
	arr[value] = newNode;
	
	// Incrementing currentSize after insertion
	currentSize++;
}

int HashTable::hashCode(int key)
{
	int i = 0;
	int index;
	while (i != maxSize)
	{
		// Getting the index(position) using linear probing
		index = (hashFunc(key) + i) % maxSize;

		// This ensures that only unique keys are inserted
		if(arr[index] != nullptr && arr[index]->key == key)
		{
			std::cout << "Key already in hash table" << std::endl;
			return -1;
		}

		if(arr[index] == nullptr)
		{
			// Inserting the key into the hash table using the computed index
			insertNode(key, index);
			return index;
		}
		i++;
	}

	std::cerr << "Hash table overflow" << std::endl;
	return -1;
}

int HashTable::get(int key)
{
	int i = 0;
	int index;
	while(i != maxSize)
	{
		index = (hashFunc(key) + i) % maxSize;

		if(arr[index] == nullptr)
			break;
		
		if (arr[index]->key == key)
		{
			std::cout << key << " found at position " << index << std::endl;
			return index;
		}

		i++;
	}

	std::cout << "The key was not found" << std::endl;
	return -1;
}

bool HashTable::isEmpty()
{
	int i = 0;
	while(i != maxSize)
	{
		if(arr[i] != nullptr)
			return false;
		
		i++;
	}

	return true;
}

#endif