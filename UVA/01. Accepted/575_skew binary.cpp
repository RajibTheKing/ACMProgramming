#include<iostream.h>
#include<string.h>
#include<math.h>

main()
{
    long long ans, t, tt;
    long long i, j, k, n;
    char a[10000];
    while(1)
    {
        memset(a, 0, sizeof(a));

        gets(a);
        if(a[0]=='0')
            break;

        k=strlen(a);
        n=k;
        ans=0;
        for(i=0; i<k; i++)
        {
            t=a[i]-'0';
            tt=pow(2, n)-1;
            ans=ans+(tt*t);

            n--;

        }

        cout<<ans<<endl;

    }
}
