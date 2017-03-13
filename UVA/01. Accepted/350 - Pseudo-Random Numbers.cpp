#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

int main()
{

    int Z, I, M, L, L_new, kount, kase = 0;
    bool flag[100000];
    while(cin>>Z>>I>>M>>L)
    {
        if(Z==0&&I==0&&M==0&&L==0) break;
        memset(flag, false, sizeof(flag));

        kount = 0;
        int p = 0;
        while(1)
        {

            L_new = (Z*L+I)%M;
            if(flag[L_new]==false)
            {
                kount++;
                flag[L_new]=true;
                L = L_new;
            }
            else
                break;

        }

        printf("Case %d: %d\n", ++kase, kount);
    }

    return 0;
}
