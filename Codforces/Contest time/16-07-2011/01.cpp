#include<stdio.h>
#include<string.h>
char a[105];
main()
{
    int i, j, k, t1, t2;
    while(scanf("%s", a)==1)
    {
        k=strlen(a);
        j=0;
        t1=0;
        t2=0;
        for(i=1;i<k;i++)
        {
            if(a[i]=='0')
            {
                t1++;
                t2=0;
            }
            else
            {
                t2++;
                t1=0;
            }

            if(t1>=7||t2>=7)
            {
                j=1;
                break;

            }

        }

        if(j==1)
            printf("YES\n");
        else
            printf("NO\n");

        memset(a, 0, sizeof(a));


    }
}
