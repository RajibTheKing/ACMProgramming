#include<stdio.h>
#include<string.h>

int main()
{
    char a[1000];
    int sum;
    int i , j, k;


    while(gets(a))
    {
        k=strlen(a);
        sum=0;

        for(i=0; i<k; i++)
        {
            if(a[i]=='\n')
                printf("%c", a[i]);

            if(a[i]>='0' && a[i]<='9')
                sum+=a[i]-'0';

            if(a[i]=='b')
            {

                for(j=0; j<sum; j++)
                    printf(" ");
                sum=0;
            }

            if(a[i]>='A'&&a[i]<='Z')
            {

                for(j=0; j<sum; j++)
                    printf("%c", a[i]);
                sum=0;
            }
            if(a[i]=='*')
            {

                for(j=0; j<sum; j++)
                    printf("%c", a[i]);
                sum=0;
            }

            if(a[i]=='!')
                printf("\n");


        }
        printf("\n");


    }
    return 0;
}
