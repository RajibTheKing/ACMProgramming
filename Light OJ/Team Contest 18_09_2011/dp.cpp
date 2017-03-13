#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int a[101];
bool flag[10000];

void dp(void)
{

    int i, j;


    for(i=2;i<10000;i++)
    {
        if(flag[i]==false)
        {

            for(j=i+i;j<10000;j+=i)
                flag[j]=true;
        }

    }
}

void ans(int n)
{
    memset(a, 0, sizeof(0));
    int t=2;
    for(int j=1;j<=n;j++)
    {
        t=2;
        if(flag[j]==false)
            a[j]++;
        else
            while(1)
            {
                if(j%t==0)
                {
                    a[t]++;
                    j=j/t;
                }
                else
                {
                    t++;
                }

                if(j==0||j==1 || t >=j/2)
                    break;
                cout<<"a"<<endl;
            }
    }
}

main()
{
    dp();
    int test, n, i, j;
    cin>>test;
    for(int i=1;i<=test; i++)
    {
        memset(a, 0, sizeof(0));

        cin>>n;

        ans(n);

        for(j=0;j<100;j++)
            cout<<a[j]<<" ";
        cout<<endl;

    }



}

