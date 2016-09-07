#include<iostream.h>
int a[1001];
int main()
{
    int c;
    scanf("%d", &c);
    while(c)
    {
        int n, i;
        float avg, sum=0, ans,count=0;
        scanf("%d", &n);
        for(i=0;i<n; i++)
        {
            scanf("%d", &a[i]);
            sum=sum+a[i];
        }
        avg=sum/n;
        for(i=0; i<n; i++)
        {
            if(a[i]>avg)
                count++;
        }
        ans=(count*100)/n;
        printf("%0.3f", ans);
        printf("%%\n");
        c--;
    }

    return 0;
}
