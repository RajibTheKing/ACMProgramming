#include<iostream.h>
int main()
{
    int n;
    cin>>n;
    int a[1001], b[1001], i;
    for(i=0; i<n; i++)
        cin>>a[i]>>b[i];
    int sum=0, max=0;
    for(i=0; i<n ; i++)
        sum=sum+a[i];
    for(i=0; i<n ; i++)
        if(max<b[i])
            max=b[i];
    if(max>sum)
    {
        printf("%d", max-sum-1);
    }
    else
    {
        printf("-1");
    }



    return 0;
}
