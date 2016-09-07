#include<stdio.h>
int main()
{
    double n, p;
    long k;
    while (scanf("%lf %lf", &n, &p)==2)
    {
        k= pow(p, 1/n);


       printf("%ld\n", k);
    }
    return 0;
}
