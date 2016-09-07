#include<stdio.h>
#include<iostream.h>
long long a[1000000];
int main()
{
    long long  t;
    cin>>t;
    while(t)
    {
        long long n,i, flag=0, alice=0, bob=0;
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(i=0; i<n; i++)
        {
            for(; ; )
            {
                if(a[i]==1)
                    break;
                if(alice==0)
                {
                    alice=1;
                    bob=0;
                }
                else
                {
                    alice=0;
                    bob=1;
                }
                a[i]--;
            }


        }



        if(alice)
            printf("Alice\n");
        else
            printf("Bob\n");
        t--;
    }

    return 0;
}
