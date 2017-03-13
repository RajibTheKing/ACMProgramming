#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
    long long m, n;
    long long v[200];
    bool flag;
    int indx;
    while(scanf("%lld %lld", &n, &m)==2)
    {
        if(n<2||m<2)
        {
            printf("Boring!\n");
            continue;
        }

        indx=0;
        flag=true;

        while(n)
        {
            v[indx++]=n;
            if(n==1) break;
            if(n%m)
            {
                flag=false;
                break;
            }
            n/=m;

        }
        if(flag)
        {
            for(int i=0;i<indx;i++)
            {
                if(i) printf(" ");
                printf("%lld", v[i]);
            }
        }
        else
            printf("Boring!");
        printf("\n");


    }
    return 0;
}
