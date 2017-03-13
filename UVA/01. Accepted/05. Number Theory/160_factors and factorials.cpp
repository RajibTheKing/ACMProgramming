#include<stdio.h>

main()
{
    int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    int a[26];

    int b,l, i, j, sum;

    while(scanf("%d", &b)==1)
    {
        if(b==0)
            break;

        for(i=0;i<26;i++)
        {
            l=b;
            sum=0;
            while(l>1)
            {
                sum=sum+l/prime[i];
                l=l/prime[i];
            }
            a[i]=sum;

        }
        int count=0;

        printf("%3d! =", b);
        for(i=0;i<26;i++)
        {
            if(a[i]&&(count%15!=0||count==0))
            {
                printf("%3d", a[i]);
                count++;

            }
            else if(count%15==0&&a[i])
            {
                printf("\n%9d", a[i]);
                count++;
            }


        }
        printf("\n");

    }
}
