#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c;
    int d1, d2;
    int check;
    while(scanf("%d %d %d", &a, &b, &c)==3)
    {
        d1=b-a;
        d2=c-b;
        if(d1>d2)
            check=d1-1;
        else
            check=d2-1;
        printf("%d\n", check);
    }


    return 0;
}

