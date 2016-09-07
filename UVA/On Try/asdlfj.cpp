#include<stdio.h>
int calculate(int a, int b, int c)
{
    if(a<0) return 0;
    int r=a+b;
    printf("%d %d %d\n", a,b,r );
    c=calculate(a-1, b-2, c+1);
    r=b+c;
    printf("%d %d %d\n", b, c, r);
    return r;
}
main()
{
    calculate(3,5,3);
}
