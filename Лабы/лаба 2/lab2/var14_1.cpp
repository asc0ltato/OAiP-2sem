//Паспортные данные, даты приезда и отъезда, номер, тип размещения(люкс, одноместный, двухместный, трехместный, апартаменты).
//Поиск гостя по дате приезда.Даты приезда и отъезда реализовать с помощью битового поля, тип размещения - с помощью перечисления.

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

int i;
int stateMenu;

// Перечисление типов размещения
enum AccommodationType {
	LUXURY = 1,
	SINGLE,
	TWO,
	TRIPLE,
	APARTMENT
};

// Структура даты приезда и отъезда с помощью битового поля
struct Date {
	unsigned int arrivedDay : 5;
	unsigned int arrivedMonth : 5;
	unsigned int arrivedYear : 12;
	unsigned int leftDay : 5;
	unsigned int leftMonth : 5;
	unsigned int leftYear : 12;
};

// Сам гость
struct Guest {
	string firstName;
	string lastName;
	string passportNumber;
	Date dateIn;
	Date dateOut;
	int roomNumber;
	AccommodationType accommodationType;
};

// Ввод гостя
void inputGuest(Guest& guest) {
	cout << "Введите фамилию: ";
	cin >> guest.lastName;
	cout << "Введите имя: ";
	cin >> guest.firstName;
	cout << "Введите номер паспорта: ";
	cin >> guest.passportNumber;
	cout << "Введите дату приезда(через enter): ";
	cin >> i;
	guest.dateIn.arrivedDay = i;
	cin >> i;
	guest.dateIn.arrivedMonth = i;
	cin >> i;
	guest.dateIn.arrivedYear = i;
	cout << "Введите дату отъезда(через enter): ";
	cin >> i;
	guest.dateOut.leftDay = i;
	cin >> i;
	guest.dateOut.leftMonth = i;
	cin >> i;
	guest.dateOut.leftYear = i;
	cout << "Введите номер комнаты: ";
	cin >> guest.roomNumber;
	cout << "Введите тип размещения (1 - Люкс, 2 - Одноместный, 3 - Двухместный, 4 - Трехместный, 5 - Апартаменты): ";
	int accommodationType;
	cin >> accommodationType;
	guest.accommodationType = static_cast<AccommodationType>(accommodationType);
}

// Вывод гостя
void outputGuest(const Guest& guest) {
	cout << "Фамилия: " << guest.lastName << endl;
	cout << "Имя: " << guest.firstName << endl;
	cout << "Номер паспорта: " << guest.passportNumber << endl;
	cout << "Дата приезда: " << guest.dateIn.arrivedDay << "." << guest.dateIn.arrivedMonth << "." << guest.dateIn.arrivedYear << endl;
	cout << "Дата отъезда: " << guest.dateOut.leftDay << "." << guest.dateOut.leftMonth << "." << guest.dateOut.leftYear << endl;
	cout << "Номер комнаты: " << guest.roomNumber << endl;
	cout << "Тип размещения: ";
	switch (guest.accommodationType) {
	case LUXURY:
		cout << "Люкс" << endl;
		break;
	case SINGLE:
		cout << "Одноместный" << endl;
		break;
	case TWO:
		cout << "Двухместный" << endl;
		break;
	case TRIPLE:
		cout << "Трехместный" << endl;
		break;
	case APARTMENT:
		cout << "Апартаменты" << endl;
		break;
	}
}

// Удаление по фамилии
void deleteGuest(Guest* guests, int& guestsCount, const string& lastName) {
	for (int i = 0; i < guestsCount; i++) {
		if (guests[i].lastName == lastName) {
			for (int j = i; j < guestsCount - 1; j++) {
				guests[j] = guests[j + 1];
			}
			guestsCount--;
			break;
		}
	}
}

// Поиск по дате приезда
void searchGuest(Guest* guests, int& guestsCount, const Date& dateIn) {
	for (int i = 0; i < guestsCount; i++) {
		if (guests[i].dateIn.arrivedDay == dateIn.arrivedDay && guests[i].dateIn.arrivedMonth == dateIn.arrivedMonth && guests[i].dateIn.arrivedYear == dateIn.arrivedYear) {
			outputGuest(guests[i]);
		}
	}
}

// Вывод всех имеющихся гостей
void outputAllGuests(Guest* guests, int& guestsCount) {
	for (int i = 0; i < guestsCount; i++) {
		outputGuest(guests[i]);
	}
}

// Главное меню
void Menu() {
	cout << "Меню:" << endl
		<< "1. Добавить гостя" << endl
		<< "2. Удалить гостя" << endl
		<< "3. Поиск по дате приезда" << endl
		<< "4. Вывести всех гостей" << endl
		<< "5. Выход" << endl
		<< "Ваш выбор: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Guest* guests = new Guest[1];
	int guestsCount = 0;

	Menu();

	while (stateMenu != 5) {
		switch (stateMenu) {
		case 1: {
			system("cls");
			Guest* temp = new Guest[guestsCount + 1];
			for (int i = 0; i < guestsCount; i++) {
				temp[i] = guests[i];
			}
			delete[] guests;
			guests = temp;
			inputGuest(guests[guestsCount]);
			guestsCount++;
			cout << "Гость добавлен!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		} case 2: {
			string lastName;
			cout << "Введите фамилию гостя: ";
			cin >> lastName;
			deleteGuest(guests, guestsCount, lastName);
			Menu();
			break;
		} case 3: {
			Date dateIn;
			cout << "Введите дату приезда: ";
			cin >> i;
			dateIn.arrivedDay = i;
			cin >> i;
			dateIn.arrivedMonth = i;
			cin >> i;
			dateIn.arrivedYear = i;
			searchGuest(guests, guestsCount, dateIn);
			Menu();
			break;
		} case 4: {
			outputAllGuests(guests, guestsCount);
			Menu();
			break;
		} case 5: {
			return 0;
		} default: {
			cout << "Неверный ввод!" << endl;
			Menu();
			break;
		}
		}
	}
}