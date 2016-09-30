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

#define sz 50001
int prime[5000];
bool flag[sz+100];

vector<int> fact;
vector<int> cnt;

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
        if(prime[k]>31700) break;
    }

    //for(int i=0;i<100;i++)
        //cout<<prime[i]<<endl;

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}

LL Get_Sum_Of_Digit(LL n)
{
    char c[50];
    sprintf(c, "%lld", n);
    LL sum=0;
    for(int i=0;i<strlen(c);i++)
        sum+=c[i]-'0';
    return sum;
}

LL Get_Sum_Of_Digit_Of_Factors()
{
    LL sum = 0;
    for(int i=0;i<fact.size();i++)
    {
        sum+=Get_Sum_Of_Digit(fact[i]) * cnt[i];
    }

    return sum;
}



LL Get_Result(LL n, int lim)
{
    LL t, kount, val, t1,  t2;
    bool fff = false;

    for(LL i=n+1; ;i++)
    {
        //if(flag[i]==true) continue;
        //cout<<"Rajib"<<endl;
        //cout<<"For: "<<i<<endl;
        t=i;
        val=sqrt(t) + 1;
        fact.clear();
        cnt.clear();
        kount=-1;
        fff=true;
        for(int j=0;prime[j]<val&&j<=lim;j++)
        {
            //cout<<"Aporba"<<endl;
            if(t%prime[j]==0)
            {
                fff=false;
                kount++;
                fact.push_back(prime[j]);
                cnt.push_back(0);
                while(t%prime[j]==0)
                {
                    t/=prime[j];
                    cnt[kount]++;
                }

                val=sqrt(t) + 1;
            }
        }

        if(t>1)
        {
            if(fff) continue;
            fact.push_back(t);
            kount++;
            cnt.push_back(0);
            cnt[kount]++;
        }


        t1 = Get_Sum_Of_Digit(i);
        t2 = Get_Sum_Of_Digit_Of_Factors();

        if(t1==t2)
            return i;
    }
}


int main()
{
    int lim = sieve();

    //Create_Vector(lim);

    //cout<<"Complete"<<endl;

    int t;
    LL n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<Get_Result(n, lim)<<endl;
    }


}
