#include<iostream.h>
#include<string.h>
char input[2005];
int a[130];
main()
{

    int n, k, i, t, j, flag, flag2, c;
    scanf("%d ", &n);
    c=0;
    while(n)
    {
        flag2=0;
        memset(a, 0, sizeof(a));
        gets(input);
        k=strlen(input);
        for(i=0; i<k; i++)
        {
            t=input[i];
            a[t]++;
        }

        printf("Case %d: ", ++c);
        for(i=20; i<123; i++)
        {
            if(a[i]<=1)
                continue;
            t=a[i];
            flag=0;
            for(j=2;j<t;j++)
            {
                if(t%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                flag2=1;
                printf("%c", i);
            }
        }
        if(flag2==0)
            printf("empty");
        printf("\n");
        memset(input, 0, sizeof(input));
        n--;
    }
}
