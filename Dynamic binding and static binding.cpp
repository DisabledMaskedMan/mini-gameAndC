#include<iostream>

class A
{
protected:
	int a;
public:
	virtual void A_vfunc1() { std::cout << "Avf1" << std::endl; }
	void A_func1(){ std::cout << "Af1" << std::endl; }
	void A_func2() { std::cout << "Af2" << std::endl; }
};

class B : public A
{
	int b;
public:
	void B_func1() { std::cout << "Bf1" << std::endl; }
	void B_func2() { a = 10; }
	virtual void B_vfunc1(){ std::cout << "Bvf1" << std::endl; }

	void A_func1() { std::cout << "B Af1" << std::endl; }
	void A_vfunc1() { std::cout << "B Avf1" << std::endl; }
};

class C
{
public:
	int c;
	virtual void C_vfunc1() = 0;
};

class D : public C
{
public:
	int d;
	void C_vfunc1(){ std::cout << "D Cvf1" << std::endl; }
};

class E : public C
{
public:
	int e;
};

int main()
{

	A a;
	B b;

	A* pa = &a;
	pa->A_func1();		//a静态类型为A，静态绑定为A，所以打印的是“Af1”
	pa->A_vfunc1();		//a的动态类型为A，动态绑定为A，所以打印的是“Avf1”

	pa = &b;
	pa->A_func1();		//a的静态类型为A，静态绑定为A,所以打印的是“Af1”
	pa->A_vfunc1();		//a的动态类型为B，动态绑定为B，因为B覆盖了A里的虚函数，所以打印的是“B Avf1”

	B* pb = new B;
	pb->A_func1();		//因为B覆盖了A里的此函数，所以打印的是“B Af1”
	pb->A_func2();		//因为B没有覆盖了A里的此函数，所以打印的是“Af2”，子类可以继承父类的方法和数据(protected)

	//C c; C内有纯虚数所以C为抽象类（不能实例化）
	C* c = new D;
	c->C_vfunc1();		//抽象类可以通过指针调用子类

	//E e; 抽象类的子类未定义纯虚数，该子类仍为抽象类
}
