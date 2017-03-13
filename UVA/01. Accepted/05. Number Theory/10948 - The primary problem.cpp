#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define sz 1000005
int total;
bool flag[sz];
void seive()
{
    int i,val,j;
    for(i=2;i<=sz;i++)flag[i]=1;
    val=sqrt(sz)+1;
    for(i=2;i<val;i++)
    {
        if(flag[i])
        {
            for(j=i;j*i<=sz;j++)
                flag[i*j]=0;
        }
    }
}

int main()
{
    int n,i,test,ans1,ans2;
    seive();

    while(cin>>n&&n)
    {
        test=0;
        for(i=2;i<=n/2+1;i++)
        {
            if(flag[i]&&flag[n-i])
            {
                test=1;
                ans1=i;
                ans2=n-i;
                break;
            }
        }
        cout<<n<<":"<<endl;
        if(test)
            cout<<ans1<<"+"<<ans2<<endl;
        else cout<<"NO WAY!"<<endl;
    }

}

