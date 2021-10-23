#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,k;
    cout<<"enter the string to know whether the given string is palandrome or not"<<endl;
    string b;
    cin>>b;
    string rev=b;
    reverse(rev.begin(),rev.end());
    cout<<"\n"<<rev;
    if(rev!=b)
        cout<<"\nentered string is not a palandrome";
    else
        cout<<"\nenterd string is a palandrome";
}