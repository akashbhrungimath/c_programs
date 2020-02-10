#include<stdio.h>
struct frac
{
    int num;
    int den;
};
typedef struct frac FRAC;
FRAC input(int);
void getfraction(int,FRAC *);
FRAC calc(int,FRAC *);
FRAC reduction(FRAC);
int gcd(int,int);
void output(int,FRAC *,FRAC);
void getfraction(int no,FRAC f[no])
{
	for(int i=0;i<no;i++)
    {
        f[i]=input(i);
    }
}
FRAC input(int i)
{
	FRAC f;
	printf("enter the numerator and denominator of fraction %d\n",i+1);
	scanf("%d%d",&f.num,&f.den);
	return f;
}
FRAC calc(int n,FRAC f[n])
{
    FRAC f1;
    f1.num=0;
    f1.den=1;
    for (int i=0;i<n;i++)
    {
        f1.num=(f[i].num*f1.den)+(f1.num*f[i].den);
        f1.den=f1.den*f[i].den;
    }
    f1=reduction(f1);
	return f1;
}
FRAC reduction(FRAC f1)
{
    int g;
    g=gcd(f1.num,f1.den);
    f1.num=f1.num/g;
    f1.den=f1.den/g;
    return f1;
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
void output(int n,FRAC f[n],FRAC ff)
{
	for(int i=0;i<n-1;i++)
	{
		printf("(%d/%d)+",f[i].num,f[i].den);
	}
	printf("(%d/%d)=%d/%d\n",f[n-1].num,f[n-1].den,ff.num,ff.den);
}
int main()
{
    int i,no;
    FRAC ff;
    printf("enter the number of fractions you want to enter=");
    scanf("%d",&no);
    FRAC f[no];
    getfraction(no,f);
    ff=calc(no,f);
    output(no,f,ff); 
    return 0;
}