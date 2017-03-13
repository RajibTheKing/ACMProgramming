#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;
#define SZ 10000000

int prime[1000];
bool flag[SZ+100];

void Prime_Generate()
{
    for(int i=0;i<=SZ;i+=2)
        flag[i]=true;
    flag[1]=true;
    flag[2]=false;
    int k=-1;
    prime[++k]=2;
    for(int i=3;i<SZ;i++)
    {
        if(flag[i]==false)
        {
            prime[++k]=i;
            if(prime[k]>10000) break;
            for(int j=i+i;j<SZ;j+=i)
                flag[j]=true;
        }

    }








}

int Find_Ans(int n)
{
    int sum, c;
    c=0;
    for(int i=0;prime[i]<=n;i++)
    {
        sum=0;
        for(int j=i;prime[j]<=n;j++)
        {
            sum+=prime[j];
            if(sum==n)
                c++;



        }
        //cout<<"for i = "<<i<<"  sum = "<<sum<<endl;
    }
    return c;
}
int main()
{
    Prime_Generate();
    int n,ans;
    while(cin>>n&&n!=0)
    {
        ans = Find_Ans(n);
        cout<<ans<<endl;
    }

    return 0;
}
