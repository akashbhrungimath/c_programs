#include<bits/stdc++.h>
#include<stdlib.h>
#include<string>
using namespace std;
class college;
class student;
class colg_name;
class USN;
class college
{
    protected:
    string c[3]={"BMS","RVC","PES"};
    char ci[3][2]={'B','M',
            'R','V',
            'P','E'};
    char bn[3][2]={'E','E',
            'E','C',
            'M','E'};
};
class student
{
    protected:
    char *name;
    public:
    void getname()
    {
        int n;
        cout<<"enter the length of the name=";
        cin>>n;
        name=(char*)malloc((n+1)*sizeof(char));
        cout<<"enter the name= ";
        cin>>name;
    }
};
class colg_name:public student
{
    protected:
    char college_name[4];
    char branch_name[2];
    public:
    void get_colgname()
    {
        cout<<"enter the college name=";
        cin>>college_name;
    }
    void get_branchname()
    {
        cout<<"enter the branch=";
        cin>>branch_name;
    }
};
class USN:public colg_name, public college
{
    protected:
    char usn[10];
    static int number[5][5];
    public:
    friend void sort_names(int, USN *);
    void cal_usn()
    {
        for(int j=0;j<3;j++)
        {
            for(int m=0;m<3;m++)
            {
                int flag=strcmp(branch_name,bn[m]);
                if(college_name==c[j] && flag==0)
                {
                    usn[0]='1';
                    for(int k=1;k<=2;k++)
                        usn[k]=ci[j][k-1];
                    usn[3]='1';
                    usn[4]='9';
                    int i=0;
                    for(int k=5;k<=6;k++)
                    {
                        usn[k]=branch_name[i];
                        i++;
                    }
                    usn[7]='0';
                    usn[8]='0';
                    usn[9]=number[j][m];
                    number[j][m]++;
                }
            }
        }
    }
    void display()
    {
        cout<<endl<<name<<"\t"<<usn<<endl;
    }
};
int USN::number[5][5]={1};
void sort_names(int n,USN u[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(strcmp(u[j].name,u[j+1].name)<0)
            {
                char *temp;
                strcpy(temp,u[j].name);
                strcpy(u[j].name,u[j+1].name);
                strcpy(u[j+1].name,temp);
            }
        }
    }
}
int main()
{
    int n1;
    cout<<"how many names do you want to enter=";
    cin>>n1;
    USN u[n1];
    for(int i=0;i<n1;i++)
    {
        u[i].getname();
        u[i].get_colgname();
        u[i].get_branchname();
    }
    sort_names(n1,u);
    for(int i=0;i<n1;i++)
        u[i].cal_usn();
    for(int i=0;i<n1;i++)
        u[i].display();
    return 0;
}
