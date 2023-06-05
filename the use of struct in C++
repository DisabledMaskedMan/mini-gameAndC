struct B
{
	char a;
	int b;
	double c;
	B& test()				//C++中也可以在结构体中定义函数
	{
		std::cout << "wc" << std::endl;
		std::cout << this << std::endl;
		return *this;
	}
	B()
	{
		a = 32;
		b = 32;
		c = 3.14;
	}
};

int main()
{
	B a = B();						//在C++中结构体有默认构造函数作用是创建一个临时结构体成员都赋值为零再将其赋值给创建的变量（左值)
	std::cout << &a << std::endl;	//同样也可以自定义结构体的构造函数，但结构体为值传递，类为引用传递（传递地址）
	std::cout << a.a << std::endl;
	std::cout << a.b << std::endl;
	std::cout << a.c << std::endl;
}
