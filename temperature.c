#include <stdio.h>
int main()
{
     float c,f;
     printf("enter the temparature in degree ferenheit=");
     scanf("%f",&f);
     c= ((f-32)*5)/9;
     printf("temperature in degree celcius is=%f",c);
     return 0;
}