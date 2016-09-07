#include<iostream.h>
#include<string.h>

typedef struct node
{
    int info;
    int ff;
};


main()
{
    node dp[27];
    char a[30];
    int i , j, t, flag=0, t1, t2, temp;
    char c, d, q1, q2;

    gets(a);
    t=atoi(a);

    while(t--)
    {

        for(i=0; i<27; i++)
        {
            dp[i].info=i;
            dp[i].ff=0;

        }

        scanf("%c", &c);
        scanf("%c", &c);
        d=c;
        scanf(" ");

        flag=0;

        for(; ;)
        {
            memset(a, 0, sizeof(a));
            j=-1;
            for(; ;)
            {
                scanf("%c", &c);
                if(c=='\n'&&flag==0)
                {
                    flag=1;
                    break;
                }
                else if(c=='\n'&&flag==1)
                {
                    flag=2;
                    break;
                }
                else
                {
                    flag=0;
                    a[++j]=c;
                }

            }

            if(flag==2)
                break;

            t1=a[0]-'A';
            t2=a[1]-'A';

            if(t1>t2)
            {
                temp=t1;
                t1=t2;
                t2=temp;
            }

            if(dp[t1].ff==0)
            {
                dp[t1].info=t1;
                dp[t1].ff=1;
                dp[t2].info=t1;
                dp[t2].ff=1;
            }
            else
            {
                temp=dp[t1].info;
                dp[t1].info=temp;
                dp[t1].ff=1;
                dp[t2].info=temp;
                dp[t2].ff=1;

            }
        }

      //  std::sort(dp.info, dp.info+27);

        for(i=0; i<d+1-'A'; i++)
        printf("%d : %d\n", dp[i].info, dp[i].ff);
        cout<<endl;
    }

}
