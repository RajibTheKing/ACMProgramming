#include<iostream.h>
#include<string.h>
int main()
{
    char a[5000], b[5000];
    while(1)
    {
        int temp, sum, k;
        gets(a);
        if(a[0]=='0')
            break;
        k=strlen(a);

        for(int i=0;i<k;i++)
        {
            sum=0;
            for(int i=0;i<k ;i++)
                sum=sum+a[i]-48;
        }
        temp=sum;
        for(; ;)
        {
            if(temp<10)
                break;
            sum=0;

            for(; ;)
            {
                sum=sum+temp%10;
                temp=temp/10;
                if(temp==0)
                    break;
            }
            temp=sum;
        }
        printf("%d\n", temp);
    }
    return  0;
}
