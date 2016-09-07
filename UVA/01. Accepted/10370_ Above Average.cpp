#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, a, i, b[1005], sum;
    double ans, avg;


    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &a);
        for(i=0; i<a; i++)
            scanf("%d", &b[i]);
        sum=0;
        for(i=0; i<a; i++)
            sum=sum+b[i];

        avg=sum/a;
        int count;

        count = 0;

        for(i=0; i<a; i++)
            if(b[i]>avg)
                count ++;

        ans =(1.0*count*100)/(a*1.0);
        printf("%0.3lf%%\n", ans);


    }
}
