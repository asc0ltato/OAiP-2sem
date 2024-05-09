//4. В текстовом файле содержатся целые числа.Построить хеш - таблицу из чисел файла.Осуществить поиск введенного целого числа в хеш - таблице.
//Сравнить результаты количества сравнений при различном наборе данных в файле.

#include "Header.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include <fstream>
#include "List.h"

using namespace std;

struct AAA
{
	int key;
	int mas;
	AAA(int k, int z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = 0;
	}
};
//-------------------------------
int hf(void* d) //Функция создания указателя как информационного элемента списка
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
void foutF(ofstream& f, char* name);

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream input;
	ifstream output;
	setlocale(LC_ALL, "rus");                                                            
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int current_size = 0;                                                                                                            
	cout << "Введите размер хеш-таблицы: ";                                      
	cin >> current_size;                                                                 
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)																			
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "5 - заполнение хэш-таблицы из файла" << endl;
		cout << "0 - выход" << endl;
		cout << "Сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;                                           
			char* str = new char[100];                                             
			cout << "Введите ключ: ";
			cin >> k;                                                              
			a->key = k;                                                            
			cout << "Введите число: ";
			cin >> k;
			a->mas = k;
			H.insert(a);                                                          
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "Введите число: ";
			cin >> k;
			b->mas = k;
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "Введите число: ";
			cin >> k;
			c->mas = k;
			H.Scan1(c);
		}
			  break;
		case 5:
		{
			char* str = new char[100];
			char words[14][50];
			char buf[25];
			cout << "Введите имя файла для чтения: ";
			cin.ignore();
			cin.getline(str, 100);
			output.open(str);
			if (!output.is_open()) {
				cout << "Ошибка открытия файла \"" << str << "\": ";
				perror("");
			}
			else
			{
				int i = 0;
				output.getline(buf, 25);
				do
				{
					strcpy_s(*(words + i), 50, buf);
					i++;
				} while (output.getline(buf, 50));
				for (int i = 0; i < H.sizeO - 1; i++)
				{
					AAA* a = new AAA;
					k = 0 + rand() % H.sizeO;
					a->key = k;
					a->mas = atoi(*(words + (0 + rand() % 14)));
					H.insert(a);
				}
				output.close();
			}
		}
		break;
		case 6:
		{
			char* str = new char[100];
			cout << "Введите имя файла для записи: ";
			cin.ignore();
			cin.getline(str, 100);
			foutF(input, str);
		}
		break;
		}
	}
	return 0;
}

void foutF(ofstream& f, char* name)
{
	f.open(name);
	for (int i = 0; i < 14; i++)
	{
		f << 0 + rand() % 1000 << endl;
	}
	f.close();
}