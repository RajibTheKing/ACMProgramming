#include<bits/stdc++.h>
using namespace std;
#define SZ 500
int primes[500];
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



void update(int a, int arr[])
{
    int indx=0;
    while(a>1)
    {
        int p=primes[indx++];
        while(a%p==0)
        {
            arr[p]++;
            a/=p;
        }
    }
}
int main()
{
    Sieve();
    int arr1[500];
    int arr2[500];
    int n,m;
    int value;

    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        for(int i=0;i<n;i++)
        {
            cin>>value;
            for(int j=value;j>=1;j--)
                update(j, arr1);
        }
        for(int i=0;i<m;i++)
        {
            cin>>value;
            for(int j=value;j>=1;j--)
                update(j, arr2);
        }

        bool flag = true;
        for(int i=0;i<SZ;i++)
        {
            if(arr1[i]!=arr2[i])
            {
                flag=false;
                break;
            }
        }

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}
/*12345
2 2
123456
3 1
1+3
*/
