#include<iostream.h>
int a[25];

main()
{
    int t, i, j,sum, n, temp, flag;
    cin>>t;
    while(t)
    {
        cin>>n;
        for(j=0;j<n;j++)
            scanf("%d", &a[j]);
        sum=0;
        for(i=0; i<=j; i++)
            sum+=a[i];
        flag=0;
        if(sum%4==0)
        {
            temp=sum/4;
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {

                }
            }

        }
        else
            printf("no\n");
        t--;
    }
}
