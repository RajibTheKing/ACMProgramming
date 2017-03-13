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
#define sz 1000010
#define Num 1000000000000LL

LL prime[1000000];
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
    }

   // cout<<"Last: "<<k<<" "<<prime[k]<<endl;
    return k;
}
LL R[1000000];

unsigned long long  t;

int Create_Result(int lim)
{
    int k=-1;
    //cout<<"Lim: "<<lim<<endl;

    //cout<<Num<<endl;

    for(int i=0;i<=lim;i++)
    {
        //cout<<i<<endl;
        t=prime[i];

        while(t<=Num)
        {
            t*=prime[i];
            R[++k]=t;

        }
    }

    //for(int i=0;i<=k;i++)
        //cout<<R[i]<<endl;
    return k+1;

}
int main()
{
    int lim =  sieve();

    int n = Create_Result(lim);
    //cout<<"Complete  "<<n<<endl;
    sort(R, R+n);

    LL low, high, t, kount;
    cin>>t;
    while(t--)
    {
        cin>>low>>high;
        kount=0;
        for(int i=0;R[i]<=high;i++)
        {
            if(R[i]>=low&&R[i]<=high)
                kount++;
        }

        cout<<kount<<endl;
    }
    return 0;
}

