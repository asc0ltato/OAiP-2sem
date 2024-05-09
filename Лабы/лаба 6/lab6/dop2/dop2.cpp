//Каждый элемент списка студентов содержит фамилию, имя, отчество, год рождения, курс, номер группы, оценки по пяти предметам.
//Упорядочить студентов по курсу, причем студенты одного курса должны располагаться в алфавитном порядке.Найти средний балл каждой группы по каждому предмету.
//Определить самого старшего студента и самого младшего студентов.Для каждой группы найти лучшего с точки зрения успеваемости студента.

#include <iostream>
#include <Windows.h>

using namespace std;

int stateMenu;

// Каждый элемент списка студентов содержит фамилию, имя, отчество, год рождения, курс, номер группы, оценки по пяти предметам.

struct Student
{
	char surname[20];
	char name[20];
	char patronymic[20];
	int year;
	int course;
	int group;
	int marks[5];
};

// Функция вывода всех студентов
void printStudents(Student students[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Студент № " << i + 1 << ": " << endl;
		cout << "Фамилия: " << students[i].surname << endl;
		cout << "Имя: " << students[i].name << endl;
		cout << "Отчество: " << students[i].patronymic << endl;
		cout << "Год рождения: " << students[i].year << endl;
		cout << "Курс: " << students[i].course << endl;
		cout << "Номер группы: " << students[i].group << endl;
		cout << "Оценки по пяти предметам: " << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "Оценка " << j + 1 << ": " << students[i].marks[j] << endl;
		}
		cout << endl << endl;
	}
}

// Функция упорядочивания студентов по курсу
void sortStudentsByCourse(Student students[], int size)
{
	Student temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (students[j].course > students[j + 1].course)
			{
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
			else if (students[j].course == students[j + 1].course)
			{
				if (strcmp(students[j].surname, students[j + 1].surname) > 0)
				{
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}
			}
		}
	}

	cout << "Список студентов, упорядоченных по курсу: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Студент № " << i + 1 << ": " << endl;
		cout << "Фамилия: " << students[i].surname << endl;
		cout << "Имя: " << students[i].name << endl;
		cout << "Отчество: " << students[i].patronymic << endl;
		cout << "Год рождения: " << students[i].year << endl;
		cout << "Курс: " << students[i].course << endl;
		cout << "Номер группы: " << students[i].group << endl;
		cout << "Оценки по пяти предметам: " << endl;
		for (int j = 0; j < 5; j++)
		{

			cout << "Оценка " << j + 1 << ": " << students[i].marks[j] << endl;
		}
		cout << endl << endl;
	}

}

