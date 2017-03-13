#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sz 1000001
using namespace std;


bool flag[1000005];
int prime[100000];
int ans[1000005];

void seive()
{
    int i, j, k;
    k=0;

    flag[0]=1;flag[1]=1;

    for(i=2;i<sz;i++)
    {
        if(flag[i]==0)
        {
            prime[++k]=i;

            for(j=i+i;j<sz;j+=i)
            {
                flag[j]=1;
            }
        }
    }
    for(i=1;i<100;i++)
        printf("%d\n", prime[i]);


}

bool check(int n)
{
    char b[20], c[20];
    sprintf(b,"%d",n);

    int l=strlen(b);
    int i, j, k, o;

    for(i=1;i<l;i++)
    {
        memset(c, 0, sizeof(c));

        for(j=0;j<l-1;j++)
            c[j]=b[j+1];


        c[j]=b[0];
        k=atoi(c);

        if(flag[k]==1)
            return 0;

        memset(b, 0, sizeof(b));

        for(o=0;o<l;o++)
        b[o]=c[o];

    }


    return 1;
}
void find(void)
{
    int i, j, k;
    int t=0;
    bool p;
    for(i=100;i<sz;i++)
    {
        if(flag[i]==0)
        {

            p=check(i);
            if(p==1)
            {
                t++;
                ans[i]=t;


            }
            else
                ans[i]=t;
        }

        else
            ans[i]=t;
    }

}

main()
{
    seive();
    find();
    int n1, n2;

    while(scanf("%d", &n1)==1)
    {

        if(n1==-1) break;
        scanf("%d", &n2);

        int t = ans[n2]-ans[n1-1];




        if(t==1)
            printf("1 Circular Prime.\n");
        else if(t==0)
            printf("No Circular Primes.\n");
        else
            printf("%d Circular Primes.\n", t);

    }

}
