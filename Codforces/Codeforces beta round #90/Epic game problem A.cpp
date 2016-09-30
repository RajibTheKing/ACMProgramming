#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}


main()
{
    int a, b, n, temp;
    while(cin>>a>>b>>n){
    bool flag;
    flag=true;
    while(1)
    {
        temp=gcd(a, n);
        n-=temp;
        flag=true;
        if(n==0) break;
        temp=gcd(b, n);
        n-=temp;
        flag=false;
        if(n==0) break;
    }
    if(flag) printf("0\n");
    else printf("1\n");
    }
}
