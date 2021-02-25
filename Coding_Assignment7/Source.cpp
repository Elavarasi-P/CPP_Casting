#include<iostream>
#include<exception>
#include<string>
using namespace std;
struct myStruct
{
	int icat;
	int ihat;
	//char crat;
	bool bbat;
};
class Int
{
	int x;
public:
	Int(int x=0):x{x}
	{
		cout << "\nConversion constructor";
	}
	operator string()
	{
		cout << "\nConversion operator";
		return to_string(x);
	}
};
class Base
{
	virtual void print()
	{
		cout << "Base" << endl;
	}
};
class Derived : private Base
{
	void print()
	{
		cout << "Derived" << endl;
	}
};
class Derived1 :public Base 
{
	void print()
	{
		cout << "Derived1" << endl;
	}
};
class Derived2 : public Base
{
	void print()
	{
		cout << "Derived2" << endl;
	}
};
class Alpha
{
public:
	void display()
	{
		cout << "Hello!!This is Alpha" << endl;
	}
};
class Beta
{
public:
	void printBeta()
	{
		cout << "Hello!!This is Beta" << endl;
	}
};

void someAPI(int* aa)
{
	int k = 16;
	cout << "inside someAPI: k+x=" << k + (*aa) << endl;
}

int main()
{
	float f = 3.5;
	int a;
	
	//c-style casting
	//a = f;
	
	//static-cast--1
	a = static_cast<int>(f);
	cout << "\na=" << a;

	//static-cast--2
	Int obj(3);
	//string str1 = obj;//using conversion  operator
	//obj = 20;//using conversion constructor
	string str1 = static_cast<string> (obj);
	obj = static_cast<Int>(35);
	cout << "\nstr1= " << str1<<endl;

	//error:static_cast--3
	//char c;
	//int *ip=(int *c)&c; //allowed
	//int *ip=static_cast<int*>(&c); //not allowed

	//static_cast--4
	Derived d;
	//Base* bp = (Base*)&d; //allowed
	//Base *bp=static_cast<Base*>(&d);//not allowed


	//static_cast--5
	int i = 10;
	void* v = static_cast<void*>(&i);
	int* ip1 = static_cast<int*>(v);

	//static_cast--6
	Derived1 d1;
	Derived2 d2;
	Base* bp1 = static_cast<Base*>(&d1);
	Base* bp2 = static_cast<Base*>(&d2);

	//Derived1 *dp1=static_cast<Base*>(bp2);
	//Derived2 *dp2=static_cast<Base*>(bp1);

	//dynamic_cast
	Base* bp3 = dynamic_cast<Base*>(&d1);
	Derived2* dp2 = dynamic_cast<Derived2*> (bp3);
	//Derived1* dp1=dynamic_cast<Derived1*> (bp3);
	if (dp2 == NULL)
		cout << "NULL: Wrong down cast"<<endl;
	else
		cout << "NOT NULL: Corrrect down cast" << endl;

	//reinterpret_cast--1
	Alpha* alp = new Alpha();
	Beta* bet = new Beta();
	Alpha* newalp = reinterpret_cast<Alpha*>(bet);
	newalp->display();

	//reinterpret_cast--2
	myStruct s;
	s.icat = 5; s.ihat = 10; s.bbat = true;
	int* ptr = reinterpret_cast<int*>(&s);
	cout << "s.icat= "<<*ptr<<endl;
	ptr++;
	cout << "s.ihat= " << *ptr << endl;
	cout << "s.bbat= " << *(reinterpret_cast<bool*>(++ptr))<<endl;

	//const_cast--1
	const int x = 10;
	int y = 15;
	const int* px = &x;
	const int* py = &y;
	//int* z = const_cast<int*>(px);
	//*z = 15;  //undefined behaviour
	int* z1 = const_cast<int*>(py);
	*z1 = 30;
	cout << "x= " << x << " y= " << y << " *z1= " << *z1 << endl;

	//const_cast--2
	someAPI(const_cast<int*>(px));

	return 0;
}