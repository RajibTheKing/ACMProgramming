#include<iostream.h>
#include<string.h>

int main()
{
     char a[50]="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
     char s;
     while(scanf("%c", &s)==1)
     {
          if(s==' ')
          {
               printf("%c", s);
               continue;
          }
          int t, i, flag=0;

          for(i=1; i<48; i++)
          {
               if(a[i]==s)
               {
                    flag=1;
                    t=i;
                    break;
               }
          }
          t--;
          if(flag==1)
          {
               printf("%c", a[t]);
               flag=0;
          }
          else
          printf("%c", s);



     }

}
