#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    int n;
    int a[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    while(scanf("%d", &n)==1)
    {
        bool f=false;
        for(int i=0;i<14;i++)
            if(n%a[i]==0)
            {
                f=true;
                break;

            }
        if(f==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
