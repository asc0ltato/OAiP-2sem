//2. Даны два файла целых чисел, содержащие элементы матрицы A размерности n x n и B размерности n x 1 по строкам,причем начальный элемент
//каждого файла содержит количество столбцов соот - ветствующей матрицы.Создать файл той же структуры с именем C, содержащий произведение матриц А и В.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int n; errno_t err;
    FILE* f;
    FILE* g;
    FILE* q;
    printf("Размер записи массива в 1.txt: ");
    cin >> n;
    err = fopen_s(&f, "1.txt", "w");

    if (err != 0) {
        return EXIT_FAILURE;
    }
    int** mas = new int* [n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand() % 10;
            fprintf(f, "%d ", mas[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    err = fopen_s(&f, "2.txt", "w");

    int r;
    printf("Размер записи массива в 2.txt: ");
    cin >> r;
    int** masarr = new int* [r];

    for (int j = 0; j < r; j++) {
        masarr[j] = new int[1];
    }

    for (int j = 0; j < r; j++) {
        masarr[j][0] = rand() % 10;
        fprintf(f, "%d ", mas[j][0]);
        fprintf(f, "\n");
    }
    fclose(f);

    err = fopen_s(&f, "3.txt", "w");

    int** arrmas = new int* [n];
    for (int i = 0; i < n; i++) {
        arrmas[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        arrmas[i][0] = 0;
        for (int j = 0; j < n; j++) {
            arrmas[i][0] += mas[i][j] * masarr[j][0];
        }

    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", arrmas[i][0]);
        fprintf(f, "\n");
    }
    fclose(f);
}