#include<stdio.h>
#include<math.h>

int main()
{

    long long a[20005];
    long long  i , j , k, n, count=0, flag, s;
    scanf("%lld", &n);
    for(i=0; i<n; i++)
        scanf("%lld", &a[i]);

    for(i=0; i<n; i++)
    {
        k=2;
        for( ; ; )
        {
            flag=1;
            s=sqrt(k);

            for(j=2;j<=s ;j++)
            {
                if(k%j==0)
                {
                    flag=0;
                    break;
                }
            }

            if(flag==1)
                count++;

            if(count==a[i])
                {
                    count=0;
                    printf("%lld\n", k);
                    break;
                }
            k++;

        }
    }

    return 0;
}

