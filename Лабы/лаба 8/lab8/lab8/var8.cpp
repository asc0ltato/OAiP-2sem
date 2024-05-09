//Создать проект из нескольких файлов, демонстрирующий работу с очередью.В соответствии со своим вариантом выполнить задание из таблицы, представленной ниже.
//Разработать меню и реализовать все операции с очередью через функции. Максимальный размер очереди ввести с клавиатуры.
//Создать очередь для целых чисел и функции для ввода, вывода, удаления и определения размера очереди.
//Разработать функцию, которая удаляет из очереди первый отрицательный элемент, если такой есть.

#include <iostream>
#include "myQueue.h"
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Queue* first = NULL; //указывает на первый элемент в очереди (этот будет извлечен из очереди при удалении)
	Queue* last = NULL; // указывает на последний элемент в очереди (был добавлен последним при добавлении)
	int n; 
	cout << "Введите количество элементов очереди: "; 
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Неверный ввод!" << endl;
	}
	system("cls");
	int choice;
	do
	{
		cout << "1. Ввод очереди" << endl;
		cout << "2. Вывод очереди" << endl;
		cout << "3. Удаление элемента из очереди" << endl;
		cout << "4. Размер очереди" << endl;
		cout << "5. Удаление первого отрицательного элемента" << endl;
		cout << "6. Выход" << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный ввод!" << endl;
		}
		switch (choice)
		{
		case 1:
			InputQueue(first, last, n);
			break;
		case 2:
			OutputQueue(first);
			break;
		case 3:
			DeleteElement(first, last);
			break;
		case 4:
			cout << "Размер очереди: " << SizeQueue(first) << endl;
			break;
		case 5:
			DeleteFirstNegativeElement(first, last);
			break;
		case 6:
			return 0;
		default:
			cout << "Неверный пункт меню!" << endl;
			break;
		}
	} while (choice != 6);
}