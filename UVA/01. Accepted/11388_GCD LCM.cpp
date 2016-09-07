#include<stdio.h>
main()
{
    int t, g, l, f=-1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &g, &l);
        if(l%g==0)
            printf("%d %d\n", g, l);
        else
            printf("%d\n", f);
    }
}
