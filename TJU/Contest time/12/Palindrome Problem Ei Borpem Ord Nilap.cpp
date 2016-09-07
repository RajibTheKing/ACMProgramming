#include<iostream.h>
#include<string.h>

int main()
{
     char a[100], b[100], c[100];
     int i, j, k, t, flag;

     while(1)
     {
          memset(a, 0, sizeof(a));
          memset(b, 0, sizeof(b));
          memset(c, 0, sizeof(c));
          flag=0;
          for(i=0; ; i++)
          {
               scanf("%c", &a[i]);
               if(a[i]=='\n')
                    break;
          }
          k=i;
          if(a[0]=='T'&&a[1]=='H'&&a[2]=='E'&&a[3]==' '&&a[4]=='E'&&a[5]=='N'&&a[6]=='D'&&a[7]=='.')
               break;

          j=-1;
          for(i=0; i<k; i++)
          {
               if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
               {
                    b[++j]=a[i];
                    flag=1;
               }
             else
               continue;
          }
          if(flag==0)
               continue;

          for(i=0; i<=j; i++)
               b[i]=toupper(b[i]);

          t=-1;
          for(i=j; i>=0; i--)
              c[++t]=b[i];

          for(i=0; i<=j; i++)
               if(b[i]!=c[i])
               {
                    flag=0;
                    break;
               }


          if(flag==1)
               printf("Yes\n");
          else
               printf("No\n");

     }
}
