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

int sieve(void)
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
        if(prime[k]>1000) break;
    }

    //cout<<"Last: "<<k<<" "<<prime[k]<<endl;
    return k;
}
LL Get_Result(LL n, int lim)
{
    LL t, val;
    int sum=0;
    t=n;
    val=sqrt(t) + 1;
    for(int j=0;prime[j]<val&&j<=lim;j++)
    {
        if(t%prime[j]==0)
        {
            sum++;
            while(t%prime[j]==0)
            {

                t/=prime[j];

            }
            val=sqrt(t) + 1;
        }
    }

    if(t>1)
        sum++;



    return sum;

}
int main()
{
   int lim =  sieve();

    LL n, a;
    while(cin>>n)
    {
        if(n==0) break;
        //cout<<n<<endl;

        a = Get_Result(n, lim);
        printf("%lld : %lld\n", n, a);
    }
    return 0;


}

