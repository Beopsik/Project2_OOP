#include "inf_int.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
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

	/*inf_int a(0);
	inf_int b("-25454545");
	cout << a<<" + "<<b<<" = "<< a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;

	inf_int c("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	inf_int d("0");
	cout << c << " + " << d << " = " << c + d << endl;
	cout << c << " - " << d << " = " << c - d << endl;
	cout << c << " * " << d << " = " << c * d << endl;

	inf_int e("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	inf_int f("555555");
	cout << e << " + " << f << " = " << e + f << endl;
	cout << e << " - " << f << " = " << e - f << endl;
	cout << e << " * " << f << " = " << e * f << endl;

	f = e;
	cout << e << " + " << f << " = " << e + f << endl;
	cout << e << " - " << f << " = " << e - f << endl;
	cout << e << " * " << f << " = " << e * f << endl;

	inf_int g("1");
	inf_int h("0");
	cout << g << " + " << h << " = " << g + h << endl;
	cout << g << " - " << h << " = " << g - h << endl;
	cout << g << " * " << h << " = " << g * h << endl;

	inf_int j("0");
	inf_int k("0");
	cout << j << " + " << k << " = " << j + k << endl;
	cout << j << " - " << k << " = " << j - k << endl;
	cout << j << " * " << k << " = " << j * k << endl;

	inf_int l("-321111111111122222222222233333333333444444444445555555555");
	inf_int m("-123451987651234572749499923455022211");
	cout << l << " + " << m << " = " << l + m << endl;
	cout << l << " - " << m << " = " << l - m << endl;
	cout << l << " * " << m << " = " << l * m << endl;

	inf_int o(l);
	cout << l << " != " << o << " = " << (l != o) << endl;
	cout << l << " == " << o << " = " << (l == o) << endl;
	cout << l << " < " << o << " = " << (l < o) << endl;
	cout << l << " > " << o << " = " << (l > o) << endl;

	cout << l << " != " << m << " = " << (l != m) << endl;
	cout << l << " == " << m << " = " << (l == m) << endl;
	cout << l << " < " << m << " = " << (l < m) << endl;
	cout << l << " > " << m << " = " << (l > m) << endl;

	cout << e << " != " << g << " = " << (e != g) << endl;
	cout << e << " == " << g << " = " << (e == g) << endl;
	cout << e << " < " << g << " = " << (e < g) << endl;
	cout << e << " > " << g << " = " << (e > g) << endl;

	cout << h << " == " << h << " = " << (h == h) << endl;
	

	return 0;*/
}
