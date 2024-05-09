//1. Дан файл вещественных чисел, содержащий элементы квадратной матрицы по строкам, причем начальный элемент файла содержит значение количества столбцов матрицы.
//Создать новый файл той же структуры, содержащий k - ый столбец исходной матрицы.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n, k, i, j;
	float** a;

	FILE* f;
	f = fopen("input.txt", "r");
	if (f == NULL) {
		cout << "Ошибка открытия!" << endl;
		return 1;
	}

	fscanf(f, "%d", &n);
	a = new float* [n];
	for (i = 0; i < n; i++) {
		a[i] = new float[n];
		for (j = 0; j < n; j++) {
			fscanf(f, "%f", &a[i][j]);
		}
	}
	fclose(f);

	cout << "Введите k: ";
	cin >> k;

	if (k > n) {
		cout << "Ошибка" << endl;
		return 1;
	}

	f = fopen("output.txt", "w");
	if (f == NULL) {
		cout << "Ошибка открытия!" << endl;
		return 1;
	}

	for (i = 0; i < n; i++) {
		fprintf(f, "%f ", a[i][k - 1]);
	}
	fclose(f);
	return 0;
}