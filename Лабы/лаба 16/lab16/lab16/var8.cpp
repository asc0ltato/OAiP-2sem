//Аэропорт. Создать хеш-таблицу со следующими
//полями: номер рейса, аэропорт назначения. Ключ – номер рейса.

#include "Hash_Table.h"
#include <tchar.h>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct ROW {
	char* number;
	char* name;

	ROW(char* z, char* n) {
		number = z;
		name = n;
	}

	ROW() {
		number = (char*)""; name = (char*)"";
	}
};

char* getkeyfromROW(void* d) {
	ROW* f = (ROW*)d;
	return f->number;

}

void ROW_print(listx::Element* e) {

	cout << '\t' << ((ROW*)e->Data)->number << " - " << ((ROW*)e->Data)->name << endl;

}

int main(int argc, _TCHAR* argv[]) {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int current_size;
	cout << "Введите размер хэш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::Create(current_size, getkeyfromROW);
	int choise;
	char k[100];
	for (;;) {
		cout << "Меню:" << endl;
		cout << "1 - Вывод всего списка аэропортов " << endl;
		cout << "2 - Добавление нового рейса" << endl;
		cout << "3 - Удаление рейса по номеру" << endl;
		cout << "4 - Поиск" << endl;
		cout << "0 - Выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choise;
		switch (choise) {
		case 0: exit(0);
		case 1: H.Scan(ROW_print); break;
		case 2:
		{
			char* str = new char[20];
			char* nstr = new char[200];
			cout << "Введите номер рейса" << endl;
			cin >> str;
			cout << "Введите аэропорт назначения" << endl;
			cin >> nstr;
			ROW* a = new ROW(str, nstr);
			H.Insert(a);
		} break;
		case 3: {
			cout << "Введите номер " << endl;
			cin >> k;
			H.Delete(k); } break;
		case 4: {cout << "Введите номер " << endl;
			cin >> k;
			if (H.Search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else ROW_print(H.Search(k)); }
			  break;
		}
	}
	return 0;
}