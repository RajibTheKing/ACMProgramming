#include<iostream.h>
main()
{
    int n;
    cin>>n;
    int k;
    k=0;
    while(n)
    {


        int a[3];
        int max=0, min=10001;
        int i=-1, t1, t2, ans;
        cin>>a[++i]>>a[++i]>>a[++i];
        for(i=0; i<3; i++)
        {
            if(a[i]<min)
            {
                min=a[i];
                t1=i;
            }
        }
        for(i=0; i<3; i++)
        {
            if(a[i]>max)
            {
                max=a[i];
                t2=i;
            }
        }
        for(i=0; i<3; i++)
        {
            if(i!=t1&&i!=t2)
                ans=i;
        }
        printf("Case %d: %d\n", ++k, a[ans]);

        n--;
    }
}
