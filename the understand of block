using namespace std;

int main()
{
	int a = 10;
	//代码块1
	{
		cout << a << endl;		//未在代码块1创建a之前用的是main内的a
		int a = 20;
		cout << a << endl;		//创建了变量a优先用代码块1中的a
		a = 20;					//只改变代码块1中的a
		cout << a << endl;
	}

	int b = 30;
	//代码块2
	{
		cout << a << endl;		//此处可以证明代码块1中的最后一行代码，代码块1结束后代码块1中的变量内存被释放此时用的是main中的a
		a = 40;					//未在代码块内创建a变量，改变的是main中的a
		cout << a << endl;
		int b = 50;
		cout << b << endl;		//同理用的是代码块2中的b
	}

	cout << b << endl;			//同理代码块2结束，代码块2中的内存被释放，此时用的是main中的b
}
