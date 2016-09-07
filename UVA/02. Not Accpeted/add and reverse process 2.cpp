#include<iostream.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long function(long temp)
{
    int i, k;
    char a[20];
    for(i=0; ; i++)
    {
        k=temp%10;
        a[i]=k+48;
        if(temp<10)
            break;
        temp=temp/10;
    }
    return atol(a);

}
int main()
{
    int c, i, count;
    cin>>c;
    while(c>0)
    {
        count=0;
        long n, t1, t2, temp, k;
        cin>>n;
        temp=n;
        for(; ;)
        {
            t1=temp;

            t2=function(temp);
            temp=t1+t2;

            if(t1==t2)
                break;
            count++;
        }
        printf("%ld %ld\n",count, t1 );



        c--;
    }
    return 0;
}
