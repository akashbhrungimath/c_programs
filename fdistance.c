#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x1,x2,y1,y2,z;
    printf("enter the value of x1,x2,y1,y2=");
    scanf("%f%f%f%f",&x1,&x2,&y1,&y2);
    z=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    printf("Distance=%f\n",z);
    return EXIT_SUCCESS;
    
}