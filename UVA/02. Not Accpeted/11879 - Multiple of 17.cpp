#include<iostream.h>
#include<string.h>
char a[105], c[105];
int i, k, n, flag;

void function(void)
{
    int temp, h, temp1, temp2;
    for(; ;)
    {
        temp=(a[k-1]-48)*5;
        a[k-1]=NULL;
        k=strlen(a);
        if(k<6)
            break;
        memset(c, 0, sizeof(c));
        c[k-1]=temp%10;
        temp=temp/10;
        c[k-2]=temp%10;
        h=0;
        for(i=k-1; i>=0; i--)
        {
            temp1=a[i]-48;
            temp2=c[i]-48;
            if(temp1<temp2)
            {
                temp1=temp1+10;
                h=1;
            }
            else
                h=0;
            temp=temp1-temp2;
            a[i]=temp;
            if(i==0)
                break;

            c[i-1]=h+c[i-1];
        }
    }
    return;
}

main()
{

    while(1)
    {
        gets(a);
        k=strlen(a);
        if(k<=6)
        {
            n=atoi(a);
            if(n==0)
                break;
        }
        else
        {
            function();
            n=atoi(a);
            cout<<n<<"ami: "<<endl;
        }

        if(n%17==0)
            flag=1;
        else
            flag=0;
        printf("%d\n", flag);

        memset(a, 0, sizeof(a));

    }

}
