#include<iostream.h>
#include<string.h>
int main()
{
     int x, y;
     int  n, a, i, j, t;
     scanf("%d", &n);
     while(n--)
     {
          cin>>x;cin>>y;
          a=x+y;
          for( ; ;)
          {
               t=a%10;
               cout<<t;

               a=a/10;
               if(a==0)
                    break;

          }
          cout<<endl;
          cout<<endl;

     }
     return 0;
}

