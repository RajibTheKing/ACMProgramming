#include<iostream.h>
main()
{
    long long l, h, v, s, count, n1, n2, temp, n;
    while(1)
    {
        cin>>n1>>n2;
        if(n1==0&&n2==0)
            break;

        if(n2<n1)
        {
            temp=n1;
            n1=n2;
            n2=temp;
        }

        s=0;

        for(n=n1; n<=n2; n++)
        {
            count=0;
            temp=n;
            if(temp==0)
                continue;
            for(; ;)
            {
                if(temp%2==0)
                {
                    count++;
                    temp=temp/2;
                }
                else
                {
                    count++;
                    temp=(temp*3)+1;
                }
                if(temp==1)
                    break;

            }
            if(s<count)
            {
                s=count;
                v=n;
            }

        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",n1, n2, v, s);
    }
}
