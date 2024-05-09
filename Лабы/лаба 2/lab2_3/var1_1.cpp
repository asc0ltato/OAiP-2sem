//Отдел кадров. Ф.И.О.работника, образование, специальность, подразделение, должность, оклад, дата поступления на предприятие.
//Выбор по стражу работы.Даты реализовать с помощью битового поля, должность - с помощью перечисления.
//Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов.Интерфейс пользователя осуществить в виде меню.

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

int i;
int stateMenu;

enum Position {
	Director,
	Manager,
	Engineer,
	Worker
};

// Структура даты с помощью битового поля
struct Date {
	unsigned int day : 8;
	unsigned int month : 8;
	unsigned int year : 12;
};

// Структура сотрудника
struct Employee {
	string lastName;
	string firstName;
	string patronymic;
	string education;
	string specialty;
	string department;
	Position position;
	int salary;
	Date date;
};

// Функция ввода информации о сотруднике
void inputEmployee(Employee& employee) {
	cout << "Введите фамилию: ";
	cin >> employee.lastName;
	cout << "Введите имя: ";
	cin >> employee.firstName;
	cout << "Введите отчество: ";
	cin >> employee.patronymic;
	cout << "Введите образование: ";
	cin >> employee.education;
	cout << "Введите специальность: ";
	cin >> employee.specialty;
	cout << "Введите подразделение: ";
	cin >> employee.department;
	cout << "Введите должность (0 - Директор, 1 - Менеджер, 2 - Инженер, 3 - Рабочий): ";
	int position;
	cin >> position;
	employee.position = static_cast<Position>(position);
	cout << "Введите оклад: ";
	cin >> employee.salary;
	cout << "Введите дату поступления на предприятие(через Enter): ";
	cin >> i;
	employee.date.day = i;
	cin >> i;
	employee.date.month = i;
	cin >> i;
	employee.date.year = i;
}

// Функция вывода информации о сотруднике
void printEmployee(Employee employee) {
	cout << "Фамилия: " << employee.lastName << endl;
	cout << "Имя: " << employee.firstName << endl;
	cout << "Отчество: " << employee.patronymic << endl;
	cout << "Образование: " << employee.education << endl;
	cout << "Специальность: " << employee.specialty << endl;
	cout << "Подразделение: " << employee.department << endl;
	cout << "Должность: ";
	switch (employee.position) {
	case Director:
		cout << "Директор" << endl;
		break;
	case Manager:
		cout << "Менеджер" << endl;
		break;
	case Engineer:
		cout << "Инженер" << endl;
		break;
	case Worker:
		cout << "Рабочий" << endl;
		break;
	}
	cout << "Оклад: " << employee.salary << endl;
	cout << "Дата поступления на предприятие: " << employee.date.day << "." << employee.date.month << "." << employee.date.year << endl;
}

// Функция удаления сотрудника по фамилии
void deleteEmployee(Employee* employees, int& count, const string& lastName) {
	for (int i = 0; i < count; i++) {
		if (employees[i].lastName == lastName) {
			for (int j = i; j < count - 1; j++) {
				employees[j] = employees[j + 1];
			}
			count--;
			break;
		}
	}
}

// Выбор по стажу работы
void selectByExperience(Employee* employees, int count) {
	cout << "Введите стаж работы: ";
	int experience;
	cin >> experience;
	for (int i = 0; i < count; i++) {
		if (employees[i].date.year <= 2023 - experience) {
			printEmployee(employees[i]);
		}
	}
}

// Функция вывода всех сотрудников
void printAllEmployees(Employee* employees, int count) {
	for (int i = 0; i < count; i++) {
		printEmployee(employees[i]);
	}
}

// Главное меню
void Menu() {
	cout << "Меню:" << endl
		<< "1. Добавить работника" << endl
		<< "2. Удалить работника" << endl
		<< "3. Поиск по стажу" << endl
		<< "4. Вывести всех работников" << endl
		<< "5. Выход" << endl
		<< "Ваш выбор: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Employee* employees = new Employee[100];
	string lastName;
	int count = 0;
	do
	{
		Menu();
		switch (stateMenu) {
		case 1:
			system("cls");
			inputEmployee(employees[count]);
			count++;
			cout << "Рабочий добавлен!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Введите фамилию работника: ";
			cin >> lastName;
			deleteEmployee(employees, count, lastName);
			break;
		case 3:
			selectByExperience(employees, count);
			break;
		case 4:
			printAllEmployees(employees, count);
			break;
		case 5:
			return 0;
		default:
			cout << "Неверный ввод!" << endl;
			Menu();
			break;
		}
	} while (stateMenu != 5);
	delete[] employees;
	return 0;
}