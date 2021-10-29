#include "inf_int.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	inf_int a;
	inf_int b(100);
	inf_int c("321111111111122222222222233333333333444444444445555555555");
	inf_int d("123451987651234572749499923455022211");
	inf_int e = d;
	inf_int f(e);

	cout << b << " + " << c << " = " << b + c << endl;
	cout << b << " - " << c << " = " << b - c << endl;
	cout << b << " * " << c << " = " << b * c << endl << endl;

	cout << d << " != " << e << " = " << (d != e) << endl;
	cout << d << " == " << e << " = " << (d == e) << endl;
	cout << a << " < " << f << " = " << (a < f) << endl;
	cout << a << " > " << f << " = " << (a > f) << endl;

	return 0;
}
