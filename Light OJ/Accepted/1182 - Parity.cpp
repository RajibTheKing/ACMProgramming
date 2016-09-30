#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


int main()
{
    int T, kase=0, n, k;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        k=0;
        while(n)
        {
            if(n%2==1)
                k++;
            n/=2;
        }
        if(k%2==0)
            printf("Case %d: even\n", ++kase);
        else
            printf("Case %d: odd\n", ++kase);



    }
    return 0;
}
