#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

bool flag[100000];
int a[100000],prime[100000];
int main()
{

    int test,i,j;
    cin>>test;
    for(i=2;i<10000;i++)
    {
        if(flag[i]==0)
        {
            for(j=i+i;j<10000;j+=i)
                flag[j]=1;
        }
    }
    int k=0,m,p;
    for(i=2;i<10000;i++)
        if(flag[i]==0)
        prime[k++]=i;
    for(int l=1;l<=test;l++)
    {
        cin>>m;
        p=m;j=0;
        for(i=0;i<m;i++)
        {
            if(prime[i]==0)
            break;
            else if(prime[i]<=m){
                while(p/prime[i])
                {
                    a[j]+=(p/prime[i]);
                    p=p/prime[i];
                }
                j++;
            }
            p=m;
        }
        printf("Case %d: %d =",l,m);
        for(i=0;i<j-1;i++)
        {
            if(a[i])
            printf(" %d (%d) *",prime[i],a[i]);
        }
        printf(" %d (%d)\n",prime[j-1],a[j-1]);
        memset(a,0,sizeof(a));
    }

}

