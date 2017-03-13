#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <assert.h>

using namespace std;


#define SIZE_N 5000100      //#define is used for constant & global
#define SIZE_P 1000000

bool flag[SIZE_N+5];
int prime[SIZE_P+5];
unsigned long long dp[SIZE_N];

void seive()
{
	int i,j,r,c=0,p;

	for(i=3;i<=SIZE_N;i+=2) //
        flag[i]=true;

	flag[2]=true;       //flag[i] array check the Isprime
	prime[c++]=2;       //All Prime store in the Prime[i] Array
	p=SIZE_N+1;
	for(i=3;i<p;i+=2)
        if(flag[i])
        {
            prime[c++]=i;
            if(SIZE_N/i>=i)
            {
                r=i*2;
                for(j=i*i;j<p;j+=r)
                    flag[j]=false;
            }
        }
    printf("Total prime: %d\n",c);
}

void preprocess()
{
    unsigned long long i,val,j,cnt,tmp;

    dp[1]=1;
    for(i=2;i<SIZE_N;i++)
    {
        if(flag[i])
            dp[i]=i-1;
        else
        {
            val=i;
            for(j=0;prime[j]<i;j++)
            {
                if(val%prime[j]==0)
                {
                    cnt=0;
                    tmp=1;
                    while(val%prime[j]==0)
                    {
                        val/=prime[j];
                        cnt++;
                        tmp*=prime[j];
                    }
                    tmp/=prime[j];
                    dp[i]=dp[val]*tmp*(prime[j]-1);
                    break;
                }
            }
        }
    }

    for(i=2;i<SIZE_N;i++)
        dp[i]=dp[i-1]+dp[i]*dp[i];
}

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    int test,Case=1;
    unsigned long long i,j,ans,a,b;;

    seive();
    preprocess();
    cout<<"completed"<<endl;



    scanf("%d",&test);

    while(test--)
    {
        scanf("%llu %llu",&a,&b);
        //cin>>a>>b;
        ans=dp[b]-dp[a-1];
        printf("Case %d: %llu\n",Case++,ans);
        //debug(ans);
    }

    return 0;
}
