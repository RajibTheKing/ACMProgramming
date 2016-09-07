
#include<iostream.h>
#include<string.h>
main()
{
    char a[20];
    int b[20];
    int n, i, j, k, total, t1, t2, p;
    gets(a);
    n=atoi(a);
    while(n--)
    {
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
        scanf(" %[^\n]", a);
        k=strlen(a);
        if(k!=19)
        {
            total=11;
            goto output;
        }

        t1=0;
        t2=0;

        j=-1;
        for(i=0; i<k; i+=2)
        {
            if(a[i]==' ') i++;
            b[++j]= 2*(a[i]-'0');
        }

        for(i=0; i<=j; i++)
        {
            if(b[i]>=10)
                p=b[i]%10+1;
            else
                p=b[i];
            t1=t1+p;
        }

        for(i=1; i<k ;i+=2)
        {

            t2=t2+a[i]-'0';
            if(a[i+1]==' ') i++;

        }

        total=t1+t2;
output:
        if(total%10==0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
}
