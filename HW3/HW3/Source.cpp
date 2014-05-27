#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

void ex03_01();
void ex03_02();
void ex03_03();
void ex03_04();
void ex03_05();

int main(){

	ex03_01();
	ex03_02();
	ex03_03();
	ex03_04();
	ex03_05();
	
}

void ex03_01(){
	class Fan
	{
	public:
		int speed;
		bool on;
		double radius;
		Fan()
		{
			speed = 1;
			on = 0;
			radius = 5;
		}
		Fan(int newspeed, bool onoff, double newradius){
			speed = newspeed;
			on = onoff;
			radius = newradius;
		}

	};
	Fan fan1(3, 1, 10);
	Fan fan2(2, 0, 5);

	cout << "speed: " << fan1.speed << endl << "Fan is on: " << fan1.on << endl << "Fan radius: " << fan1.radius << endl;
	cout << "speed: " << fan2.speed << endl << "Fan is on: " << fan2.on << endl << "Fan radius: " << fan2.radius << endl;

}

void ex03_02(){
	class QuadraticEquation
	{
	private:
		int a, b, c;
	public:
		double root1, root2;
		double discriminant;

		QuadraticEquation(double a, double b, double c){
			a = 1;
			b = 1;
			c = 1;
		}

		double geta(){
			return a;
		}
		double getb(){
			return b;
		}
		double getc(){
			return c;
		}

		double getDiscriminant(){
			return ((b*b) / (-(4 * a*c)));
		}
		double getRoot1()
		{
			if (getDiscriminant() < 0)
				return 0;
			else
			{
				return (-b + sqrt(getDiscriminant())) / (2 * a);
			}
		}

		double getRoot2()
		{
			if (getDiscriminant() < 0)
				return 0;
			else
			{
				return (-b - sqrt(getDiscriminant())) / (2 * a);
			}
		}
	};

	double a, b, c;
	double discriminant, root1, root2;
	cout << "enter three numbers: ";
	cin >> a >> b >> c;
	QuadraticEquation d(a, b, c);

	discriminant = d.getDiscriminant();

	if (discriminant < 0)
	{
		cout << "The equation has no roots" << endl;
	}
	else if (discriminant == 0)
	{
		cout << "Root: " << d.getRoot1() << endl;
	}
	else
	{
		cout << "Root 1: " << d.getRoot1() << " Root 2: "
			<< d.getRoot2() << endl;
	}
}

void ex03_03(){
	class EvenNumber{
	public:
		int value;
		EvenNumber (){
			value = 0;
		}
		EvenNumber(int newvalue){
			value = newvalue;
		}

		int getValue(){
			return value;
		}

		int getNext(){
			value = value + 2;
			return value;
		}
		int getPrevious(){
			value = value - 2;
			return value;
		}
	};

	EvenNumber en1(16);
	cout << en1.getNext() << endl;
	cout << en1.getPrevious() << endl;

}

void ex03_04(){
	cout << "enter a word: ";
	string word;
	cin >> word;
	sort(word.begin(), word.end());
	cout << word << endl;
}

void ex03_05(){
	class MyInteger{
	private:
		int value;

	public:
		int getValue() const
		{
			return value;
		}

		MyInteger(int value){
			this->value = value;
		}

		bool isEven() const
		{
			return isEven(value);
		}

		static bool isEven(int a)
		{
			return a % 2 == 0;
		}

		static bool isEven(const MyInteger& a)
		{
			return isEven(a.getValue());
		}




		bool isOdd() const
		{
			return isOdd(value);
		}

		static bool isOdd(int c)
		{
			return c % 2 != 0;
		}

		static bool isOdd(const MyInteger& c)
		{
			return isEven(c.getValue());
		}




		bool isPrime() const
		{
			return isPrime(value);
		}

		static bool isPrime(const MyInteger& b)
		{
			return isPrime(b.getValue());
		}

		static bool isPrime(int num)
		{
			if ((num == 1) || (num == 2))
			{
				return true;
			}

			for (int i = 2; i <= num / 2; i++)
			{
				if (num % i == 0)
					return false;
			}

		}
			bool equals(int num1)
			{
				return value == num1;
			}

			bool equals(const MyInteger& b) const
			{
				return value == b.getValue();
			}

	};

	MyInteger a1(10);
	cout << "is a1 even? " << a1.isEven() << endl;
	cout << "is a1 prime? " << a1.isPrime() << endl;
	cout << "is 10 prime? " << MyInteger::isPrime(10) << endl;

}