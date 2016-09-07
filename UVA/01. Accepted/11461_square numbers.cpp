#include<iostream.h>
#include<math.h>

int a[100000];
main()
{
   int i, j, t, count, b, c, temp;
   t=1;

   for(; ;)
   {
       i=t*t;
       if(i>100000)
        break;
       a[i] = 1;
       t++;
    }
    while(1)
    {
        cin>>b>>c;

        if(b==0 and c==0)
            break;
        if(b>c)
        {
            temp=b;
            b=c;
            c=temp;
        }
        count=0;
        for(i=b; i<=c; i++)
            if(a[i]==1)
                count++;
        printf("%d\n", count);
    }

}
