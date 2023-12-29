using namespace std;

const int& Sum(int& x)
{
	x += x;
	return x;
}

int main()
{
	int a = 10;
	int& t = a;
	const int& x = Sum(a);		//只能将const int& 赋值给 cinst int&
	cout << x << endl;
	t = 30;						//虽然const int& 也就是x，不能修改a的值，但新创建的关于a的引用t可以
	cout << x << endl;


	int b = 50;
	const int* const pa = &b;
	const int* const * const ppa = &pa;		//ppa不可修改，*ppa不可修改，**ppa不可修改	

	cout << **ppa << endl;
	b = 100;					//由于只能将const指针赋值给const指针，所以只能用最开始的变量修改（前提最开始的变量可修改）
	cout << **ppa << endl;
	cout << *pa << endl;

	return 0;
}
