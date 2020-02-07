#include<stdio.h>
struct frac
{
    int num;
    int den;
};
typedef struct frac FRAC;
FRAC input(int);
FRAC calc(FRAC,FRAC);
int gcd(int,int);
FRAC reduction(FRAC,int);
void output(FRAC,FRAC,FRAC);
FRAC input(int i)
{
    FRAC f;
    printf("enter the numeretor and denominator of the %d fraction=\n",i);
    scanf("%d%d",&f.num,&f.den);
    return f;
}
FRAC calc(FRAC f1,FRAC f2)
{
    FRAC f;
    float a,b;
    f.num=(f1.num*f2.den)+(f2.num*f1.den);
    f.den=(f1.den*f2.den);
    return f;
}
int gcd(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
	return a;
}
FRAC reduction(FRAC f,int g)
{
    f.num=f.num/g;
    f.den=f.den/g;
    return f;
}
void output(FRAC f3,FRAC f2,FRAC f1)
{
    printf("sum of the (%d/%d) and (%d/%d) is=%d/%d\n",f1.num,f1.den,f2.num,f2.den,f3.num,f3.den);
}
int main()
{
    FRAC f1,f2,f3;
    int g;
    f1=input(1);
    f2=input(2);
    f3=calc(f1,f2);
    g=gcd(f3.num,f3.den);
    f3=reduction(f3,g);
    output(f3,f2,f1);
    return 0;
}