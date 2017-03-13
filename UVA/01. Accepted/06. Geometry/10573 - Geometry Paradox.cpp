#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#define pi 2*acos(0.0)
using namespace std;
vector<double> in;
int main()
{
    double r1, r2;
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        char a[1000];
        gets(a);
        in.clear();
        istringstream iss(a);
        while(iss)
        {
            int b;
            iss>>b;
            in.push_back(b);
        }

        if(in.size()==3)
        {
            r1=in[0];
            r2=in[1];
        }
        else
        {
           r1=r2=in[0]/4;
        }
        double R=r1+r2;
        double ans=R*R - r1*r1 - r2*r2;
        ans = pi*ans;

        printf("%0.4lf\n", ans);
    }
}

