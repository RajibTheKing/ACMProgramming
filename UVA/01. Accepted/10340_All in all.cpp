#include<iostream.h>
#include<string.h>

char s[9000000], t[9000000];

main()
{
    int k, l, i, j;

    while(scanf(" %s %s", s, t)==2)
    {
        k=strlen(s);
        l=strlen(t);

        for(i=0, j=0; i<k&&j<l; j++)
        {
            if(s[i]==t[j])
                i++;
        }

        if(k==i)
            printf("Yes\n");
        else
            printf("No\n");

        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
    }

}
