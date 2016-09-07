#include<iostream.h>
#include<math.h>
int main()
{
    while(1)
    {
        long long  prime[25000], tr[100000];
        long long i, j, flag, count=0, t;
        long long a, d, n, temp;
        cin>>a>>d>>n;
        if(a==0&&d==0&&n==0)
            goto end;
        t=0;
        for(i=0; ; i++)
        {
            tr[i]=a+(t*d);
            t++;
            temp=tr[i];
            if(temp==1)
                continue;
            flag=1;
            for(j=2; j<=sqrt(temp); j++)
            {
                if(temp%j==0)
                    {
                        flag=0;
                        break;
                    }
            }
            if(flag==1)
            {
                count++;
                prime[count]=temp;

            }
            if(n==count)
                break;


        }







        printf("%lld\n", prime[n]);
        memset(prime, 0 , sizeof(prime));
        memset(tr, 0, sizeof(tr));


    }
end:

    return 0;
}
