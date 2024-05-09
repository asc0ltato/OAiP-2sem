#include "Hash_Table.h"
#include "List.h"
#include <iostream>

using namespace hashTC;

int Object::HashFunction(char* key)
{
	int h = 0;
	int a = rand() % (Size - 1) + 1; 
	int b = rand() % (Size - 1) + 1; 
	for (; *key != 0; key++) {
		h = (a * h + *key) % p;
		a = (a * b) % (Size - 1);
	}
	return h % Size;
}

Object hashTC::Create(int size, char* (*getkey)(void*))
{
	return *(new Object(size, getkey));
}

void Object::Insert(void* d)
{
	char* t = GetKey(d), j = HashFunction(t);
	Data[j].Insert(d);
}

listx::Element* Object::Search(char* key)
{
	int j = HashFunction(key);
	return Data[j].Search(key, GetKey);
}

void Object::Delete(char* key)
{
	int j = HashFunction(key);
	Data[j].Delete(key, GetKey);
}

void Object::Scan(void(*f)(listx::Element*))
{
	for (int i = 0; i < this->Size; i++)
	{
		std::cout << "Ячейка " << i + 1 << ": " << std::endl;
		Data[i].Scan(f);
		std::cout << std::endl;
	}
}