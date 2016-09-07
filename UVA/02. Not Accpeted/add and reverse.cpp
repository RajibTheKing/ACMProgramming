#include<iostream.h>
int main()
{
    long long n, c, t1, t2, temp, a[15];
    int i, j, count, add;
    cin>>c;
    while(c>0)
    {
        add=0;
        cin>>n;
        temp=n;

        for(j=0; ; j++)
        {
            t1=temp;
            count=0;
            for(i=0; ; i++)
            {
                count++;
                a[i]=temp%10;
                if(temp<10)
                    break;
                temp=temp/10;

            }
            t2=0;
            for(i=0; i<count; i++)
                t2=t2*10+a[i];

            if(t1==t2)
                break;
            temp=t1+t2;
            add++;

        }
        printf("%d %d\n", add, t1);
    }
    return 0;
}
