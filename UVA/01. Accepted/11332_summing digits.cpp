#include<iostream.h>
#include<string.h>
main()
{
    char a[10000];
    long long n, k, i, j, t;

    while(1)
    {
        memset(a, 0, sizeof(a));
        gets(a);
        if(a[0]=='0')
            break;
        k=strlen(a);
        n=0;
        for(i=0; i<k; i++)
            n=n+a[i]-'0';



        for(; ;)
        {
            t=n;
            n=0;
            for(; ;)
            {
                n=n+(t%10);
                t=t/10;
                if(t==0)
                    break;

            }

            if(n<10)
                break;
        }

        cout<<n<<endl;

    }

}
