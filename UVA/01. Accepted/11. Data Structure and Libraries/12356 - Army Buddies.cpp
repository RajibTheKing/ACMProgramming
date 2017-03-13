#include<iostream>
#include<map>
#include<math.h>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<vector>

using namespace std;
#define SZ 100100
int Left[SZ], Right[SZ];

main()
{
    int S, B, L, R;
    while(scanf("%d %d", &S, &B)==2)
    {
        if(S==0&&B==0) break;

        for(int i=1;i<=S;i++)
        {
            Left[i]=i-1;
            Right[i]=i+1;
        }
        Left[1]=-1;
        Right[S]=-1;

        for(int i=0;i<B;i++)
        {
            scanf("%d %d", &L, &R);
            if(Left[L]==-1) printf("*");
            else printf("%d", Left[L]);

            if(Right[R]==-1) printf(" *\n");
            else printf(" %d\n", Right[R]);

            Left[Right[R]]=Left[L];
            Right[Left[L]]=Right[R];
        }
        printf("-\n");
    }

}
