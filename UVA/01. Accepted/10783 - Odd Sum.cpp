#include<iostream.h>
main()
{
    int n;
    cin>>n;
    int count=0;
    while(n)
    {
        int a, b;
        int i;
        int sum=0;
        cin>>a>>b;
        for(i=a; i<=b; i++)
        {
            if(i%2==1)
            sum=sum+i;
        }
        printf("Case %d: %d\n", ++count, sum);
        n--;
    }
}
