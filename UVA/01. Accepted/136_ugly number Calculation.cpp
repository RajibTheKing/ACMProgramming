#include<stdio.h>
#include<math.h>

int uglynumber[1501];

void calculate(void)
{

    int i, j, k, l, f, q;
    l=0;
    uglynumber[++l]=1;

    for(i=2;i<900000000;i++)
    {
        f=i;
        while(f%2==0||f%3==0||f%5==0)
        {
            if(f%2==0)
                f=f/2;
            else if(f%3==0)
                f=f/3;
            else if(f%5==0)
                f=f/5;
        }
        if(f>5)
            continue;

        uglynumber[++l]=i;
        printf("Ugly Number[%lld]:  %lld\n", l, uglynumber[l]);

    }

}

main()
{
    calculate();

    printf("%d\n", uglynumber[1500]);


}
