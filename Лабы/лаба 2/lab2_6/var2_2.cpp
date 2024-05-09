// Вокзал.Номер поезда, пункт назначения, дни следования, время прибытия, время отправления.Выбор по пункту назначения.
//Реализовать функции ввода с клавиатуры, вывода на экран и поиска.

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

int stateMenu;

// Перечисление дней следования
enum Days {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday,
};

// Дата через union
union Time {
	struct {
		int hour;
		int minute;
	};
	int time[2];
};

// Структура поезда
struct Train {
	int number;
	string destination;
	Days days;
	Time arrival;
	Time departure;
};

// Функция для ввода даты
void InputTime(Time& time) {
	cout << "Введите часы: ";
	cin >> time.hour;
	cout << "Введите минуты: ";
	cin >> time.minute;
}

// Функция для ввода поезда
void InputTrain(Train& train) {
	cout << "Введите номер поезда: ";
	cin >> train.number;
	cout << "Введите пункт назначения: ";
	cin >> train.destination;
	cout << "Выберите день следования (0 - понедельник, 1 - вторник, 2 - среда, 3 - четверг, 4 - пятница, 5 - суббота, 6 - воскресенье): ";
	int day;
	cin >> day;
	train.days = static_cast<Days>(day);
	cout << "Введите время прибытия: " << endl;
	InputTime(train.arrival);
	cout << "Введите время отправления: " << endl;
	InputTime(train.departure);
}

// Функция для вывода поезда
void OutputTrain(Train& train) {
	cout << "Номер поезда: " << train.number << endl;
	cout << "Пункт назначения: " << train.destination << endl;
	cout << "День следования: "
		<< (train.days == Monday ? "Понедельник" :
			train.days == Tuesday ? "Вторник" :
			train.days == Wednesday ? "Среда" :
			train.days == Thursday ? "Четверг" :
			train.days == Friday ? "Пятница" :
			train.days == Saturday ? "Суббота" :
			train.days == Sunday ? "Воскресенье" : "Ошибка") << endl;
	cout << "Время прибытия: " << train.arrival.hour << ":" << train.arrival.minute << endl;
	cout << "Время отправления: " << train.departure.hour << ":" << train.departure.minute << endl;
}

// Функция для вывода всех поездов
void OutputAllTrains(Train* trains, int size) {
	for (int i = 0; i < size; i++)
	{
		OutputTrain(trains[i]);
		cout << endl;
	}
}

// Функция для поиска поезда по пункту назначения
void SearchTrainByDestination(Train* trains, int size)
{
	string destination;
	cout << "Введите пункт назначения: ";
	cin >> destination;
	for (int i = 0; i < size; i++) {
		if (trains[i].destination == destination) {
			OutputTrain(trains[i]);
			cout << endl;
		}
	}
}

// Функция меню
void Menu() {
	cout << "1. Ввод поезда" << endl;
	cout << "2. Вывод всех поездов" << endl;
	cout << "3. Поиск поезда по месту назначения" << endl;
	cout << "4. Выход" << endl;
	cout << "Введите номер пункта меню: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Train* trains = new Train[10];
	int size = 0;

	while (true) {
		Menu();
		switch (stateMenu) {
		case 1:
			InputTrain(trains[size]);
			size++;
			break;
		case 2:
			OutputAllTrains(trains, size);
			break;
		case 3:
			SearchTrainByDestination(trains, size);
			break;
		case 4:
			return 0;
		default:
			cout << "Ошибка ввода" << endl;
			break;
		}
	}
}