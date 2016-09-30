#include<iostream>
using namespace std;
#include<math.h>

int main()
{
    int N,B,i,j,p,c,noz,k;
    while (scanf("%d%d",&N,&B)!=EOF)
    {
          noz=N;
          j=B;
          for (i=2;i<=B;i++)
          {
              if (j%i==0)
              {
                 p=0;
                 while (j%i==0)
                 {
                       p++;
                       j/=i;
                 }
                 c=0;
                 k=N;
                 while (k/i>0)
                 {
                       c+=k/i;
                       k/=i;
                 }
                 noz=min(noz,c/p);
              }
          }
          double ans=0;
          for (i=1;i<=N;i++)
          {
              ans+=log(i);
          }
          ans/=log(B);ans+=1.0;
          ans=floor(ans);
          printf("%d %.0lf\n",noz,ans);
    }
}
