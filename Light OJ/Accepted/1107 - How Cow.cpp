#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


int main()
{
    int T, kase=0, m, x1, x2, y1, y2, x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &m);
        printf("Case %d:\n", ++kase);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d", &x, &y);
            if(x>x1&&x<x2&&y>y1&&y<y2)
                printf("Yes\n");
            else
                printf("No\n");
        }


    }
    return 0;
}
