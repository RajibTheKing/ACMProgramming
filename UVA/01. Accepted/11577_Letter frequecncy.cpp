#include<iostream.h>
#include<string.h>
char a[301];
main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("\n");
        gets(a);
        int k, i, j, max=0;
        k=strlen(a);
        int b[130];
        memset(b, 0, sizeof(b));
        for(i=0; i<k; i++)
        {
            if(a[i]>='A'&&a[i]<='Z')
                a[i]=a[i]+32;
        }

        for(i=0; i<k; i++)
        {
            if(a[i]>='a'&&a[i]<='z')
            {
                j=a[i];
                b[j]++;
            }
        }
        for(i=97; i<123; i++)
            if(max<b[i])
                max=b[i];
        if(max>0)
            for(i=97; i<123; i++)
            {
                if(b[i]==max)
                    printf("%c", i);
            }
        printf("\n");
    }
}
