#include<stdio.h>
main()
{
    int h1, h2, m1, m2;
    int i, j, t1, t2, ans ;

    while(1)
    {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if(h1==0&&m1==0&&h2==0&&m2==0) break;
        i=0;

        if(m2<m1)
        {

            m2+=60;
            i=1;
        }

        if((h2-i)<h1)
        {
            h2+=24;
        }

        t2=m2-m1;
        t1=h2-i-h1;
        ans=t1*60+t2;

        printf("%d\n", ans);
    }
}
