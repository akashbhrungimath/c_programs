#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x1,x2,y1,y2,z;
    printf("enter the value of x1=");
    scanf("%f",&x1);
    printf("enter the value of x2=");
    scanf("%f",&x2);
    printf("enter the value of y1=");
    scanf("%f",&y1);
    printf("enter the value of y2=");
    scanf("%f",&y2);
    z=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    printf("Distance=%f\n",z);
    return EXIT_SUCCESS;
    
}