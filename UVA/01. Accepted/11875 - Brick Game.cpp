#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int age[100];
    int n, x, kase=0;
    cin>>n;

    while(n--)
    {
        memset(age, 0, sizeof(age));
        cin>>x;
        for(int i=0;i<x;i++)
            cin>>age[i];
        sort(age, age+x);
        int mid=x/2;
        printf("Case %d: %d\n", ++kase, age[mid]);
    }
}
