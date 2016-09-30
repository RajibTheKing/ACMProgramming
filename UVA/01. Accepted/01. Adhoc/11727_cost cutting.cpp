#include<iostream.h>
#include<math.h>
main()
{
    int n, a, b, c, avg, min, i, flag, j=0;
    int d[3];
    cin>>n;
    while(n)
    {
        scanf("%d %d %d", &a, &b, &c);
        avg=(a+b+c)/3;

        d[0]=abs(avg-a); d[1]=abs(avg-b); d[2]=abs(avg-c);

        min=999999;
        for(i=0; i<3; i++)
        {
            if(min>d[i])
            {
                min=d[i];
                flag=i;
            }
        }

        if(flag==0)
            printf("Case %d: %d\n", ++j, a);
        else if(flag==1)
            printf("Case %d: %d\n", ++j, b);
        else
            printf("Case %d: %d\n", ++j, c);
        n--;
    }
}
