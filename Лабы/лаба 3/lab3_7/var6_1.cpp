//1. Компоненты файла fA – вещественные числа(положительные и отрицательные).
//Определить и вывести на экран порядковый номер того из них, которое наиболее близко к введенному пользователем целому числу.

#include <iostream>   
#include <stdio.h>
#include <string>
#include  <cmath>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Rus");
	int n, i = 0, j = 1;
	char c[100];
	float Pp[5]; //Инициализация переменных	
	cout << "Введите число n: ";
	cin >> n; //Ввод числа

	FILE* f;
	errno_t err;
	err = fopen_s(&f, "F1.txt", "r");//Открытие файла
	if (err != 0) {
		perror("ОШИБКА");
		return EXIT_FAILURE;
	}

	while (!feof(f)) {
		if (fgets(c, 100, f) != NULL) {
			Pp[i++] = stof(c);
		}
	}

	float summ, result;
	result = abs(n - Pp[0]);

	for (int i = 1; i < 5; i++) {//Поиск номера ближнего числа
		if (result > abs(n - Pp[i])) {
			result = abs(n - Pp[i]);
			j++;
		}
	}
	cout << "Порядковый номер: " << j; //Вывод числа
	return 0;
}