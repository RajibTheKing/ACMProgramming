#include<iostream.h>
int main()
{
     int n, d;
     cin>>d;
     while(d--)
     {
          int a[1000], i, j, flag=0;
          cin>>n;

          i=-1;
          for(; ;)
          {
               j=n%2;
               a[++i]=j;
               n=n/2;
               if(n==0)
                    break;

          }


          for(j=0; j<=i; j++)
          {

              if(a[j]==1&&flag==0)
               {
                    printf("%d", j);
                    flag=1;
                    continue;
               }

              if(a[j]==1&&flag==1)
                    printf(" %d", j);
          }

          printf("\n");
     }

}
