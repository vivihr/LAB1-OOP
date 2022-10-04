
#include "ZavdClass.h"
#include <stdio.h>
#include <Math.h>
#include <iostream>
#include <iomanip>

using namespace std;

  
double ZavdClass::Fn_b()
{
	
	double b = pow(cos(atan((x * x + y) / (z + 1))), 2) + (x / z) * exp(3 * x + y);
	return b;
}

double ZavdClass::Fn_a()
{
	double a;
	double a1 = 1 + sqrt(pow(sin(pow(abs(x + y), 0.4)), 2));
	double a2 = 2 + Fn_b() * Fn_b() + pow(sin(pow((y + z), 3)), 2);
	double a3 = tan(3 * x / z);

	a = (a1 / a2) + a3;
	return a;
}


int main()
{

	setlocale(LC_ALL, "Ukrainian");

	double x = 0.48 * 6;
	double y = 0.47 * 6;
	double z = -1.32 * 6;
	double delX = 0.2;
	double xk = 1;

	ZavdClass a = ZavdClass(x, y, z);

	cout << "Завдання 1: " << endl;
	cout << "" << "Функцiя a[x, y, z, b] = " << a.Fn_a() << endl;
	cout << "" << "Функцiя b[x, y, z] = " << a.Fn_b() << endl;
	cout << endl;
	
	cout << "Завдання 2. Табулювання функцiї: " << endl;

	for (double i = -1; i <= 1; i += delX)
	{
		ZavdClass a = ZavdClass(x + i, y, z);
		if (xk < 10) {
			cout <<  "Функцiя a" << xk  << "= " << a.Fn_a() << setw(30) << "Функцiя b" << xk <<  "= " << setw(3) << a.Fn_b() << endl;
		}
		else {
			cout <<  "Функцiя a" << xk << setw(2) << "= "  << a.Fn_a() << setw(30) << "Функцiя b" << xk << setw(3) << "= " << setw(3) << a.Fn_b() << endl;
		}
		xk++;
	}
}