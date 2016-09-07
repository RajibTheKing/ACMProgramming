#include<stdio.h>
int main()
{

    int y, flag, f;
    while(scanf("%d", &y)==1)
    {
        f=0;
        flag=0;
        if(y%4==0)
        {
            if(y%100!=0)
            {
                f=1;
                flag=1;
                printf("This is leap year.\n");
                if(y%15==0)
                    printf("This is huluculu festival year.\n");
                if(y&55==0)
                    printf("This is buluculu festival year.\n");
            }
            if(y%400==0)
            {
                f=1;
                flag=1;
                printf("This is leap year.\n");
                if(y%15==0)
                    printf("This is huluculu festival year.\n");
                if(y&55==0)
                    printf("This is buluculu festival year.\n");
            }
        }
        if(flag==0)
            if(y%15==0)
                {
                    f=1;
                    printf("This is huluculu festival year.\n");
                }
        if(f==0)
            printf("This is an ordinary year.\n");
        printf("\n");
    }
}
