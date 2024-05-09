//Для первой программы необходимо предварительно создать текстовый файл FILE1 из нескольких строк и записать в него данные.
//1. Скопировать из файла FILE1 в файл FILE2 все строки, в которых содержится два одинаковых слова.Определить номер слова, в котором больше всего  букв «1».
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <windows.h>


using namespace std;

// Функция для подсчета количества букв "1" в строке
int countOnes(string str) {
    return count(str.begin(), str.end(), '1');
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename1 = "FILE1.txt";
    string filename2 = "FILE2.txt";

    ifstream fin(filename1);
    ofstream fout(filename2);

    if (!fin || !fout) {
        cout << "Ошибка открытия файлов." << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        // Разбиваем строку на слова
        istringstream iss(line);
        string word1, word2;
        iss >> word1;
        iss >> word2;

        if (word1 == word2) { // Если слова одинаковые, то записываем строку в файл FILE2
            fout << line << endl;
        }
        else { // Иначе, ищем слово с наибольшим количеством букв "1"
            int count1_word1 = countOnes(word1);
            int count1_word2 = countOnes(word2);
            if (count1_word1 > count1_word2) {
                cout << "Слово 1 содержит больше букв '1'" << endl;
            }
            else if (count1_word1 < count1_word2) {
                cout << "Слово 2 содержит больше букв '1'" << endl;
            }
            else {
                cout << "Слова содержат одинаковое количество букв '1'" << endl;
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
