// Клиенты банка. Ф.И.О., тип счета(срочный, льготный и т.д.), номер счета, сумма на счете, дата последнего изменения.Выбор по номеру счета.
//Реализовать функции ввода с клавиатуры, вывода на экран и поиска.

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

int stateMenu;

// Перечисление типов счетов
enum TypeAccount {
	Current,
	Debit,
	Credit,
};

// Дата через union
union Date {
	struct {
		int day;
		int month;
		int year;
	};
	int date[3];
};

// Структура клиента
struct Client {
	string firstName;
	string lastName;
	string patronymic;
	TypeAccount typeAccount;
	int numberAccount;
	int sumAccount;
	Date dateLastChange;
};

// Функция для ввода даты
void InputDate(Date& date) {
	cout << "Введите день: ";
	cin >> date.day;
	cout << "Введите месяц: ";
	cin >> date.month;
	cout << "Введите год: ";
	cin >> date.year;
}

// Функция для ввода клиента
void InputClient(Client& client)
{
	cout << "Введите фамилию: ";
	cin >> client.lastName;
	cout << "Введите имя: ";
	cin >> client.firstName;
	cout << "Введите отчество: ";
	cin >> client.patronymic;
	cout << "Выберите тип счета (0 - текущий, 1 - дебетовый, 2 - кредитный): ";
	int type;
	cin >> type;
	switch (type) {
	case 0:
		client.typeAccount = Current;
		break;
	case 1:
		client.typeAccount = Debit;
		break;
	case 2:
		client.typeAccount = Credit;
		break;
	default:
		cout << "Неверный тип счета!" << endl;
		break;
	}
	cout << "Введите номер счета: ";
	cin >> client.numberAccount;
	cout << "Введите сумму на счете: ";
	cin >> client.sumAccount;
	cout << "Введите дату последнего изменения: " << endl;
	InputDate(client.dateLastChange);
}

// Функция для вывода клиента
void OutputClient(Client& client) {
	cout << "Фамилия: " << client.lastName << endl;
	cout << "Имя: " << client.firstName << endl;
	cout << "Отчество: " << client.patronymic << endl;
	cout << "Тип счета: ";
	switch (client.typeAccount) {
	case 0:
		cout << "Текущий" << endl;
		break;
	case 1:
		cout << "Дебетовый" << endl;
		break;
	case 2:
		cout << "Кредитный" << endl;
		break;
	default:
		cout << "Неверный тип счета!" << endl;
		break;
	}
	cout << "Номер счета: " << client.numberAccount << endl;
	cout << "Сумма на счете: " << client.sumAccount << endl;
	cout << "Дата последнего изменения: " << client.dateLastChange.day << "." << client.dateLastChange.month << "." << client.dateLastChange.year << endl;
}

// Функция для вывода всех клиентов
void OutputAllClients(Client* clients, int size) {
	for (int i = 0; i < size; i++) {
		OutputClient(clients[i]);
		cout << endl;
	}
}

// Функция для поиска клиента по номеру счета
void SearchClient(Client* clients, int size) {
	int numberAccount;
	cout << "Введите номер счета: ";
	cin >> numberAccount;
	for (int i = 0; i < size; i++) {
		if (clients[i].numberAccount == numberAccount) {
			OutputClient(clients[i]);
			cout << endl;
		}
	}
}

// Функция меню
void Menu() {
	cout << "1. Ввести данные о клиенте" << endl;
	cout << "2. Вывести данные о всех клиентах" << endl;
	cout << "3. Поиск клиента по номеру счета" << endl;
	cout << "4. Выход" << endl;
	cout << "Выберите пункт меню: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Client* clients = new Client[10];
	int size = 0;

	while (true) {
		Menu();
		switch (stateMenu)
		{
		case 1:
			InputClient(clients[size]);
			size++;
			break;
		case 2:
			OutputAllClients(clients, size);
			break;
		case 3:
			SearchClient(clients, size);
			break;
		case 4:
			return 0;
		default:
			cout << "Неверный пункт меню!" << endl;
			break;
		}
	}
}