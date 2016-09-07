#include<iostream.h>
int main()
{
    int n, m, p, q, sum;
    int t, flag, t2;
    cin>>t;
    while(t--)
    {

        cin>>n;
        t2=n;
        p=0;
        for(; ;)
        {
            p++;
            n=n/10;
            if(n==0)
                break;
        }

        p=p*9;
        sum=0;
        flag=0;
        int i;
        n=t2;
        for(i=p;i>=0 ;i--)
        {
            m=n-i;
            sum=m;
            t2=m;

            for(; ;)
            {
                q=m%10;
                sum=sum+q;
                m=m/10;
                if(m==0)
                    break;
            }



            if(sum==n)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            m=t2;
            cout<<m<<endl;
        }
        else
        {
            m=0;
            cout<<m<<endl;
        }


    }
}
