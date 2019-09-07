#include <stdio.h>
int time(int ,int);
int main()
{
     int h,m,t;
     printf("enter how many hours=");
     scanf("%d",&h);
     printf("enter how many minutes=");
     scanf("%d",&m);
     time(h,m);
     printf("total time in minutes is=%d",t);
     return 0;
}
int time(int h,int m)
{
     int t;
     t=h*60+m;
     return t;
}