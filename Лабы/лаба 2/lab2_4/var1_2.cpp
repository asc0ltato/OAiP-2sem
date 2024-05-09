// Преподаватели. Фамилия преподавателя, название экзамена, дата экзамена. Выбор по фамилии.
// Реализовать функции ввода с клавиатуры, вывода на экран и поиска.

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

int stateMenu;

// Перечисление предметов
enum Exam {
	Math,
	Physics,
	Chemistry,
	Programming,
	English,
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

// Структура экзамена
struct ExamInfo {
	string name;
	string surname;
	string patronymic;
	Exam exam;
	Date date;
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

// Функция для ввода экзамена
void InputExam(ExamInfo& exam) {
	cout << "Введите фамилию: ";
	cin >> exam.surname;
	cout << "Введите имя: ";
	cin >> exam.name;
	cout << "Введите отчество: ";
	cin >> exam.patronymic;
	cout << "Введите предмет (0 - математика, 1 - физика, 2 - химия, 3 - программирование, 4 - английский язык): ";
	int examNumber;
	cin >> examNumber;
	exam.exam = static_cast<Exam>(examNumber);
	InputDate(exam.date);
}

// Функция для вывода экзамена
void OutputExam(ExamInfo& exam) {
	cout << "Фамилия: " << exam.surname << endl;
	cout << "Имя: " << exam.name << endl;
	cout << "Отчество: " << exam.patronymic << endl;
	cout << "Предмет: ";
	switch (exam.exam) {
	case Math:
		cout << "Математика";
		break;
	case Physics:
		cout << "Физика";
		break;
	case Chemistry:
		cout << "Химия";
		break;
	case Programming:
		cout << "Программирование";
		break;
	case English:
		cout << "Английский язык";
		break;
	}
	cout << endl;
	cout << "Дата(через точку): " << exam.date.day << "." << exam.date.month << "." << exam.date.year << endl;
}

// Функция для вывода всех экзаменов
void OutputAllExams(ExamInfo* exams, int size) {
	for (int i = 0; i < size; i++) {
		OutputExam(exams[i]);
		cout << endl;
	}
}

// Функция для поиска по фамилии
void SearchExamBySurname(ExamInfo* exams, int size) {
	string surname;
	cout << "Введите фамилию: ";
	cin >> surname;
	for (int i = 0; i < size; i++) {
		if (exams[i].surname == surname) {
			OutputExam(exams[i]);
			cout << endl;
		}
	}
}

// Функция меню
void Menu() {
	cout << "1. Ввод экзамена" << endl;
	cout << "2. Вывод всех экзаменов" << endl;
	cout << "3. Поиск по фамилии" << endl;
	cout << "4. Выход" << endl;
	cout << "Введите номер пункта меню: ";
	cin >> stateMenu;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	ExamInfo* exams = new ExamInfo[100];
	int size = 0;

	while (true) {
		Menu();
		switch (stateMenu) {
		case 1:
			InputExam(exams[size]);
			size++;
			break;
		case 2:
			OutputAllExams(exams, size);
			break;
		case 3:
			SearchExamBySurname(exams, size);
			break;
		case 4:
			return 0;
		}
	}
	return 0;
}