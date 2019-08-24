#include <stdio.h>
int main()
{
    int x,y,sum,diff,product;float division;
    printf("enter the two numbers\n");
    scanf("%d%d",&x,&y);
    sum=x+y;
    diff=x-y;
    product=x*y;
    division=(float)x/y;
    printf("Sum=%d\n Difference=%d\n Product=%d\n Division=%f\n",sum,diff,product,division);
    return 0;
}