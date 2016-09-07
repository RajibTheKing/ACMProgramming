#include<iostream.h>
#include<string.h>
char a[7], b[26], left[14], right[14], tt[26];
main()
{
    int n, i, j, t, k, l, M,c;
    char temp;
    scanf("%d ", &n);
    while(n)
    {
        gets(a);
        gets(b);
        k=strlen(a); l=strlen(b);
        for(i=0; i<k; i++)
            tt[i]=a[i];
        c=k;
        for(i=0; i<k; i++)
            a[i]=tt[--c];

        for(i=0; i<k; i++)
        {
            if(a[i]=='C')
            {
              temp=b[0];
              for(j=0; j<l-1; j++)
              {
                  b[j] = b[j+1];
              }
              b[l-1]=temp;

            }

            else if(a[i]=='J')
            {
                temp=b[l-1];
                for(j=l-1; j>0; j--)
                {
                    b[j]=b[j-1];
                }
                b[j]=temp;
            }

            else if(a[i]=='E')
            {
                if(l%2==0){
                M=l/2;
                for(j =0;j<M;j++)
                {
                    left[j] =b[j];
                }
                c=-1;
                for(j=M; j<l; j++)
                {
                    right[++c]=b[j];
                }
                c=-1;
                for(j=0; j<M; j++)
                {
                    b[j]=right[++c];
                }
                c=-1;
                for(j=M; j<l; j++)
                {
                    b[j]=left[++c];
                }


                }
                else
                {
                    M=l/2;
                    c=-1;
                    for(j=0; j<M; j++)
                        left[++c]=b[j];
                    c=-1;
                    for(j=M+1; j<l; j++)
                        right[++c]=b[j];
                    c=-1;
                    for(j=0; j<M; j++)
                        b[j]=right[++c];
                    c=-1;
                    for(j=M+1; j<l; j++)
                        b[j]=left[++c];


                }
            }
           else if(a[i]=='A')
            {
                for(j=0; j<l; j++)
                    tt[j]=b[j];
                c=l;
                for(j=0; j<l; j++)
                    b[j]=tt[--c];
            }
            else if(a[i]=='M')
            {
               for(j=0; j<l; j++)
               {
                   if(b[j]<='9' && b[j]>='0')
                    {
                        t=b[j]-48+10+1;

                        t=t%10;
                        b[j]=t+48;
                    }
               }


            }
            else if(a[i]=='P')
            {
                for(j=0; j<l; j++)
                {
                    if(b[j]<='9'&&b[j]>='0')
                    {
                        t=b[j]-48+10-1;
                        t=t%10;
                        b[j]=t+48;
                    }
                }


            }
            else
                continue;

        }
        puts(b);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        n--;
    }

}
