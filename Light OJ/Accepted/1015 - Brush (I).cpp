#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t, n, kase=0;
    int sum, temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp>0)
                sum+=temp;
        }
        printf("Case %d: %d\n", ++kase, sum);
    }
}
