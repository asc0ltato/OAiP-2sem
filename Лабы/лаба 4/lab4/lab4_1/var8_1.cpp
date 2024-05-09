//Для первой программы необходимо предварительно создать текстовый файл FILE1 из нескольких строк и записать в него данные.
//1. Скопировать из файла FILE1 в файл FILE2 все строки, кроме той строки, в которой больше всего гласных букв.Напечатать номер этой строки.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Функция countVowels принимает строку и возвращает колво гласных в ней*/
int countVowels(const string& str) { 
    int count = 0;
    for (char c : str) {
        if (c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я') {
            count++;
        }
    }
    return count;
}

//Читаем файл построчно, определяем строку с наибольшим колвом гласных и сохраняем номер. Затем мы сбрасываем указатель чтения файла в начало и копируем все строки,
//кроме строки с наибольшим колвом гласных букв, в новый файл FILE2. Выводим номер строки 
int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("FILE1.txt");
    ofstream outputFile("FILE2.txt");
    string line;
    int maxVowels = 0;
    int maxVowelsLine = 0;
    int lineNumber = 0;
    while (getline(inputFile, line)) {
        lineNumber++;
        int vowelCount = countVowels(line);
        if (vowelCount > maxVowels) {
            maxVowels = vowelCount;
            maxVowelsLine = lineNumber;
        }
    }

    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    lineNumber = 0;
    while (getline(inputFile, line)) {
        lineNumber++;
        if (lineNumber != maxVowelsLine) {
            outputFile << line << endl;
        }
    }
    cout << "Строка с наибольшим количеством гласных букв: " << maxVowelsLine << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}