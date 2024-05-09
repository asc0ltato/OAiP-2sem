//Пусть функция f(x) вещественной переменной x непрерывна на отрезке[a, b] и f(a)×f(b) < 0.
//	Разработать рекурсивную программу нахождения на отрезке[a, b] какого - либо вещественного корня.

#include <iostream>
#include <cmath>

using namespace std;

//Уравнение, которое мы будем решать
double f(double x) {
	return x * x * x - 2 * x - 5;
}

double findRoot(double a, double b, double eps) {
	double c = (a + b) / 2; // Вычисляем середину интервала [a,b]
	if ((b - a) < 2 * eps)  // Если длина интервала меньше 2*eps, возвращаем середину
		return c;
	if (f(a) * f(c) <= 0) // Если корень находится в левой половине интервала, рекурсивно вызываем функцию от [a,c]
		return findRoot(a, c, eps);
	else  // Иначе корень находится в правой половине интервала, рекурсивно вызываем функцию от [c,b]
		return findRoot(c, b, eps);
}

int main() {
	setlocale(LC_ALL, "rus");
	double a, b, eps;
	cout << "Введите a, b, eps: ";	
	cin >> a >> b >> eps;
	cout << "Корень уравнения: " << findRoot(a, b, eps) << endl;
}