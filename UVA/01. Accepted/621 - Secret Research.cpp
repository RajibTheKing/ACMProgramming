#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    char s[100000];
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        memset(s, 0, sizeof(s));
        gets(s);
        int l=strlen(s);
        if(strcmp(s, "1")==0||strcmp(s, "4")==0||strcmp(s, "78")==0)
            cout<<"+"<<endl;
        else if(s[l-2]=='3'&&s[l-1]=='5')
            cout<<"-"<<endl;
        else if(s[0]=='9' && s[l-1]=='4')
            cout<<"*"<<endl;
        else if(s[0]=='1'&&s[1]=='9'&& s[2]=='0')
            cout<<"?"<<endl;
        else continue;

    }

}
