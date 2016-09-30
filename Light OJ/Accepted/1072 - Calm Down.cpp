#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
#define pi 3.1415926535897932384626433832795


int main()
{
    int T, kase=0;
    double R, r, n;

    scanf("%d", &T);
    while(T--)
    {
        cin>>R>>n;
        r = R* sin(pi/n);

        r = r/(1 + sin(pi/n));

        printf("Case %d: %lf\n", ++kase, r);




    }
    return 0;
}
