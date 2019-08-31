#include <stdio.h>
float area(float);
int main()
{
   float r,res;
   printf("enter the value of radius=");
   scanf("%f",&r);
   res=area(r);
   printf("area of the circle is=%f",res);
   return 0;
}
float area(float r)
{
    float res;
   res=3.142*r*r;
   return res;
} 