#include<iostream>
using namespace std;
class Complex
{
	float x;
	float y;
	public:
	Complex(){}
	Complex(float x,float y)
	{
		this->x=x;
		this->y=y;
	}
	Complex operator + (Complex c2)
	{
		Complex c;
		c.x=this->x+c2.x;
		c.y=this->y+c2.y;
		return c;
	}
	void display()
	{
		cout<<x<<" + i"<<y<<endl;
	}
};
int main()
{
	Complex c1(3,4),c2(2,3),c3;
	c3=c1+c2;
	c1.display();
	c2.display();
	c3.display();
	return 0;
}
