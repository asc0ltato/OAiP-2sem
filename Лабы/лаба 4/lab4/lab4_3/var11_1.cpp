//Для первой программы необходимо предварительно создать текстовый файл FILE1 из нескольких строк и записать в него данные.
//1. Скопировать из файла FILE1 в файл FILE2 все строки, которые содержат только одно слово. Найти самое короткое слово в  файле FILE2.

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file1("FILE1.txt"); // открываем файл FILE1 для чтения
    ofstream file2("FILE2.txt"); // открываем файл FILE2 для записи
    string line; // переменная для хранения строки из файла FILE1

    // читаем строки из файла FILE1
    while (getline(file1, line)) {
        bool onlyOneWord = true; // флаг, показывающий, что в строке только одно слово
        for (char c : line) {
            if (c == ' ') { // если встретили пробел, значит в строке более одного слова
                onlyOneWord = false;
                break;
            }
        }
        if (onlyOneWord) { // если в строке только одно слово, записываем ее в файл FILE2
            file2 << line << endl;
        }
    }

    file1.close(); // закрываем файл FILE1
    file2.close(); // закрываем файл FILE2

    ifstream file2ForShortestWord("FILE2.txt"); // открываем файл FILE2 для поиска самого короткого слова
    string shortestWord = ""; // переменная для хранения самого короткого слова
    while (file2ForShortestWord >> line) { // читаем слова из файла FILE2
        if (shortestWord == "" || line.length() < shortestWord.length()) {
            shortestWord = line; // если это первое слово или оно короче текущего самого короткого, сохраняем его
        }
    }
    file2ForShortestWord.close(); // закрываем файл FILE2

    cout << "Самое короткое слово в файле FILE2: " << shortestWord << endl;

    return 0;
}