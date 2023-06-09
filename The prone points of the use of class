class A
{
public:
	A(size_t N) :m_p(new char[N])
	{
		std::cout << "构造函数1" << std::endl;
		show();
	}
	A()
	{
		std::cout << "默认构造函数" << std::endl;
	}
	A(const A& a)
	{
		/*if (this != &a)
		{
			std::cout << "构造函数2内" << std::endl;
			delete[]m_p;
			m_p = new char[strlen(m_p) + 1];
			memcpy(m_p, a.m_p, strlen(m_p) + 1);
		}*/
	}
	~A()
	{
		delete[]m_p;
		std::cout << "delete OK" << std::endl;
	}

	void show()
	{
		std::cout << (int*)m_p << std::endl;
	}

private:
	char* m_p = nullptr;
};

A createA(size_t N)
{
	return A(100);		//因为是按值返回，调用默认复制构造函数（没有定义复制构造函数的情况下）构造临时对象（匿名对象）
}

A returnA(A& a)
{
	return a;
}

void func(A a)			//传递createA（）函数返回的临时对象给a，又是值传递					
{						//又调用了一次默认复制构造函数（没有定义复制构造函数的情况下）构造临时对象（匿名对象）
	a.show();			//浅拷贝
}						//此时析构a

int main()
{
	func(createA(100));		//析构临时对象（此次析构就会报错）因为都是浅拷贝，
							//所以这是第二次delete了同一空间（最开始开辟的空间）
							
							
	//A a(100);				//额外验证例子一
	//returnA(a);
	//func(a);
	
	//A a;					//额外验证例子二
	//system("pause");
	return 0;
}
