//Создать проект, демонстрирующий работу со стеком, организованным на основе списка, в соответствии со своим вариантом для данных из таблицы ниже.
//Все операции со стеком реализовать через функции.Дополнить проект функциями очистки стека clear(), сохранения в файл и считывания из файла.
//Проект должен содержать три части : главная функция, файл с функциями работы со стеком и заголовочный файл.Создать интерфейс в виде меню.
//Разработать функцию, которая по одному стеку строит два новых : Stack1 из элементов, значение которых превышает число 50, и Stack2 - из остальных элементов.

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "myStack.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stack* top = NULL;
	Stack* top1 = NULL;
	Stack* top2 = NULL;
	int n;
	int choice;
	do
	{
		cout << "Выберите команду:" << endl;
		cout << "1. Ввод стека" << endl;
		cout << "2. Вывод стека" << endl;
		cout << "3. Запись стека в файл" << endl;
		cout << "4. Чтение стека из файла" << endl;
		cout << "5. Очистка стека" << endl;
		cout << "6. Создание двух стеков" << endl;
		cout << "7. Вывод двух стеков" << endl;
		cout << "8. Выход" << endl;
		cout << "Ваш выбор: ";
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
			cout << "Введите количество элементов: ";
			cin >> n;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Неверный ввод!" << endl;
			}
			createStack(top, n);
			break;
		case 2:
			print(top);
			break;
		case 3:
			writeToFile(top, "stack.txt");
			break;
		case 4:
			readFromFile(top, "stack.txt");
			break;
		case 5:
			clear(top);
			break;
		case 6:
			createStacks(top, top1, top2);
			break;
		case 7:
			cout << "Стек 1( > 50 ): ";
			print(top1);
			cout << "Стек 2( <= 50 ): ";
			print(top2);
			break;
		}
	} while (choice != 8);
	return 0;
}