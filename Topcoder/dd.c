#include<stdio.h>
main()
{
    char c;
    int q=50;
    char d;
    d=q%10+'0';
    q/=10;
    c=q+'0';
    printf("%c%c", c, d);
}
