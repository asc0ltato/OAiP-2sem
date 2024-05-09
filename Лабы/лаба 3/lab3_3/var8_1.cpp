//1. Дан файл целых чисел с элементами A(i), i = 0, ..., N – 1 (N  размер файла).
//Заменить исходное расположение его элементов на следующее : A(0), A(N – 1), A(1), A(N – 2), A(2), ... .

#include <stdio.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int fsize;
    int k = 1;
    int a; errno_t err;
    FILE* f;
    int b = rand() % 10;
    int* mas = new int[b];
    err = fopen_s(&f, "F1.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < b; i++) {
        mas[i] = rand() % 10;
        fprintf(f, "%d ", mas[i]);
    }
    printf("Данные записаны в файл F2.txt\n");
    fclose(f);

    err = fopen_s(&f, "F1.txt", "r");
    fseek(f, 0L, SEEK_END);
    fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);
    fclose(f);
    err = fopen_s(&f, "F2.txt", "w");
    for (int i = 0; i < b; i++) {

        fprintf(f, "%d ", mas[i]);
        fprintf(f, "%d ", mas[b - k]);
        k++;
    }
    fclose(f);
    return 0;
}