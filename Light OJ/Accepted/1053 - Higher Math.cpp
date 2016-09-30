#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    double a, b, c;
    int t, kase=0;
    cin>>t;
    double cosA, cosB, cosC;

    while(t--)
    {
        cin>>a>>b>>c;
        cosA = (b*b+c*c-a*a)/(b*c*2);
        cosB = (a*a+c*c-b*b)/(a*c*2);
        cosC = (b*b+a*a-c*c)/(b*a*2);

        if(cosC==0||cosB==0||cosA==0)
            printf("Case %d: yes\n", ++kase);
        else
            printf("Case %d: no\n", ++kase);




    }
    return 0;
}
