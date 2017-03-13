
#include<iostream>
#include<stdio.h>

using namespace std;

int fact(int n)
{
    if(n<=1) return 1;
    else return n*fact(n-1);

}
int main()
{
    printf("n e\n");
    printf("- -----------\n");
    double sum = 0;

    for(int i=0;i<=9;i++)
    {
        sum = sum + 1.0/fact(i);

        if(i<3)
            printf("%d %g\n", i, sum);
        else
            printf("%d %0.9lf\n", i, sum);
    }


    return 0;
}
