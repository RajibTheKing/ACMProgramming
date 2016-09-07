#include<stdio.h>
#include<iostream.h>
int main()
{
    while(1)
    {
        int a[101];
        int i, j, flag;
        int n, ans=1, k, l;
        cin>>n;
        if(n==0)
            break;

        for(ans=1; ; ans++)
        {
            k=ans;
            l=0;
            flag=1;
            for(i=0; i<n; i++)
            {
                a[i]=i+1;

            }
            a[0]=0;

            for(i=0; ;i=(i+1)%n)
            {
                if(a[i]==0)
                    continue;
                l++;
                if(k==l)
                {
                    a[i]=0;
                    l=0;
                }
                if(a[12]==0)
                    break;
            }

            for(i=0; i<n; i++)
            {
                if(a[i]!=0)
                {
                    flag=0;
                    break;
                }

            }

            if(flag==1)
            {
                printf("%d\n", ans);
                break;
            }

        }
    }
    return 0;
}
