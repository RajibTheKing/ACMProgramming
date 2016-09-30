#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

bool CheckFor7(int a)
{
    if(a%7==0) return true;

    while(a)
    {
        int temp = a%10;
        a/=10;
        if(temp==7) return true;
    }
    return false;

}


int main()
{
    int n, m, k;
    int person, number;
    int P[101];



    while(scanf("%d %d %d", &n, &m, &k)==3)
    {
        if(n==0&&m==0&&k==0) break;
        memset(P, 0, sizeof(P));

        person=1;
        number=0;
        bool flag=true;
        while(true)
        {
            number++;
            if(CheckFor7(number))
                P[person]++;
            if(P[m]==k) break;

            if(person==n)
                flag=false;
            if(person==1)
                flag=true;
            if(flag)
                person++;
            else
                person--;
        }
        printf("%d\n", number);

    }


    return 0;
}

