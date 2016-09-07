#include<iostream.h>
int main()
{
    while(1)
    {
        int n, i, j, a, b, flag1, flag2;
        cin>>n;
        if(n==0)
            goto end;

        for(i=3; i<=n/2;i=i+2 )
        {
            flag1=1;
            flag2=1;
            if(n<6||n%2!=0)
                {
                    flag1=2; flag2=2;
                    break;
                }

            a=i;
            b=n-a;
            for(j=2; j<a; j++)
            {
                if(a%j==0)
                {
                    flag1=0;
                    break;
                }
            }
            for(j=2; j<b; j++)
            {
                if(b%j==0)
                {
                    flag2=0;
                    break;
                }
            }

            if(flag1==1&&flag2==1)
                break;

        }

        if(flag1==1&&flag2==1)
            printf("%d = %d + %d\n", n, a, b);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }
end:

    return 0;

}
