#include<iostream.h>
#include<string.h>

char a[1005][11], b[1005][50], d[50], f[50];
int j=0, i=-1, k, t[1005], tt=-1, p, l, count, flag, u, q;
char c;

void check(void)
{

      for(j=0; j<k; j++)
      {
            strcpy(f, d);

            flag=0;
            for(i=0; i<t[j]; i++)
            {
                  c=a[j][i];
                  flag=0;
                  for( u=0; u<p ;u++)
                  {
                        if(f[u]==' ')
                              continue;

                        if(c==f[u])
                        {
                              flag=2;
                              f[u]='`';
                              break;
                        }
                  }

                  if(flag==0)
                        break;
            }
            if(flag==2)
                  count++;
      }

      printf("%d\n", count);
      return;
}

int main()
{


      while(1)
      {
            scanf("%c" , &c);
            if(c=='#')
                  break;

            a[j][++i]=c;

            if(c=='\n')
            {
                  j++;
                  t[++tt]=i;
                  i=-1;
            }

      }
      k=j;
      scanf("\n");

      while(gets(d))
      {
            if(d[0]=='#')
                  break;
            p=strlen(d);
            count=0;
            check();

            memset(d, 0, sizeof(d));
      }



}
