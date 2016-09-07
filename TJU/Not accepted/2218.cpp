#include<stdio.h>
#include<iostream.h>
#include<math.h>
int main()
{
    while(1)
    {
        long long n, k, p, i, j, d, l, flag;

        cin>>n;
        if(n==0)
            goto end;
        l=n;
        k=2006;
        if(n<16)
        {
            n=pow(n,n);
            p=n%k;
            cout<<p<<"\n";
        }
        else if(n>=16&&n<=10000)
        {
            d=223;
            p=1;
            for(i=0; i<l; i++)
            {
                n=n*l;


                while(n>1)
                {
                    if(n%d==0)
                    {
                        n=n/d;
                        p=p*d%k;

                        d=1;
                    }
                    d++;

                }
                d=13;


            }

            cout<<p%k<<"\n";
        }
        else
        {
            p=1;
            for(i=0; i<l; i++)
            {
                n=n*l;
                d=n;

                while(n>1)
                {
                    if(n%d==0)
                    {
                        n=n/d;
                        p=p*d%k;

                        d=1;
                    }
                    d++;

                }


            }

            cout<<p%k<<"\n";
        }

    }
end:

    return 0;

}
