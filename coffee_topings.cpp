#include<iostream>
using namespace std;
int calculate_combinations(int);
int combinations(int,int);
int factorial(int);
int calculate_combinations(int n)
{
  int result=0;
  for(int i=0;i<=n;i++)
  {
    result+=combinations(n,i);
  }
  return result;
}
int combinations(int n,int r)
{
  return (factorial(n)/(factorial(r)*factorial(n-r)));
}
int factorial(int n)
{
  if(n==0)
    return 1;
  int a=n * factorial(n-1);
  return a;
}
int main()
{
  int no_of_toppings;
  cout<<"Enter the no of toppings available:"<<endl;
  cin>>no_of_toppings;
  int result=calculate_combinations(no_of_toppings);
  cout<<result<<endl;
  return 0;
}
