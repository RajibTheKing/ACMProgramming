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
#define sz 1000010
#define M 1000003
long long factorial[sz];


void initiate(void)
{
    factorial[0]=1;
    factorial[1]=1;
    for(long long i=2;i<sz;i++)
        factorial[i]=(factorial[i-1] * i%M ) % M;
}
long long BigMod(long long base, long long power, long long mod)
{
    long long ans = 1;
    while(power>0)
    {
        if(power%2==1)
            ans = (ans * base) % mod;
        power/=2;
        base = (base*base) % mod;
    }
    return ans;
}

int main()
{
    initiate();
    int T, kase=0;
    long long n, r, numerator, denominator, temp, ans;
    cin>>T;
    while(T--)
    {
        cin>>n>>r;

        numerator = factorial[n];
        denominator = ( factorial[r] * factorial [n-r] ) % M;
        temp = BigMod(denominator, M-2, M);
        ans = ( numerator * temp ) % M;
        printf("Case %d: %d\n", ++kase, ans);

    }
    return 0;
}

