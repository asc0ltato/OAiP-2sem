//Ф.И.О., тип счета(срочный, льготный и т.д.), номер счета, сумма на счете, дата последнего изменения.
//Выбор по диапазону суммы(< 100, >100). Дату реализовать с помощью битового поля, тип счета - с помощью перечисления.
//Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов.Интерфейс пользователя осуществить в виде меню.

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

int i;
int stateMenu;

// Тип счета
enum AccountType {
	Current,
	Debit,
	Credit
};

// Структура даты с помощью битового поля
struct Date {
	unsigned int day : 8;
	unsigned int month : 8;
	unsigned int year : 12;
};

// Структура счета
struct Account {
	string lastName;
	string firstName;
	string patronymic;
	AccountType accountType;
	string accountNumber;
	int amount;
	Date date;
};

// Функция для заполнения структуры счета
void inputAccount(Account& account) {
	cout << "Введите фамилию: ";
	cin >> account.lastName;
	cout << "Введите имя: ";
	cin >> account.firstName;
	cout << "Введите отчество: ";
	cin >> account.patronymic;
	cout << "Введите тип счета (0 - Текущий, 1 - Дебетовый, 2 - Кредитный): ";
	int accountType;
	cin >> accountType;
	account.accountType = static_cast<AccountType>(accountType);
	cout << "Введите номер счета: ";
	cin >> account.accountNumber;
	cout << "Введите сумму на счете: ";
	cin >> account.amount;
	cout << "Введите день последнего изменения: ";
	cin >> i;
	account.date.day = i;
	cout << "Введите месяц последнего изменения: ";
	cin >> i;
	account.date.month = i;
	cout << "Введите год последнего изменения: ";
	cin >> i;
	account.date.year = i;
}

// Функция для вывода структуры счета
void outputAccount(Account& account) {
	cout << "Фамилия: " << account.lastName << endl;
	cout << "Имя: " << account.firstName << endl;
	cout << "Отчество: " << account.patronymic << endl;
	cout << "Тип счета: " << (account.accountType == Current ? "Текущий" : account.accountType == Debit ? "Дебетовый" : "Кредитный") << endl;
	cout << "Номер счета: " << account.accountNumber << endl;
	cout << "Сумма на счете: " << account.amount << endl;
	cout << "Дата последнего изменения: " << account.date.day << "." << account.date.month << "." << account.date.year << endl;
}

// Функция удаления счета по номеру счета
void deleteAccount(Account* accounts, int& count) {
	string accountNumber;
	cout << "Введите номер счета: ";
	cin >> accountNumber;
	for (int i = 0; i < count; i++) {
		if (accounts[i].accountNumber == accountNumber) {
			for (int j = i; j < count - 1; j++) {
				accounts[j] = accounts[j + 1];
			}
			count--;
			cout << "Счет удален" << endl;
			return;
		}
	}
	cout << "Счет не найден" << endl;
}

// Функция для вывода счетов по диапазону суммы
void outputAccountsByAmount(Account* accounts, int& count) {
	int minAmount;
	int maxAmount;
	cout << "Введите минимальную сумму: ";
	cin >> minAmount;
	cout << "Введите максимальную сумму: ";
	cin >> maxAmount;
	for (int i = 0; i < count; i++) {
		if (accounts[i].amount >= minAmount && accounts[i].amount <= maxAmount) {
			outputAccount(accounts[i]);
		}
	}
}

// Вывод всех счетов
void outputAllAccounts(Account* accounts, int& count) {
	for (int i = 0; i < count; i++) {
		outputAccount(accounts[i]);
	}
}

// Меню
void Menu() {
	cout << "1. Добавить счет" << endl;
	cout << "2. Удалить счет" << endl;
	cout << "3. Вывести все счета" << endl;
	cout << "4. Вывести счета по диапазону суммы" << endl;
	cout << "5. Выход" << endl;
	cout << "Введите номер пункта меню: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Account* accounts = new Account[100];
	int count = 0;

	while (stateMenu != 5) {
		Menu();
		switch (stateMenu) {
		case 1:
			system("cls");
			inputAccount(accounts[count]);
			count++;
			break;
		case 2:
			system("cls");
			deleteAccount(accounts, count);
			break;
		case 3:
			outputAllAccounts(accounts, count);
			break;
		case 4:
			system("cls");
			outputAccountsByAmount(accounts, count);
			break;
		case 5:
			break;
		default:
			cout << "Неверный пункт меню" << endl;
			break;
		}
	}
}