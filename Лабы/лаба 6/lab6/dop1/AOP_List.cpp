//В проекте используется двусвязный список для хранения информации о телефонных номерах.Проект состоит из трех частей: главная функция с именем OAP_List,
//файл List.cpp с функциями пользователя, заголовочный файл List.h.Дополнить проект, разработав функцию deleteList(удаление списка) и функцию countList(подсчет
//числа элементов списка).В содержимом списка отразить информацию в соответствии со своим вариантом из лабораторной работы № 4. Создать интерфейс в виде меню.

#include "List.h"
#include <iostream>
using namespace std;

#include "List.h"
#include <iostream>
using namespace std;

int stateMenu;

struct Person
{
	//Ф.И.О., класс (цифра+буква) предметы, оценки, средний балл
	char firstName[20];
	char lastName[20];
	char patronymic[20];
	string whichClass;
	string subjects[5];
	int marks[5];
	double averageMark;
	Person* next;
};

void print(void* data)
{
	Person* p = (Person*)data;
	cout << "Фамилия: " << p->lastName << endl;
	cout << "Имя: " << p->firstName << endl;
	cout << "Отчество: " << p->patronymic << endl;
	cout << "Класс: " << p->whichClass << endl;
	cout << "Предметы: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << p->subjects[i] << " ";
	}
	cout << endl;
	cout << "Оценки: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << p->marks[i] << " ";
	}
	cout << endl;
	cout << "Средний балл: " << p->averageMark << endl;
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	Person a1 = { "Иванов", "Иван", "Иванович", "11А", {"Математика", "Физика", "Информатика", "История", "География"}, {5, 4, 5, 3, 4}, 4.2 };
	Person a2 = { "Петров", "Петр", "Петрович", "11Б", {"Математика", "Физика", "Информатика", "История", "География"}, {5, 4, 5, 3, 4}, 4.2 };
	Person a3 = { "Сидоров", "Сидор", "Сидорович", "11В", {"Математика", "Физика", "Информатика", "История", "География"}, {5, 4, 5, 3, 4}, 4.2 };

	bool rc;
	Object L1 = Create();   // создание списка с именем L1

	while (stateMenu != 7)
	{
		cout << "1. Создание списка" << endl;
		cout << "2. Вывести список" << endl;
		cout << "3. Найти элемент" << endl;
		cout << "4. Удалить элемент" << endl;
		cout << "5. Количество элементов" << endl;
		cout << "6. Удалить список" << endl;
		cout << "7. Выход" << endl;
		cin >> stateMenu;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный ввод!" << endl;
		}
		switch (stateMenu)
		{
		case 1:
			L1.Insert(&a1);
			L1.Insert(&a2);
			L1.Insert(&a3);
			break;
		case 2:
			L1.PrintList(print);
			break;
		case 3:
		{
			Element* e = L1.Search(&a3);
			Person* aa = (Person*)e->Data;
			cout << "Найден элемент= " << aa->firstName << endl;
		}
		break;
		case 4:
			rc = L1.Delete(&a2);
			if (rc == true) cout << "Удален элемент" << endl;
			cout << "Список:" << endl;
			L1.PrintList(print);
			break;
		case 5:
			cout << "Количество элементов списка= " << L1.CountList() << endl;
			break;
		case 6:
			rc = L1.DeleteList();
			if (rc == true) cout << "Список удален" << endl;
			cout << "Список:" << endl;
			L1.PrintList(print);
			break;
		}
	}
	return 0;
}