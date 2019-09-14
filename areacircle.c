#include<stdio.h>
void calc_of_the_area(float *r);
int main()
{
    float r;
    printf("enter the radius of the circle=");
    scanf("%f",&r);
    calc_of_the_area(&r);
    return 0;
}
void calc_of_the_area(float *r)
{
    printf("area of the circle with radius %f is=%lf\n",*r,(3.142**r**r));
}