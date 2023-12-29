#include <iostream>

using namespace std;

int main()
{
  cout.setf(ios_base::fixed, ios_base::floatfield);
	float a = 10.0 / 3.0;
	cout << a << endl;
	cout << a * 10.0 << endl;
	cout << a * 100.0 << endl;
	cout << a * 1000.0 << endl;
	cout << a * 10000.0 << endl;
	cout << a * 100000.0 << endl;
	cout << a * 1000000.0 << endl;
	cout << a * 10000000.0 << endl;
	cout << a * 100000000.0 << endl;

	cout << endl;
	cout << endl;

	double b = 10.0 / 3.0;
	cout << b << endl;
	cout << b * 10.0 << endl;
	cout << b * 100.0 << endl;
	cout << b * 1000.0 << endl;
	cout << b * 10000.0 << endl;
	cout << b * 100000.0 << endl;
	cout << b * 1000000.0 << endl;
	cout << b * 10000000.0 << endl;
	cout << b * 100000000.0 << endl;
	cout << b * 1000000000.0 << endl;
	cout << b * 10000000000.0 << endl;

	float c = 10000000.125;
	cout << c << endl;

	cout << 1.e7f / 9.0f << endl;
}
