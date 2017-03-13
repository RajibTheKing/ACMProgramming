#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

string reverse(string a)
{
    string b = "";
    int i;
    for(i=a.length()-1;i>=0;i--)
        b+=a[i];
    return b;

}
main()
{
    int n;
    char c;
    char u[10000];
    string a, t, ans;
    int i, j, k;
    scanf("%d", &n);
    scanf("%c", &c);
    while(n--)
    {
        memset(u, 0, sizeof(u));
        t="";
        ans="";
        a="";

        gets(u);
        a=u;
        k=a.length();
        for(i=0;i<k;i++)
        {
            if(a[i]==' ')
            {
                ans+=a[i];
                ans+=reverse(t);
                t="";
                continue;
            }
            t+=a[i];
        }
        ans+=" ";
        ans+=reverse(t);

        for(i=1;i<ans.length();i++)
            printf("%c", ans[i]);
        printf("\n");
    }

}
