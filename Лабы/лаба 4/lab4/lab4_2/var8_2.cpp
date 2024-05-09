//Во второй программе ввод информации с клавиатуры и вывод в консольное окно должно осуществляться в главной функции, а запись в файл и чтение из файла - в функциях пользователя.
//Встроенные функции для работы со строками не использовать.
//2. Ввести с клавиатуры строку символов, состоящую из букв, цифр, запятых, точек, знаков + и -, и записать ее в файл.
//Прочитать из файла данные и вывести подстроку, которая соответствует записи веществен - ного числа с фиксированной точкой.

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Функция записи строки в файл
void writeToFile(const string& str, const string& filename) {
    ofstream outfile(filename);

    if (outfile.is_open()) {
        outfile << str;
        outfile.close();
    } else {
        cerr << "Не удалось открыть файл для записи" << endl;
    }
}

// Функция чтения из файла и поиска подстроки с вещественным числом
string readFromFile(const string& filename) {
    ifstream infile(filename);
    string str;

    if (infile.is_open()) {
        // Читаем содержимое файла в строку
        char ch;
        while (infile.get(ch)) {
            str += ch;
        }
        infile.close();

        // Ищем подстроку с вещественным числом
        string result;
        bool dotFound = false;
        bool digitFound = false;
        bool signFound = false;

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if ((ch >= '0' && ch <= '9') || ch == '+' || ch == '-') {
                digitFound = true;
                result += ch;
            } else if (ch == '.' && !dotFound) {
                dotFound = true;
                digitFound = false;
                result += ch;
            } else if (ch == '+' || ch == '-') {
                if (!signFound && digitFound) {
                    signFound = true;
                    result += ch;
                } else {
                    break;
                }
            } else {
                if (digitFound) {
                    break;
                } else {
                    result.clear();
                    dotFound = false;
                    digitFound = false;
                    signFound = false;
                }
            }
        }
        return result;
    } else {
        cerr << "Не удалось открыть файл для чтения" << endl;
        return "";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Ввод строки с клавиатуры
    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    // Запись строки в файл
    string filename = "file.txt";
    writeToFile(str, filename);

    // Чтение из файла и поиск подстроки с вещественным числом
    string result = readFromFile(filename);

    // Вывод результата
    if (result.empty()) {
        cout << "Не найдено вещественное число с фиксированной точкой" << endl;
    } else {
        cout << "Найдено вещественное число с фиксированной точкой: " << result << endl;
    }

    return 0;
}