#include<stdio.h>
int main()
{
    int n;
    int a[10005];
    int i;
    bool flag = false, flag2;
    while(scanf("%d", &n)==1)
    {
        if(n==0) break;

        flag = false;
        flag2 = false;

        for(i=0;i<n;i++)
            scanf("%d", &a[i]);

        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                flag = true;
                if(flag2==true)
                    printf(" %d", a[i]);
                else
                {
                    printf("%d", a[i]);
                    flag2 = true;
                }
            }
        }

        if(flag==false)
            printf("0");

        printf("\n");
    }
    return 0;
}
