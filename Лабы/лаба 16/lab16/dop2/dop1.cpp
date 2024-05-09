//1. Составить хеш - таблицу, содержащую буквы и количество их вхождений во введенной строке.Вывести таблицу на экран.Осуществить поиск введенной буквы в хеш - таблице.

#include <iostream>
#include <Windows.h>
using namespace std;

struct HashTable
{
	char symbol;
	int number = 0;
} ss[26];

void generate();
int getKey(char symbol);
void countValue(int key);
void showElement(int key);
void search(char symbol);
void showAll();

void generate()
{
	for (int i = 0; i < 26; i++)
		ss[i].symbol = i + 97;
}

int getKey(char symbol)
{
	return int(symbol) - 97;
}

void countValue(int key)
{
	ss[key].number++;
}

void showElement(int key)
{
	cout << "Символ" << "\t\tКоличество вхождений\n";
	cout << "\t" << ss[key].symbol << "\t\t\t" << ss[key].number << endl;
}

void search(char symbol)
{
	int key = getKey(symbol);
	showElement(key);
}

void print()
{
	cout << "Символ алфавита" << "\t\tКоличество в строке\n";
	for (int i = 0; i < 26; i++)
		cout << "\t" << ss[i].symbol << "\t\t\t" << ss[i].number << endl;
}


int main()
{
	setlocale(LC_CTYPE, "Rus");
	generate();
	char str[5000];
	cout << "Введите строку: ";  gets_s(str);

	int key = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] - 97 >= 0 && str[i] - 97 < 26)
		{
			key = getKey(str[i]);
			countValue(key);
		}
		if (str[i] - 65 >= 0 && str[i] - 65 < 26)
		{
			key = getKey(str[i] + 32);
			countValue(key);
		}
	}

	int choise;
	char s;
	for (;;)
	{
		cout << "\nВыберите действие \n";
		cout << "1-Вывод таблицы\n";
		cout << "2-Количество вхождений \n";
		cout << "0-Выход\n";
		cin >> choise;

		switch (choise)
		{
		case 0: exit(0);
		case 1: print(); break;
		case 2: cout << "Введите букву латинского алфавита: "; cin >> s; search(s); break;
		default: cout << "Неверный символ";
		}
	}
	return 0;
}