//oneByOne(Object& To, Object& from1, Object& from2) - функцию, которая формирует список To, включив в него поочередно элементы из списков from1 и from2.

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};

//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
//-----------------------------------------------------------
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)          //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}
//-----------------------------------------------------------
// returnN – функция возвращения истинного значения, если список пуст и возвращение ложного в противном случае.

bool returnN(Address** phead) 
{
	if (*phead == NULL)
		return true;
	else
		return false;
}

//-----------------------------------------------------------
// Функция, которая формирует список C, включив в него поочередно элементы из списков A и B. Списки A и B будут создаваться в этой функции.
// Вариант 8
void oneByOne()
{
	// Создание списка A и B
	Address* pheadA = NULL, * plastA = NULL;
	Address* pheadB = NULL, * plastB = NULL;
	Address* pheadC = NULL, * plastC = NULL;
	Address* t;

	// Заполнение списка A
	cout << "Количество элементов списка A: " << endl;
	int n;
	cin >> n;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	for (int i = 0; i < n; i++)
	{
		insert(setElement(), &pheadA, &plastA);
	}

	// Заполнение списка B
	cout << "Количество элементов списка B: " << endl;
	int m;
	cin >> m;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	for (int i = 0; i < m; i++)
	{
		insert(setElement(), &pheadB, &plastB);
	}

	// Вывод списков A и B
	cout << "Список A:" << endl;
	outputList(&pheadA, &plastA);
	cout << "Список B:" << endl;
	outputList(&pheadB, &plastB);

	// Формирование списка C путем поочередного добавления элементов из списков A и B.
	// Пока хотя бы один из списков не пустой, добавляем элементы в список C.
	while (!returnN(&pheadA) || !returnN(&pheadB))
	{
		// Если список A не пустой, добавляем его элемент в список C
		if (!returnN(&pheadA))
		{
			t = pheadA;
			pheadA = pheadA->next;
			insert(t, &pheadC, &plastC);
		}

		// Если список B не пустой, добавляем его элемент в список C
		if (!returnN(&pheadB))
		{
			t = pheadB;
			pheadB = pheadB->next;
			insert(t, &pheadC, &plastC);
		}
	}

	// Вывод списка C
	cout << "Список C:" << endl;
	outputList(&pheadC, &plastC);
}

//-----------------------------------------------------------


int menu(void)
{
	char s[80];
	int c;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Считывание из файла" << endl;
	cout << "7. Функция oneByOne " << endl;
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 11);
	return c;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	Address* head = NULL;
	Address* last = NULL;

	char name[NAME_SIZE];
	int c;
	while (true)
	{
		switch (menu())
		{
		case 1:
			insert(setElement(), &head, &last);
			break;
		case 2:
			cout << "Введите имя: ";
			cin.getline(name, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync(); // cin.clear() - вроде как разницы нет
			delet(name, &head, &last);
			break;
		case 3:
			outputList(&head, &last);
			break;
		case 4:
			cout << "Введите имя: ";
			cin.getline(name, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync(); // cin.clear() - вроде как разницы нет
			find(name, &head);
			break;
		case 5:
			writeToFile(&head);
			break;
		case 6:
			readFromFile(&head, &last);
			break;
		case 7:
			oneByOne();
			break;
		case 8:
			exit(0);
		default: exit(1);
		}
	}
	return 0;
}