// Функция нахождения среднего балла по каждому из 5 предметов (вывести в точностью до 2 знаков после запятой)
void findAverageMark(Student students[], int size)
{
	double averageMark[5];
	for (int i = 0; i < 5; i++)
	{
		averageMark[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			averageMark[j] += students[i].marks[j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		averageMark[i] /= size;
	}

	cout << "Средний балл по каждому из 5 предметов: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Средний балл по предмету " << i + 1 << ": " << averageMark[i] << endl;
	}
}

// Функция нахождения среднего балла каждой группы по каждому из 5 предметов (вывести в точностью до 2 знаков после запятой)
void findAverageMarkByGroup(Student students[], int size)
{
	// Определить количество групп и сколько студентов в каждой группе
	int groups[10];
	int numberOfGroups = 0;
	for (int i = 0; i < 10; i++)
	{
		groups[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		groups[students[i].group - 1]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (groups[i] != 0)
		{
			numberOfGroups++;
		}
	}

	// Найти средний балл каждой группы по каждому из 5 предметов
	double averageMarkByGroup[10][5];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			averageMarkByGroup[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			averageMarkByGroup[students[i].group - 1][j] += students[i].marks[j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			averageMarkByGroup[i][j] /= groups[i];
		}
	}

	// Вывести средний балл каждой группы по каждому из 5 предметов
	cout << "Средний балл каждой группы по каждому из 5 предметов: " << endl;
	for (int i = 0; i < 10; i++)
	{
		if (groups[i] != 0)
		{
			cout << "Группа № " << i + 1 << ": " << endl;
			for (int j = 0; j < 5; j++)
			{
				cout << "Средний балл по предмету " << j + 1 << ": " << averageMarkByGroup[i][j] << endl;
			}
		}
	}
}

// Функция нахождения самого старшего студента и самого младшего студента
void findOldestAndYoungestStudents(Student students[], int size)
{
	// Определить самого старшего студента и самого младшего студента
	int max = students[0].year;
	int min = students[0].year;
	for (int i = 0; i < size; i++)
	{
		if (students[i].year > max)
		{
			max = students[i].year;
		}
		if (students[i].year < min)
		{
			min = students[i].year;
		}
	}
	cout << "Самый старший студент: " << endl;
	for (int i = 0; i < size; i++)
	{
		if (students[i].year == min)
		{
			cout << "Фамилия: " << students[i].surname << endl;
			cout << "Имя: " << students[i].name << endl;
			cout << "Отчество: " << students[i].patronymic << endl;
			cout << "Год рождения: " << students[i].year << endl;
			cout << "Курс: " << students[i].course << endl;
			cout << "Номер группы: " << students[i].group << endl;
			cout << "Оценки по пяти предметам: " << endl;
			for (int j = 0; j < 5; j++)
			{
				cout << "Оценка " << j + 1 << ": " << students[i].marks[j] << endl;
			}
			cout << endl << endl;
		}
	}
	cout << "Самый младший студент: " << endl;
	for (int i = 0; i < 10; i++)
	{
		if (students[i].year == max)
		{
			cout << "Фамилия: " << students[i].surname << endl;
			cout << "Имя: " << students[i].name << endl;
			cout << "Отчество: " << students[i].patronymic << endl;
			cout << "Год рождения: " << students[i].year << endl;
			cout << "Курс: " << students[i].course << endl;
			cout << "Номер группы: " << students[i].group << endl;
			cout << "Оценки по пяти предметам: " << endl;
			for (int j = 0; j < 5; j++)
			{
				cout << "Оценка " << j + 1 << ": " << students[i].marks[j] << endl;
			}
			cout << endl << endl;
		}
	}
}

// Функция нахождения лучшего студенка с каждой группы
void findBestStudent(Student students[], int size)
{
	// Получаем номера групп, в которых есть студенты
	int groups[10];
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		bool isExist = false;
		for (int j = 0; j < count; j++)
		{
			if (students[i].group == groups[j])
			{
				isExist = true;
				break;
			}
		}
		if (!isExist)
		{
			groups[count] = students[i].group;
			count++;
		}
	}

	// Находим лучшего студента в каждой группе
	for (int i = 0; i < count; i++)
	{
		int max = 0;
		for (int j = 0; j < size; j++)
		{
			if (students[j].group == groups[i])
			{
				int sum = 0;
				for (int k = 0; k < 5; k++)
				{
					sum += students[j].marks[k];
				}
				if (sum > max)
				{
					max = sum;
				}
			}
		}
		cout << "Лучший студент группы " << groups[i] << ": " << endl;
		for (int j = 0; j < size; j++)
		{
			if (students[j].group == groups[i])
			{
				int sum = 0;
				for (int k = 0; k < 5; k++)
				{
					sum += students[j].marks[k];
				}
				if (sum == max)
				{
					cout << "Фамилия: " << students[j].surname << endl;
					cout << "Имя: " << students[j].name << endl;
					cout << "Отчество: " << students[j].patronymic << endl;
					cout << "Год рождения: " << students[j].year << endl;
					cout << "Курс: " << students[j].course << endl;
					cout << "Номер группы: " << students[j].group << endl;
					cout << "Оценки по пяти предметам: " << endl;
					for (int k = 0; k < 5; k++)
					{
						cout << "Оценка " << k + 1 << ": " << students[j].marks[k] << endl;
					}
					cout << endl << endl;
				}
			}
		}
	}
}

// Главное меню
void Menu()
{
	cout << "Меню:" << endl
		<< "1. Вывести информацию о студентах" << endl
		<< "2. Вывод студентов, упорядоченных по курсу" << endl
		<< "3. Средний балл по каждому из 5 предметов" << endl
		<< "4. Средний балл КАЖДОЙ ГРУППЫ по каждому из 5 предметов" << endl
		<< "5. Самый старший и самый младший студент" << endl
		<< "6. Лучший студент с каждой группы" << endl
		<< "7. Выход" << endl
		<< "Ваш выбор: ";
	cin >> stateMenu;
}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student students[10] = {
		{"Иванов", "Иван", "Иванович", 2004, 2, 5, {5, 4, 6, 8, 10}},
		{"Петров", "Петр", "Петрович", 2003, 2, 2, {10, 4, 4, 4, 6}},
		{"Сидоров", "Сидор", "Сидорович", 2003, 3, 3, {5, 5, 5, 5, 5}},
		{"Алексеев", "Алексей", "Алексеевич", 2002, 4, 5, {7, 3, 8, 9, 6}},
		{"Александров", "Александр", "Александрович", 2004, 2, 8, {9, 9, 9, 8, 8}},
		{"Андреев", "Андрей", "Андреевич", 2002, 1, 6, {6, 6, 6, 9, 4}},
		{"Антонов", "Антон", "Антонович", 2005, 2, 7, {4, 4, 4, 4, 4}},
		{"Артемов", "Артем", "Артемович", 2005, 1, 8, {5, 4, 5, 5, 5}},
		{"Борисов", "Борис", "Борисович", 2005, 1, 2, {5, 2, 5, 6, 7}},
		{"Борисов", "Борис", "Борисович", 2002, 4, 3, {8, 8, 7, 8, 5}}
	};

	Menu();

	while (stateMenu != 7)
	{
		// Ввод только цифр
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный ввод!" << endl;
			Menu();
		}

		switch (stateMenu)
		{
		case 1:
			system("cls");
			printStudents(students, 10);
			Menu();
			break;
		case 2:
			system("cls");
			sortStudentsByCourse(students, 10);
			Menu();
			break;
		case 3:
			system("cls");
			findAverageMark(students, 10);
			Menu();
			break;
		case 4:
			system("cls");
			findAverageMarkByGroup(students, 10);
			Menu();
			break;
		case 5:
			system("cls");
			findOldestAndYoungestStudents(students, 10);
			Menu();
			break;
		case 6:
			system("cls");
			findBestStudent(students, 10);
			Menu();
			break;
		default:
			cout << "Неверный ввод!" << endl;
			Menu();
			break;
		}
	}
}