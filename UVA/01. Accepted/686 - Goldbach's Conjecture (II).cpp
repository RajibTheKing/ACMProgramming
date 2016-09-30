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
#define sz 50100
int prime[5000];
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
        if(prime[k]>32768) break;
    }

    //cout<<"Last: "<<k<<" "<<prime[k]<<endl;

}





int main()
{
    sieve();

    int n, q;
    while(cin>>n)
    {
        //cout<<n<<endl;
        if(!n) break;

        int kount=0;
        for(int i=0;i<=n/2;i++)
        {
            q = n-i;
            if(flag[i]==true&&flag[q]==true)
                kount++;
        }
        cout<<kount<<endl;


    }


}

