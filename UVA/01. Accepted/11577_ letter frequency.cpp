#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>




int a[27];


int main()
{
    char b[1000];
    gets(b);

    int n;
    n=atoi(b);

    while(n--)
    {
        memset(a, 0, sizeof(a));

        gets(b);

        int i;

        for(i=0; i<strlen(b); i++)
        {
            b[i]=tolower(b[i]);
            int t;
            t=b[i]-'a';

            if(t>=0&&t<=26)
                a[t]++;
        }

        int max;
        max=0;
        for(i=0; i<27; i++)
        {

            if(a[i]>max)
                max=a[i];
        }


        for(i=0; i<27; i++)
            if(a[i]==max)
            {
                printf("%c", i+'a');
            }

        printf("\n");
    }


    return 0;

}
