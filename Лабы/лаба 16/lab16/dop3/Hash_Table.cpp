#include "Hash_Table.h"

using namespace hashTC;

int Object::HashFunction(char* key) {
	int h, a = 31415, b = 27183;
	for (h = 0; *key != 0; key++, a = a * b % (Size - 1))
		h = (a * h + *key) % Size;
	return (h < 0) ? h + Size : h;
}

Object hashTC::Create(int size, char* (*getkey)(void*)) {
	return *(new Object(size, getkey));
}

void Object::Insert(void* d) {
	char* t = GetKey(d), j = HashFunction(t);
	Data[j].Insert(d);
}

listx::Element* Object::Search(char* key) {
	int j = HashFunction(key);
	return Data[j].Search(key, GetKey);
}

void Object::Delete(char* key) {
	int j = HashFunction(key);
	Data[j].Delete(key, GetKey);
}

void Object::Scan(void(*f)(listx::Element*)) {

	for (int i = 0; i < this->Size; i++) {

		std::cout << "Ячейка " << i + 1 << ": " << std::endl;
		Data[i].Scan(f);
		std::cout << std::endl;
	}
}