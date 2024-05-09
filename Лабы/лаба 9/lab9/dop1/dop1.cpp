// Ввести цифру А, записать в файл все возможные числа, состоящие из цифр, не превышающих или равных A.Количество цифр в числах должно быть равно А.
// Примечание: использовать дополнительный массив.

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int i, c, b = 0; 
//Функция для заполнения массива числами от 1 до max и возврата колва заполненных элементов
int fun(int smth, int max, int* Array) {
    if (!b) {
        while (i < max) {
            i++;
            b++;
        }
    }
    if (i <= smth) {
        Array[c] = i;
        ++i;
        c++;
        fun(smth, max, Array);// рекурсивный вызов функции для заполнения массива
    } else {
        return c; // возвращаем количество заполненных элементов
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_CTYPE, "Russian");
    ofstream f("lab10_dop1.txt");
    int A = 0;
    cout << "Введите А: "; cin >> A;
    cout << endl;
    int* Arr = new int[A]; // создаем массив Аrr с размером А
    int counter = 1;
    while (counter < A) { // устанавливаем значение counter в первое число, состоящее из количества цифр, равного количеству цифр в A
        counter = counter * 10;
    }
    counter = counter / 10; // уменьшение значения counter в 10 раз, чтобы получить наибольшее число, < A, которое состоит только из цифр от 1 до 9
    int count = fun(A, counter, Arr); // вызов функции для заполнения Arr
    for (int i = 0; i < count; i++) { //цикл для записи каждого числа из Arr
        f << Arr[i] << endl;
    }
    f.close();
    return 0;
}