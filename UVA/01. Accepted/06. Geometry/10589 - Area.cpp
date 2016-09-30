#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;


double X[1000005];
double Y[1000005];
double dis[5];
int main()
{
    int N, M;
    double a;
    double x, y, A;
    while(scanf("%d %lf", &N, &a)==2)
    {
        if(N==0&&a==0) break;
        for(int i=0;i<N;i++)
            scanf("%lf %lf", &X[i], &Y[i]);

        double p[] = {0,a,a,0};
        double q[] = {0,0,a,a};
        M=0;
        for(int i=0;i<N;i++)
        {
            x=X[i]; y=Y[i];
            for(int j=0;j<4;j++)
                dis[j] =sqrt((x-p[j])*(x-p[j]) + (y-q[j])*(y-q[j]));

            bool flag=true;
            for(int j=0;j<4;j++)
            {
                if(dis[j]>a)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) M++;
        }
        A = M * a*a/N*1.0;
        printf("%0.5lf\n", A);




    }

    return 0;
}

