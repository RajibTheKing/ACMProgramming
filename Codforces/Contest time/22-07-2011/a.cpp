#include<stdio.h>
#include<string.h>

char a[1005];

main()
{
    int i, j, k;
    char c;

    while(scanf("%s", a)==1)
    {
        k=strlen(a);
        for(i=0;i<k;i++)
            if(a[i]=='.')
                break;

        if(a[i-1]=='9')
        {
            printf("GOTO Vasilisa.\n");
            memset(a, 0, sizeof(a));
            continue;
        }

        c=a[i+1];
        k=c-48;
        if(k>=5)
        {
            a[i-1]++;
        }

        for(j=0;j<i;j++)
            printf("%c", a[j]);
        printf("\n");
        memset(a, 0, sizeof(a));
    }
}
