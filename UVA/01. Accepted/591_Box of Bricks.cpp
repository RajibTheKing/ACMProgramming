#include<iostream.h>
main()
{
    int a[100];
    int n, i,j , avg, sum, count, set=0;
    while(1)
    {
        memset(a, 0, sizeof(a));
        cin>>n;
        set++;
        if(n==0)
            break;
        for(i=0; i<n; i++)
            cin>>a[i];
        sum=0;
        for(i=0; i<n; i++)
            sum+=a[i];
        avg=sum/n;

        count=0;
        std::sort(a, a+n);

        j=n-1;

        for(i=0;i<n;i++)
        {
            if(a[i]<avg)
            {
                for(; ;)
                {
                    count++;
                    a[i]++;
                    if(a[j]>avg)
                        a[j]--;
                    else
                    {
                        j--;
                        a[j]--;
                    }
                    if(a[i]==avg)
                        break;
                }
            }
        }

        printf("Set #%d\n", set);
        printf("The minimum number of moves is %d.\n\n", count);
    }

}
