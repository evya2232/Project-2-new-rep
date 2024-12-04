#pragma once
#include <iostream>
#include "PrimeUtil.h"
#include <cmath>
#include <stdexcept>


using namespace std;
//the status of the cell in the table
enum state { EMPTY, FULL, DELETED };

template<class K, class T>
class HashTable {
protected:

	class Item // a helper class, represents a single item in a table
	{
	public:
		T data;			//The record information
		K key;			//The record key
		state flag;		//An indicator for the vacancy of the cell if full or empty

		//******** Constructors *******

		Item() : data(T()), key(K()), flag(EMPTY) {}
		Item(K k, T d) { data = d; key = k; flag = FULL; }
	};

	int size;      // prime number for size of the table 
	Item* table;   // a pointer to an array of items of unknown size

	virtual int h1(K key) = 0;
	virtual int h2(K key) = 0;

	int hash(K k, int i);      ////A function that returns the position in the table for a key k in attempt i

public:

	//******** Constructors *******

	HashTable(int m = 10);    // contructor 
	~HashTable();             //distractor
	void print();
	T& search(K k);
	void insert(K k, T t);
	void remove(K k);
};





///////implementation:////////


template<class K, class T>
int HashTable<K, T>::hash(K k, int i) {//A function that returns the position in the table for a key k in attempt i

	return (h1(k) + i * h2(k)) % size;
}

inline int closestPrime(int n) {// A function to find the closest prime number
	if (PrimeUtil::prime(n)) return n; // if this number is prime

	int upper = n + 1; // check up

	while (true) {
		if (PrimeUtil::prime(upper)) return upper;             // If we found a bigger prime number
		++upper; // continue check up
	}
}

template<class K, class T >
HashTable<K, T>::HashTable(int m)   // constructor 
{
	size = closestPrime(m);// Finding the prime number closest to the desired size
	table = new Item[size];// create new array of items in size of size
}

template<class K, class T>
HashTable<K, T>::~HashTable()   //distractor
{
	delete[] table;
}


template<class K, class T>
inline void HashTable<K, T>::print() // print all the items in the table 
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].flag == FULL)
			cout << i << ":\t" << table[i].key << '\n';
		else if (table[i].flag == DELETED)
			cout << i << ":\t" << "DELETED" << '\n';
	}
}

template<class K, class T>
T& HashTable<K, T>::search(K k) {

	int index;
	for (int i = 0; i < size;i++)
	{
		 index = hash(k, i);

		if (table[index].flag == DELETED) 
			continue;
		if (table[index].flag == FULL) {
			if (table[index].key == k)
				return table[index].data;
			else
				continue;
		}
		else
			throw "Key does not exist in table";
	}
	throw "Key does not exist in table";
}
template<class K, class T>
void HashTable<K, T>::insert(K k, T data)
{
	int i;
	int index;

	for (i = 0;; i++) {
		index = hash(k, i);
		if (table[index].flag == EMPTY || table[index].flag == DELETED) {
			table[index].data = data;
			table[index].key = k;
			table[index].flag = FULL;
			break;
	    }
	}
	if (i >= size)
		throw "table is full";
}


template<class K, class T>
inline void HashTable<K, T>::remove(K k) {
	int i = 0;
	int index = hash(k, i);
	bool found = false;

	while (i < size) {
		if (table[index].flag == EMPTY) {
			if (!found) throw "Key not found in table";
			return;
		}
		if (table[index].flag == FULL && table[index].key == k) {
			table[index].flag = DELETED;
			found = true;
		}
		index = hash(k, ++i);
	}
	if (!found) throw "Key not found in table";
}


