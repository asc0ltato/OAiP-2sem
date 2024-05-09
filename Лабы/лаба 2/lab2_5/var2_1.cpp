//Горожанин. Ф.И.О., дата рождения, адрес, пол(м, ж).Выборка по году рождения. Дату рождения организовать с помощью битового поля, пол - с помощью перечисления.
//Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов.Интерфейс пользователя осуществить в виде меню.

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

int i;
int stateMenu;

enum Gender {
	Male,
	Female
};

// Структура даты с помощью битового поля
struct Date {
	unsigned int day : 8;
	unsigned int month : 8;
	unsigned int year : 12;
};

// Структура человека
struct Human {
	string lastName;
	string firstName;
	string patronymic;
	string address;
	Gender gender;
	Date date;
};

// Функция для заполнения структуры человека
void inputHuman(Human& human) {
	cout << "Введите фамилию: ";
	cin >> human.lastName;
	cout << "Введите имя: ";
	cin >> human.firstName;
	cout << "Введите отчество: ";
	cin >> human.patronymic;
	cout << "Введите адрес: ";
	cin >> human.address;
	cout << "Введите пол (0 - Мужской, 1 - Женский): ";
	int gender;
	cin >> gender;
	human.gender = static_cast<Gender>(gender);
	cout << "Введите день рождения(через Enter): ";
	cin >> i;
	human.date.day = i;
	cout << "Введите месяц рождения: ";
	cin >> i;
	human.date.month = i;
	cout << "Введите год рождения: ";
	cin >> i;
	human.date.year = i;
}

// Функция для вывода структуры человека
void outputHuman(Human human) {
	cout << "Фамилия: " << human.lastName << endl;
	cout << "Имя: " << human.firstName << endl;
	cout << "Отчество: " << human.patronymic << endl;
	cout << "Адрес: " << human.address << endl;
	cout << "Пол: ";
	switch (human.gender) {
	case Male:
		cout << "Мужской" << endl;
		break;
	case Female:
		cout << "Женский" << endl;
		break;
	}
	cout << "Дата рождения: " << human.date.day << "." << human.date.month << "." << human.date.year << endl;
}

// Функция для удаления человека по фамилии
void deleteHuman(Human* humans, int& countHumans, string lastName) {
	for (int i = 0; i < countHumans; i++) {
		if (humans[i].lastName == lastName) {
			for (int j = i; j < countHumans - 1; j++) {
				humans[j] = humans[j + 1];
			}
			countHumans--;
			break;
		}
	}
}

// Функция для поиска человека по дате рождения
void searchHuman(Human* humans, int countHumans, int year) {
	for (int i = 0; i < countHumans; i++) {
		if (humans[i].date.year == year) {
			outputHuman(humans[i]);
		}
	}
}

// Функция для вывода всех людей
void outputAllHumans(Human* humans, int countHumans) {
	for (int i = 0; i < countHumans; i++) {
		outputHuman(humans[i]);
	}
}

// Функция для вывода меню
void Menu() {
	cout << "Меню:" << endl
		<< "1. Добавить человека" << endl
		<< "2. Удалить человека" << endl
		<< "3. Вывести всех людей" << endl
		<< "4. Поиск человека по году рождения" << endl
		<< "5. Выход" << endl
		<< "Ваш выбор: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Human* humans = new Human[100];
	string lastName;
	int countHumans = 0;

	Menu();

	while (stateMenu != 5) {
		switch (stateMenu) {
		case 1:
			system("cls");
			inputHuman(humans[countHumans]);
			countHumans++;
			break;
		case 2:
			system("cls");
			cout << "Введите фамилию человека, которого хотите удалить: ";
			cin >> lastName;
			deleteHuman(humans, countHumans, lastName);
			break;
		case 3:
			outputAllHumans(humans, countHumans);
			break;
		case 4:
			system("cls");
			cout << "Введите год рождения: ";
			cin >> i;
			searchHuman(humans, countHumans, i);
			break;
		}
		Menu();
	}
}