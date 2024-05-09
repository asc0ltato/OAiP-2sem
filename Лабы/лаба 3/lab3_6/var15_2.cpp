//2. Создать текстовый файл F1 не менее, чем из 8 строк, и записать в него информацию.Скопировать из файла F1 в файл F2 строки, начиная с k до k + 3.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <iostream>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* f1, * f2;
    char str[100];
    int i, k;

    // Открытие файла F1 на запись
    f1 = fopen("F1.txt", "w");
    if (f1 == NULL) {
        printf("ERROR\n");
        return 1;
    }

    // Запись строк в файл F1
    fprintf(f1, "Stroka one\n");
    fprintf(f1, "Stroka two\n");
    fprintf(f1, "Stroka three\n");
    fprintf(f1, "Stroka four\n");
    fprintf(f1, "Stroka five\n");
    fprintf(f1, "Stroka six\n");
    fprintf(f1, "Stroka seven\n");
    fprintf(f1, "Stroka eight\n");

    // Закрытие файла F1
    fclose(f1);

    // Открытие файла F1 на чтение и файла F2 на запись
    f1 = fopen("F1.txt", "r");
    f2 = fopen("F2.txt", "w");
    if (f1 == NULL || f2 == NULL) {
        printf("ERROR\n");
        return 1;
    }

    printf("Введите номер строки, с которой хотите начать: ");
    scanf("%d", &k);

    // Копирование строк из файла F1 в файл F2
    for (i = 1; i <= 8; i++) {
        if (fgets(str, 100, f1) == NULL) {
            printf("Достигнут максимум F1.txt\n");
            break;
        }
        if (i >= k && i < k + 4) {
            fprintf(f2, "%s", str);
        }
    }

    // Закрытие файлов
    fclose(f1);
    fclose(f2);

    printf("Строки в F2.txt записаны\n");
    return 0;
}