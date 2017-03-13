
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

#define sz 100010
int prime[80000];
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

    //for(int i=0;i<100;i++)
        //cout<<prime[i]<<endl;

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}

bool factor(int n)
{
    int val = sqrt(n) + 1;
    int cnt = 0;

    for(int i=0;prime[i]<n; i++)
    {
        if(n%prime[i]==0)
            cnt++;
        if(cnt==3) return true;

    }

    return false;
}

vector<int> ans;

int main()
{
    int lim = sieve();

    for(int i=30;;i++)
    {
        if(factor(i))
            ans.push_back(i);
        if(ans.size()==1000) break;


    }
    //cout<<ans[999]<<endl;
   // cout<<"complete"<<endl;
    //for(int i=0;i<10;i++)
       // cout<<ans[i]<<endl;

    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ans[n-1]<<endl;
    }


}
