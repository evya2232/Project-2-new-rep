#pragma once
#include"HashTable.h"
#include<string>
using namespace std;
template <class T>
class IntHash :public HashTable<int, T>
{
private:
	int h1(int key) override;
	int h2(int key) override;
public:
	IntHash(int m = 10) :HashTable<int, T>(m) {}
};

template<class T>
int IntHash<T>::h1(int k)
{
	return (k % (this->size));
}

template<class T>
int IntHash<T>::h2(int k)
{
	return ((k % ((this->size) - 1)) + 1);
}
