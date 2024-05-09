#pragma once
#include <iostream>
#include "List.h"

namespace hashTC
{
	struct Object
	{
		int Size;
		int p = 1000000007;
		char* (*GetKey)(void*);
		listx::Object* Data;

		Object(int size, char* (*f)(void*))
		{
			Size = size;
			GetKey = f;
			Data = new listx::Object[Size];
		};
		int HashFunction(char* key);
		void Insert(void* data);
		listx::Element* Search(char* key);
		void Delete(char* key);
		void Scan(void f(listx::Element*));
	};
	Object Create(int size, char* (*f)(void*));
}