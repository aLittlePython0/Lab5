#include <iostream>
#include <ostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Triangle // початок класу
{
	double a, b, c; // сторони
	double s; // площа
public:
	Triangle() // конструктор без параметра зі значенням 0
	{
		a, b, c, s = 0;
	}
	Triangle(double a, double b, double c) // конструктор з параметром
	{
		double p;
		this->a = a;
		this->b = b;
		this->c = c;
		p = (a + b + c) / 2;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
	}
	Triangle operator +(Triangle &tr) // операція перевантаження"+" яка створює новий трикутник, сторони якого будуть сумами сторін відповідних трикутників
	{
		Triangle t (a + tr.a, b + tr.b, c + tr.c);
		return t;
	}
	Triangle operator ++ (int notused) // операція перевантаження "++"  збільшує всі стронони трикутника на одиницю
	{
		Triangle t = *this;
		a++;
		b++;
		c++;
		return t;
	}
	friend ostream& operator << (ostream& t, Triangle& tr); // операція "<<" виводить на екран значення трьох сторін і площі трикутника
};

ostream& operator << (ostream& t, Triangle& tr) // операція "<<" виводить на екран значення трьох сторін і площі трикутника
{
	t << "a = " << tr.a << "b=" << tr.b << "c = " << tr.c << "s = " << tr.s << endl;
	return t;
}




int main()
{
	Triangle a(3, 6, 7), b(5, 6, 9);
	Triangle x = a + b;
	cout << a << b;
	a = b++;
	cout << a;
	cout << b;
}

