//3. Построить хеш - таблицу для зарезервированных слов, используемого языка программирования(не менее 20 слов), содержащую HELP для 
//каждого слова.Выдатье на экран подсказку по введенному слову.Добавить подсказку по вновь введен - ному слову, используя при 
//необходимости реструктуризацию таблицы.

#include "Hash_Table.h"
#include <tchar.h>
#include <locale>
#include <iostream>
#include <cwchar>
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
	int current_size;
	cout << "Введите размер хэш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::Create(current_size, getkeyfromROW);

	const char* stt[] = { "auto","break","case","char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto" };
	const char* rrt[] = { "Спецификатор типа для указания компилятору локальной области видимости переменной","Оператор выхода из цикла",
		"Оператор указания варианта выбора(используется вместе с switch)","Символьный тип данных"," Объекты типа const не могут быть изменены программой во время её выполнения",
		"Оператор продолжения цикла с пропуском оставшихся операторов до конца блока","Оператор выбора по умолчанию","Оператор цикла с постусловием без счётчика",
		"Тип данных с плавающей запятой двойной точности","Условный оператор- в противном случае","Пользовательский тип данных -перечисляемый тип",
		"Спецификатор типа для указания компилятору внешней привязки переменной","Тип данных с плавающей запятой","Оператор цикла с предусловием, с счётчиком",
		"Оператор безусловного перехода" };

	for (int i = 0; i < 15; i++) {
		ROW* b = new ROW((char*)stt[i], (char*)rrt[i]);
		H.Insert(b);

	}
	cout << "В таблице 15 зарезервированных слов" << endl;

	int choise;

	char k[100];

	for (;;) {

		cout << "Меню:" << endl;
		cout << "1 - Вывод всех слов с определениями" << endl;
		cout << "2 - Добавление слова" << endl;
		cout << "3 - Удаление" << endl;
		cout << "4 - Поиск" << endl;
		cout << "0 - Выход" << endl;

		cout << "сделайте выбор" << endl; cin >> choise;

		switch (choise) {
		case 0: exit(0);
		case 1: H.Scan(ROW_print); break;
		case 2:{
			char* str = new char[20];
			char* nstr = new char[200];
			cout << "Введите слово" << endl;
			cin >> str;
			cout << "Введите определение" << endl;
			cin >> nstr;
			ROW* a = new ROW(str, nstr);
			H.Insert(a);
		} break;
		case 3: {
			cout << "Введите слово для удаления" << endl;
			cin >> k;
			H.Delete(k); } break;
		case 4: {cout << "Введите слово для поиска" << endl;
			cin >> k;
			if (H.Search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else ROW_print(H.Search(k)); }
			  break;
		}
	}
	return 0;
}