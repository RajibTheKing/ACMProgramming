#include<iostream>
using namespace std;

long long a[1000];

main()
{
    long long i,f, k, t,c, n, q=233919883, p=19;
    k=-1;
    int t1;
    int t2;
    for(i=47;;i++)
    {

        f=0;
        t=i;
        for(; ;)
        {
            c=t%10;
            if(c!=4&&c!=7)
            {
                f=1;
                break;

            }
            t=t/10;
            if(t==0)
            break;
        }

        t1=0;t2=0;
        t=i;
        for(; ;)
        {
            c=t%10;
            if(c==4)
                t1++;
            else
                t2++;


            t=t/10;
            if(t==0)
            break;

        }
        if(t1!=t2)
            f=1;

        if(f==0)
            a[++k]=i;

        if(i==7744) i=444777;
        if(i==777444) i=44447777;
        if(i==47777444) i=74444777;
        if(i==77774444)
            break;
    }
    a[++k]=q*p;
    while(cin>>n)
    {
        for(i=0;i<=k;i++)
        {
            if(n==a[i])
            {
                cout<<a[i]<<endl;
                break;
            }
            else if(n<a[i])
            {
                cout<<a[i]<<endl;
                break;
            }

        }
    }


}
