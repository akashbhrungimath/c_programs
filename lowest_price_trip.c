#include<stdio.h>
int get_input();
void get_flights(int,int,int (*)[],int *);
int compute_price(int,int,int (*)[],int *);
int trip_price(int,int,int (*)[],int,int *);
void display_price(int);
int get_input()
{
    int a;
    scanf("%d",&a);
    return a;
}
void get_flights(int n1,int n2,int a[n1][n2],int *b)
{
    for(int i=0;i<n1;i++)
    {
        scanf("%d %d %d",&a[i][0],&a[i][1],&b[i]);
    }
}
int compute_price(int n1,int n2,int a[n1][2],int *b)
{
    int final_price,source=0,index=0;
    for(int i=0;i<n2;i++)
    {
        if(a[i][0]==source)
        {
            final_price=trip_price(n1,n2,a,source,b);
        }
    }
    return final_price;
}
int trip_price(int n,int m,int flights[n][2],int source,int *prices)
{
    int i=0,index,price;
    if(source==n-1)
        return 0;
    while((flights[i][0]!=source && i<m))
        i++;
    if(i<m && flights[i][1]>source)
        price=prices[i];
    while(flights[i][0]==source)
    {
        if(price>=prices[i] && flights[i][1]>source)
        {
            price=prices[i];
            index=i;
        }
        i++;
        while((flights[i][0]!=source && i<m))
            i++;
    }
    source=flights[index][1];
    return prices[index]+trip_price(n,m,flights,source,prices);
}
void display_price(int p)
{
    printf("the resultant lowest price trip is: ");
    printf("%d\n",p);
}
int main()
{
    int n,m,result;
    printf("enter the no. of cities");
    n=get_input();
    printf("enter the no. of flights");
    m=get_input();
    int flights[m][2],prices[m];
    get_flights(m,2,flights,prices);
    result=compute_price(n,m,flights,prices);
    display_price(result);
    return 0;
}
