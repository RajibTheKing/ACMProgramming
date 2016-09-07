#include<iostream.h>
#include<string.h>

main()
{
    char a[150],b[150], list_1[150], list_2[150], x[150], y[150];
    char tt[10];
    int t, i, k, j, flag, len1, len2, l, f;
    gets(tt);
    t=atoi(tt);
    while(t--)
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
        memset(list_1, 0, sizeof(list_1));
        memset(list_2, 0, sizeof(list_2));
        gets(a);
        gets(b);
        k=strlen(a);
        l=strlen(b);

        j=-1;
        flag=0;
        for(i=0; i<k ;i++)
        {
            if(a[i]=='<')
            {
                a[i]='*';
                flag=1;
                continue;
            }
            if(a[i]=='>')
            {
                a[i]='*';
                break;
            }

            if(flag==1)
                list_1[++j]=a[i];
        }
        len1=j+1;


        j=-1;
        flag=0;

        for(i=0; i<k ;i++)
        {
            if(a[i]=='<')
            {
                a[i]='*';
                flag=1;
                continue;
            }
            if(a[i]=='>')
            {
                a[i]='*';
                break;
            }

            if(flag==1)
                list_2[++j]=a[i];
        }
        len2=j+1;




        flag=0;
        j=-1;

        for(i=0; i<k ;i++)
        {
            if(a[i]=='*' and flag==0)
            {
                flag=1;
                a[i]='<';
                x[++j]=a[i];
                continue;
            }
            if(flag==1 and a[i]=='*')
            {
                a[i]='>';
                x[++j]=a[i];
                continue;
            }
            if(a[i]==' 'and flag==1)
                break;
            if(a[i]=='\n' and flag==1)
                break;

            if(flag==1)
                x[++j]=a[i];

        }


        flag=0;
        j=-1;

        for(i=0; i<k ;i++)
        {
            if(a[i]=='*' and flag==0)
            {
                flag=1;
                a[i]='<';
                y[++j]=a[i];
                continue;
            }
            if(flag==1 and a[i]=='*')
            {
                a[i]='>';
                y[++j]=a[i];
                continue;
            }
            if(a[i]==' 'and flag==1)
                break;
            if(a[i]=='\n' and flag==1)
                break;

            if(flag==1)
                y[++j]=a[i];

        }


        for(i=0; i<k; i++)
        {
            if(a[i]=='<' or a[i]=='>')
                continue;

            printf("%c", a[i]);
        }
        cout<<endl;

        //11111111111111111111111111111111111111111111111111111111111111111111111111111111111

        flag=0;

        for(i=0; i<l ; i++)
        {
            if(b[i]=='.' and flag==0)
            {
                flag=1;

                for(j=0; j<strlen(x); j++)
                {
                    if(x[j]=='<')
                    {
                        for(k=0; k<len2; k++)
                            printf("%c", list_2[k]);
                        break;
                    }

                    printf("%c", x[j]);

                }


                f=0;
                for(j=0; j<strlen(x); j++)
                {
                    if(x[j]=='<')
                    {
                        f=1;
                        continue;
                    }
                    if(x[j]=='>')
                    {
                        f=0;
                        continue;
                    }

                    if(f==0)
                        printf("%c", x[j]);

                }


                printf(" ");

                for(j=0; j<strlen(y); j++)
                {
                    if(y[j]=='<')
                    {
                        for(k=0; k<len1; k++)
                            printf("%c", list_1[k]);
                        break;

                    }
                    printf("%c", y[j]);

                }



                f=0;
                for(j=0; j<strlen(y); j++)
                {

                    if(y[j]=='<')
                    {
                        f=1;
                        continue;
                    }
                    if(y[j]=='>')
                    {
                        f=0;
                        continue;
                    }

                    if(f==0)
                        printf("%c", y[j]);

                }
            }

            if(b[i]=='.' and flag==1)
                continue;

            printf("%c", b[i]);

        }
        cout<<endl;




    }

}
