//CODING ASSIGNMENT 7
//C++ CASTING
//A program to demonstrate various types of casting in c++

#include<iostream>
#include<exception>
#include<string>
using namespace std;
struct Student
{
	int regnum;
	int rank;
	bool pass;
};
class Int
{
	int varx;
public:
	Int(int varx=0):varx{varx}
	{
		cout << "\nConversion constructor";
	}
	operator string()
	{
		cout << "\nConversion operator";
		return to_string(varx);
	}
};
class Animal
{
	virtual void print()
	{
		cout << "Animal" << endl;
	}
};
class Herbivores : private Animal
{
	void print()
	{
		cout << "Herbivores" << endl;
	}
};
class Carnivores :public Animal 
{
	void print()
	{
		cout << "Carnivores" << endl;
	}
};
class Ominvores : public Animal
{
	void print()
	{
		cout << "Ominvores" << endl;
	}
};
class Alpha
{
public:
	void displayAlpha()
	{
		cout << "Hello!!This is Alpha" << endl;
	}
};
class Beta
{
public:
	void displayBeta()
	{
		cout << "Hello!!This is Beta" << endl;
	}
};

void someAPI(int* pvar)
{
	int vark = 16;
	cout << "inside someAPI:" << vark + (*pvar) << endl;
}

int main()
{
	float varf = 3.5;
	int vara;
	
	//c-style casting
	//a = f;
	
	//static-cast--1
	vara = static_cast<int>(varf);
	cout << "\nvara=" << vara;

	//static-cast--2
	Int obj(3);
	//string str1 = obj;//using conversion  operator
	//obj = 20;//using conversion constructor
	string str = static_cast<string> (obj);
	obj = static_cast<Int>(35);
	cout << "\nstr= " << str<<endl;

	//error:static_cast--3
	//char ch;
    //int *ip=(int *ch)&ch; //allowed
	//int *ip=static_cast<int*>(&ch); //not allowed

	//static_cast--4
	Herbivores elephant;
	//Animal* animalptr = (Animal*)&elephant; //allowed
	//Animal *animalptr=static_cast<Animal*>(&elephant);//not allowed


	//Ramtatic_cast--5
	int vari = 10;
	void* vptr = static_cast<void*>(&vari);
	int* iptr = static_cast<int*>(vptr);

	//static_cast--6
	Carnivores lion;
	Ominvores dog;
	Animal* animalptr1 = static_cast<Animal*>(&lion);
	Animal* animalptr2 = static_cast<Animal*>(&dog);

	//Carnivores *lionptr=static_cast<Animal*>(animalptr2);
	//Ominvores *dogptr=static_cast<Animal*>(animalptr1);

	//dynamic_cast
	Animal* animalptr3 = dynamic_cast<Animal*>(&lion);
	Ominvores* dogptr = dynamic_cast<Ominvores*> (animalptr3);
	//Carnivores* lionptr=dynamic_cast<Carnivores*> (animalptr3);
	if (dogptr == NULL)
		cout << "NULL: Wrong down cast"<<endl;
	else
		cout << "NOT NULL: Corrrect down cast" << endl;

	//reinterpret_cast--1
	Alpha* alp = new Alpha();
	Beta* bet = new Beta();
	Alpha* newalp = reinterpret_cast<Alpha*>(bet);
	newalp->displayAlpha();

	//reinterpret_cast--2
	Student ram;
	ram.regnum = 5; ram.rank = 10; ram.pass = true;
	int* ramptr = reinterpret_cast<int*>(&ram);
	cout << "ram.regnum= "<<*ramptr<<endl;
	ramptr++;
	cout << "ram.rank= " << *ramptr << endl;
	cout << "ram.pass= " << *(reinterpret_cast<bool*>(++ramptr))<<endl;

	//const_cast--1
	const int constnum = 10;
	int varnum = 15;
	const int* cptrnum = &constnum;
	const int* cptr = &varnum;
	//int* varz = const_cast<int*>(cptrnum);
	//*varz = 15;  //undefined behaviour
	int* varb = const_cast<int*>(cptr);
	*varb = 30;
	cout << "constnum= " << constnum << " varnum= " << varnum << " *varb= " << *varb << endl;

	//const_cast--2
	someAPI(const_cast<int*>(cptrnum));

	return 0;
}