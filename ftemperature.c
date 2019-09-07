#include<stdio.h>
float result(float);
int main()
{
     float c,f;
     printf("enter the temperature in degree ferenheit=");
     scanf("%f",&f);
     c=result(f);
     printf("temperature in degree celcius=%f,c);
     return 0;
}
float result(float f)
{
     float c;
     c=((f-32)*5)/9;
     return c;
}