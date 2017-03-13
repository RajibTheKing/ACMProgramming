#include<iostream>
using namespace std;
#define MAX 1501
int prime[300];
bool flag[MAX];
int Seive()
{
    for(int i=0;i<MAX;i++) flag[i]=true;
    int k=0;
    for(int i=2;i<MAX;i++)
    {
        if(flag[i])
        {
            prime[k++]=i;
            for(int j=i+i;j<MAX;j=j+i)
                flag[j]=false;
        }

    }
    return k;
}

int main()
{
    int kount = Seive();
    //for(int i=0;i<kount;i++) cout<<prime[i]<<endl;

    int n, k, kk;
    while(cin>>n>>k)
    {
        kk=0;
        for(int i=0;prime[i]<=n;i++)
        {
            int temp = prime[i];
            for(int j=0;prime[j+1]<=temp;j++)
            {
                if((1+prime[j]+prime[j+1])==temp)
                    kk++;
            }
        }
        if(kk>=k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}

