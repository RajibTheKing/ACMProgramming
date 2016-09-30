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
typedef long long LL;

#define sz 5000100
int prime[1000000];
bool flag[sz+100];

void sieve(void)
{
    int i, j, k=-1, r;
    for(i=3;i<=sz;i+=2)
        flag[i]=true;
    flag[2]=true;
    prime[++k]=2;
    for(i=3;i<sz;i+=2)
    {
        if(flag[i])
        {
            prime[++k]=i;
            if(sz/i>=i)
            {
                r=i*2;
                for(j=i*i;j<sz;j+=r)
                    flag[j]=false;
            }
        }
        if(prime[k]>1000000) break;


    }

   // cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;

}
LL result[1000001];

LL Factor_Of_Factorial(int n)
{
    if(flag[n]==true)
        return result[n-1]+1;

    LL sum=0, val=sqrt(n) + 1;
    int t=n;
    for(int i=0;prime[i]<val;i++)
    {
        if(t%prime[i]==0)
        {

            while(t%prime[i]==0)
            {
                sum++;
                t/=prime[i];
            }
            val=sqrt(t)+1;
        }

    }
    if(t>1)
        sum++;

    return result[n-1] + sum;
}


int main()
{
    sieve();
    int n;
    result[0]=0;
    result[1]=1;
    result[2]=1;

    for(int i=3;i<=1000000;i++)
    {
        result[i] = Factor_Of_Factorial(i);
    }
    //cout<<"Complete"<<endl;

    while(cin>>n)
    {

        cout<<result[n]<<endl;
    }


}
