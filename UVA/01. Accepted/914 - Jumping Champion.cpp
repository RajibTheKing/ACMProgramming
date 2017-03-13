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

#define sz 1000100
int prime[1000000];
int ptr[1000005];
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
        if(prime[k]>1000000) break;

    }

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}
int main()
{
    int lim = sieve();
    map<int, int> R;
    R.clear();
    int t, L, U;
    cin>>t;
    while(t--)
    {
        R.clear();
        cin>>L;
        cin>>U;
        R.clear();
        int i, j, temp, max=0, cnt;
        for(i=0;i<=lim;i++)
        if(prime[i]>=L)
                break;

        for(j=i;prime[j+1]<=U;j++)
        {
            temp=prime[j+1]-prime[j];
            if(temp>max) max=temp;
            R[temp]++;
        }
        temp=0;
        cnt=0;
        for(i=0;i<=max;i++)
        {
           // cout<<i<<" "<<R[i]<<endl;
            if(cnt<R[i])
            {
                temp=i;
                cnt=R[i];
            }
        }
        //cout<<temp<<endl;
        bool flag=true;
        for(i=0;i<=max;i++)
            if(i!=temp&&cnt==R[i])
            {
                flag=false;
                break;
            }
        if(flag&&temp!=0)
            printf("The jumping champion is %d\n", temp);
        else
            printf("No jumping champion\n");




    }

    return 0;
}
