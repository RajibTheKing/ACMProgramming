#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<ctype.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
    char  a[500], b[500], c[500], d[500];
    int n, k, l, i, j, kase=0;
    char h;

    scanf("%d", &n);
    scanf("%c", &h);
    while(n--)
    {
        gets(a);

        gets(b);

        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));

        k=strlen(a);
        l=strlen(b);
        j=-1;

        for(i=0;i<k;i++)
        {
            if(a[i]==' ') continue;
            a[i]=toupper(a[i]);

            if(a[i]>='A'&&a[i]<='Z')
            c[++j]=a[i];
        }
        j=-1;
        for(i=0;i<l;i++)
        {
            if(b[i]==' ') continue;
            b[i]=toupper(b[i]);

            if(b[i]>='A'&&b[i]<='Z')
            d[++j]=b[i];
        }


        std::sort(c, c+strlen(c));
        std::sort(d, d+strlen(d));

        bool flag;
        flag=true;
        if(strlen(c)!=strlen(d))
        {
            flag=false;
        }
        else
        {
            for(i=0;i<l;i++)
                if(c[i]!=d[i])
                {
                    flag=false;
                    break;
                }
        }
        if(flag)
            printf("Case %d: Yes\n", ++kase);
        else
            printf("Case %d: No\n", ++kase);

    }
}
