#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{

    int T;
    cin>>T;
    double x, y,r;

    while(T--)
    {
        cin>>x>>y>>r;


        double diff = sqrt(x*x + y*y);
        double longestDistance = diff+r;
        double shortestDistance = r-diff;

        printf("%0.2lf %0.2lf\n", shortestDistance, longestDistance);

    }

    return 0;
}
