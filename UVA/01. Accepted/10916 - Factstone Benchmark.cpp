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


int F[300010];
int Ans[30];
int Bit[30];

void Calculate_All_Factorials(void)
{
    int i, k, j, m;
    double sum=0;
    for(i=1;i<900000;i++)
    {
        sum+=(double) log(i)/ (double) log(2);
        F[i]=floor(sum+1);
        if(F[i]>(1<<22)) break;

    }
    k=i;
    j=0;
    for(int i=2;i<=22;i++)
        Bit[++j]=1<<i;
    j=1;
    m=-1;
    for(int i=1;i<=k;i++)
    {
        if(F[i]>Bit[j])
        {
            Ans[++m]=i-1;
            //cout<<m<<" : "<<Ans[m]<<endl;
            j++;
        }
    }


}
int main()
{
    int year;
    Calculate_All_Factorials();
    while(scanf("%d", &year)==1&&year!=0)
    {
        year-=year%10;
        year-=1960;
        year/=10;
        printf("%d\n", Ans[year]);
    }

    return 0;
}

