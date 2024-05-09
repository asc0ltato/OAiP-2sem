#include <iostream>	
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define N 2

using namespace std;

struct University
{
	string name;
	string address;
	string speciality[N];
	int lastYear[N];
	int payment[N];
};

void input(University* university, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите имя университета: ";
		cin >> university[i].name;
		cout << "Введите адрес университета: ";
		cin >> university[i].address;
		for (int j = 0; j < N; j++)
		{
			cout << "Введите специальность: ";
			cin >> university[i].speciality[j];
			cout << "Введите конкурс прошлого года: ";
			cin >> university[i].lastYear[j];
			cout << "Введите размер оплаты: ";
			cin >> university[i].payment[j];
		}
	}
}

void output(University* university, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Имя университета: " << university[i].name << endl;
		cout << "Адрес университета: " << university[i].address << endl;
		for (int j = 0; j < N; j++)
		{
			cout << "Специальность: " << university[i].speciality[j] << endl;
			cout << "Конкурс прошлого года: " << university[i].lastYear[j] << endl;
			cout << "Размер оплаты: " << university[i].payment[j] << endl;
		}
	}
}

void deleteUniversity(University* university, int size, int index)
{
	for (int i = index; i < size - 1; i++)
	{
		university[i] = university[i + 1];
	}
}

void search(University* university, int size, string speciality)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (university[i].speciality[j] == speciality)
			{
				cout << "Имя университета: " << university[i].name << endl;
				cout << "Адрес университета: " << university[i].address << endl;
				cout << "Специальность: " << university[i].speciality[j] << endl;
				cout << "Конкурс прошлого года: " << university[i].lastYear[j] << endl;
				cout << "Размер оплаты: " << university[i].payment[j] << endl;
			}
		}
	}
}

void write(University* university, int size)
{
	ofstream fout("university.txt");
	for (int i = 0; i < size; i++)
	{
		fout << university[i].name << endl;
		fout << university[i].address << endl;
		for (int j = 0; j < N; j++)
		{
			fout << university[i].speciality[j] << endl;
			fout << university[i].lastYear[j] << endl;
			fout << university[i].payment[j] << endl;
		}
		fout << "-----------------------";

	}
	fout.close();
}

void read(University* university, int size)
{
	ifstream fin("university.txt");
	for (int i = 0; i < size; i++)
	{
		fin >> university[i].name;
		fin >> university[i].address;
		for (int j = 0; j < N; j++)
		{
			fin >> university[i].speciality[j];
			fin >> university[i].lastYear[j];
			fin >> university[i].payment[j];
		}
	}
	fin.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	cout << "Введите количество университетов: ";
	cin >> size;
	University* university = new University[size];
	int choice;
	string speciality;
	do
	{
		cout << "1. Ввод данных" << endl;
		cout << "2. Вывод данных" << endl;
		cout << "3. Удаление университета" << endl;
		cout << "4. Поиск по специальности" << endl;
		cout << "5. Запись в файл" << endl;
		cout << "6. Чтение из файла" << endl;
		cout << "7. Выход" << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(university, size);
			break;
		case 2:
			output(university, size);
			break;
		case 3:
			int index;
			cout << "Введите индекс университета: ";
			cin >> index;
			deleteUniversity(university, size, index);
			size--;
			break;
		case 4:
			cout << "Введите специальность: ";
			cin >> speciality;
			search(university, size, speciality);
			break;
		case 5:
			write(university, size);
			break;
		case 6:
			read(university, size);
			break;
		case 7:
			break;
		default:
			cout << "Неверный пункт меню" << endl;
			break;
		}
	} while (choice != 7);
}