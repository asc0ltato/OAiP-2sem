#pragma once
#define LISTNIL (Element*)-1
namespace listx
{
	struct Element // элемент списка, в котором содержится поле void data, то есть У на данные произвольного типа
	{
		Element* Prev; 
		Element* Next; 
		void* Data;
		Element(Element* prev, void* data, Element* next) // конструктор, в котором задаём У на предыдущий, на следующий и на данные
		{
			Prev = prev; Data = data; Next = next;
		}
		Element* GetNext() { return Next; };
		Element* GetPrev() { return Prev; };
	};

	static Element* NIL = NULL; // статический У NIL

	struct Object // структура Object, в данном случае это список
	{
		Element* Head;

		Object() { Head = NIL; }; // конструктор, который устанавливает У на голову в NULL

		Element* GetFirst() { return Head; }; // простая так как первый Э - голова
		Element* GetLast();

		Element* Search(char* key, char* getkey(void*)); // функция поиска Э-а по ключу
		// в хэш-таблицах сравниваются не все данные, а только ключи и ключи в хэш-таблицах уникальные
		// int getkey(void*) - функция извлечения ключа из Э-а
		bool Insert(void* data); // функция вставки
		bool Delete(Element* e); // удаление по У-лю
		bool Delete(char* key, char* getkey(void*)); // удаление по ключу
		// функции для вывода Э-ов
		void Scan(void(*f)(Element*), Element* e); // вывод одного Э-а
		void Scan(void(*f)(Element*)); // вывод всего списка
	};
	Object Create(); // функция создания нашей структуры Object, можно было бы использовать new
	// этот Create находится в пространстве имён listx
}
#undef LISTNIL 