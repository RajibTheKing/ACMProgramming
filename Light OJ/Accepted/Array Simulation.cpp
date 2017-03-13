#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;

int main()
{
    int T, kase=0;
    string p;
    char c;
    int a[150],b[150], n, m;
    int D, M, N, i, j, k, K, l;
    cin>>T;
    while(T--)
    {
        scanf("%d %d", &n, &m);
        scanf("%c", &c);

        for(i=0;i<n;i++)
        {
            cin>>a[i];

        }

        for(l=0;l<m;l++)
        {
           cin>>p;

           c=p[0];

            p.clear();
           if(c=='P')
           {
               cin>>M>>N;
               k=a[M];
               a[M]=a[N];
               a[N]=k;

           }
           if(c=='S')
           {
               cin>>D;
               for(i=0;i<n;i++)
                    a[i]+=D;

           }
           if(c=='M')
           {
               cin>>D;
               for(i=0;i<n;i++)
                    a[i]*=D;
           }
           if(c=='R')
           {

               for(i=0;i<n;i++)
                b[i]=a[i];

               for(i=0,j=n-1;i<n&&j>=0;i++,j--)
                   a[i]=b[j];

           }
           if(c=='D')
           {
               cin>>K;
               for(i=0;i<n;i++)
                    a[i]/=K;
           }
        }
        printf("Case %d:\n", ++kase);
        for(i=0;i<n-1;i++)
            printf("%d ", a[i]);

        cout<<a[i]<<endl;

    }

    return 0;
}

