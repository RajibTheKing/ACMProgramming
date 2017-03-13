#include<stdio.h>
#include<iostream>
#include<math.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    int t, n, kase=0;
    double r,ans;
    cin>>t;
    while(t--)
    {
        cin>>r;
        ans=r*r*4;
        ans-=pi*r*r;

        printf("Case %d: %0.2lf\n", ++kase, ans);
    }
    return 0;
}
