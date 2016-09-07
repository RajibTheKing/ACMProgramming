#include<stdio.h>
int main()
{
    int y, flag=0;
    while(scanf("%d", &y)==1)
    {
        if(y>=2000)
        {
            if(y%4!=0&&y%15!=0&&y%55!=0)
                {
                    printf("This is an ordinary year.\n");
                    goto next;
                }

            if(y%4==0)
            {
                if(y%100!=0)
                    {
                        printf("This is leap year.\n");
                        if(y%15==0)
                            printf("This is huluculu festival year.\n");
                        if(y%55==0)
                            printf("This is bulukulu festival year.\n");
                        flag=1;
                    }

                if(y%400==0)
                    {
                        printf("This is leap year.\n");
                        if(y%15==0)
                            printf("This is huluculu festival year.\n");
                        if(y%55==0)
                            printf("This is bulukulu festival year.\n");
                        flag=1;

                    }


                if(flag==1)
                    goto next;
                if(y%100==0)
                printf("This is an ordinary year.\n");
            }

            else
            {
                if(y%15==0)
                    printf("This is huluculu festival year.\n");
            }
next:
            printf("\n");
            flag=0;
        }
    }
    return 0;
}
