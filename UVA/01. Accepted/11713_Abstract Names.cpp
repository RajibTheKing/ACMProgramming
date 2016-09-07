#include<iostream.h>
#include<string.h>

main()
{
    char a[25];
    char b[25];
    int i, j, k, l, n, flag;
    gets(a);
    n=atoi(a);
    while(n--)
    {
        scanf(" %s %s", a, b);

        k=strlen(a);
        l=strlen(b);
        flag=1;
        if(k!=l)
        {
            flag=0; goto output;
        }

        for(i=0; i<k; i++)
        {
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
                continue;

            if(a[i]!=b[i])
            {
                flag=0;
                break;
            }
        }

output:
        if(flag==0)
            printf("No\n");
        else
            printf("Yes\n");
    }

}
