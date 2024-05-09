//Для первой программы необходимо предварительно создать текстовый файл FILE1 из нескольких строк и записать в него данные.
//1. Скопировать в файл FILE2 только четные строки из FILE1. Подсчитать размер файлов FILE1 и FILE2 (в байтах).

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string file1 = "FILE1.txt";
    string file2 = "FILE2.txt";

    ifstream in(file1);
    ofstream out(file2);

    if (!in || !out) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    string line;
    int count = 0;

    while (getline(in, line)) {
        ++count;
        if (count % 2 == 0) {
            out << line << endl;
        }
    }

    in.close();
    out.close();

    ifstream size1(file1, ios::binary | ios::ate);
    ifstream size2(file2, ios::binary | ios::ate);

    if (!size1 || !size2) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    cout << "Размер файла " << file1 << ": " << size1.tellg() << " байт." << endl;
    cout << "Размер файла " << file2 << ": " << size2.tellg() << " байт." << endl;

    size1.close();
    size2.close();

    return 0;
}