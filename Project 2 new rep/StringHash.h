#pragma once
#include"HashTable.h"

template <class T>
class StringHash :public HashTable<string, T>
{
private:
    int h1(string key) override;
    int h2(string key) override;

public:
    StringHash(int m = 10) :HashTable<string, T>(m) {}
};

template<class T>
inline int StringHash<T>::h1(string key)
{
    long long hashValue = 0;
    int m = this->size;
    if (key.length() <= 8) {
        for (size_t i = 0; i < key.length(); ++i) {
            hashValue += static_cast<unsigned char>(key[i]) * static_cast<long long>(pow(256, i));
            hashValue %= m;
        }
        return static_cast<int>(hashValue % m);
    }
   throw "key is longer than 8";
}

template<class T>
inline int StringHash<T>::h2(string key)
{
    return 1;
}
