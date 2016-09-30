#include<bits/stdc++.h>
using namespace std;
#define SZ 100010
int primes[10000];
bool flag[SZ];


void Sieve()
{

    memset(flag, 0, sizeof(flag));
    flag[0] = true;
    flag[1] = true;
    int indx=0;
    for(int i=2;i<SZ;i++)
    {
        if(flag[i]==false)
        {
            primes[indx++] = i;
            for(int j=i+i;j<SZ;j+=i)
            {
                flag[j]=true;
            }
        }
    }
}

int update(int nowans, int p)
{
    if(p==1) return nowans;

    if(p%2==0)
        nowans*=1;
    else
    {
        int t = p+1;
        if(t%4==0)
        {
            nowans*=1;
        }
        else
        {
            nowans*=(-1);
        }
    }

    return nowans;
}
int main()
{
    Sieve();
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int now = n;
        int indx=0;
        int nowans=1;
        while(now>1)
        {
            int p = primes[indx];
            while(now%p==0)
            {
                nowans = update(nowans, p);
                now/=p;
            }
            indx++;
        }

        if(nowans==1)
            cout<<"+"<<endl;
        else
            cout<<"-"<<endl;
    }
    return 0;
}
