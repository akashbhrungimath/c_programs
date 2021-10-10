#include <iostream>
#include<iomanip>
int main()
{
	float a,b,sum,avg;
	std::cout<<"enter the values of a and b "<<std::endl;
	std::cin>>a>>b;
	//cin>>b;
	sum=a+b;
	avg=sum/2;
	std::cout<<"sum= "<<std::setw(5)<<sum<<std::endl;
	std::cout<<"avg= "<<std::setw(5)<<avg<<std::endl;
}