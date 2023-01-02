#include <stdio.h>
int main()
{
    char in_time[5],out_time[7];
    printf("Enter the time in 24 hrs format \"00:00\" :");
    scanf(" %s",in_time);
    printf("Entered time is : %s\n",in_time);
    if((in_time[0]-48>=1 && in_time[1]-48>2) || (in_time[0]=='2'))
    {
        if(in_time[0]=='2' && in_time[1]-48>2)
        {
            out_time[0]='1';
            out_time[1]=(char)(in_time[1]-2);
        }
        else
        {
            if(in_time[0]=='2')
            {
                out_time[0]='0';
                out_time[1]=(char)(in_time[1]+8);
            }
            else
            {
                out_time[0]='0';
                out_time[1]=(char)(in_time[1]-2);
            }
        }
        out_time[5]='p';
        out_time[6]='m';
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            out_time[i]=in_time[i];
        }
        out_time[5]='a';
        out_time[6]='m';
    }
    for(int i=2;i<5;i++)
    {
        out_time[i]=in_time[i];
    }
    printf("%s\n",out_time);
    return 0;
}
