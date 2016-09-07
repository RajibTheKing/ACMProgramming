#include<iostream.h>
#include<string.h>
char array[30]="_abcdefghijklmnopqrstuvwxyz.";

main()
{
    char a[100];
    int k;
    while(1)
    {
        int i, n, c[100], p[100], j, t;
        scanf("%d", &k);
        if(k==0)
            break;

        scanf(" %s", a);
        n=strlen(a);

        for(i=0; i<n; i++)
        {
            for(j=0; j<30; j++)
            {
                if(a[i]==array[j])
                    break;
            }
            c[i]=j;

        }

        for(i=0; i<n; i++)
        {
            t=k*i%n;
            p[t]=(i+c[i])%28;

        }

        for(i=0; i<n; i++)
            printf("%c", array[p[i]]);
        cout<<endl;


        memset(c, 0, sizeof(c));
        memset(p, 0, sizeof(p));
        memset(a, 0, sizeof(a));
    }
}
