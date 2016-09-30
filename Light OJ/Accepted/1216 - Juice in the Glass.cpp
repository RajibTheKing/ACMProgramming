#include<iostream>
#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795
using namespace std;
int main()
{
    double r1, r2, r3, h, p, x, ans;
    int t, kase=0;
    cin>>t;
    while(t--)
    {
        cin>>r1>>r2>>h>>p;
        x = (h*r2)/(r1-r2);
        r3 = r2 *(p+x)/x;
        //cout<<"rajib r3: "<<r3<<endl;
        //cout<<"Babu r3: "<<((r1+r2)*p)/(h)<<endl;
        ans = ((r3*r3*(p+x) - r2*r2*x) * pi)/3;
        printf("Case %d: %lf\n", ++kase, ans);

    }
    return 0;
}
