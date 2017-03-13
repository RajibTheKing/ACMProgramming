#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    int n,m, temp, kase=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        temp=n*m;
        if(temp<=4)
        {
            temp=n*m;
            goto ans;
        }
        if(n==1||m==1)
        {
            temp=n*m;
            goto ans;
        }

        if(n==2||m==2)
        {
            if(n==2)
            {
                if(m%4==0)
                {
                    temp=n*m/2;
                    goto ans;
                }
                else
                {
                    int y=m/2;
                    y++;
                    temp=y*2;
                    goto ans;
                }
            }
            if(m==2)
            {
                if(n%4==0)
                {
                    temp=n*m/2;
                    goto ans;
                }
                else
                {
                    int y=n/2;
                    y++;
                    temp=y*2;
                    goto ans;
                }

            }
        }

        if(temp%2==1)
            temp=temp+1;

        temp=temp/2;

    ans:
        printf("Case %d: %d\n", ++kase, temp);

    }
    return 0;
}
