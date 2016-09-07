#include<iostream.h>
#include<string.h>
char a[500];
char b[30]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ.";

main()
{
    int i, k, j, sum;
    while(1)
    {
        sum=0;
        memset(a, 0, sizeof(a));
        gets(a);
        if(a[0]=='#')
            break;
        k=strlen(a);
        for(i=0; i<k; i++)
        {
            for(j=0; j<30; j++)
            {
                if(a[i]==b[j])
                    break;
            }
            sum=sum+(i+1)*j;
        }
        printf("%d\n", sum);
    }

}
