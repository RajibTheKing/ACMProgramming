#include<stdio.h>

int main()
{
    int n, x[10000], y[10000];
    int i;
    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d %d", &x[i], &y[i]);

    for(i=0; i<n; i++)
    {
        if(x[i]%2==0&&y[i]%2==0)
        {
            if(x[i]==y[i])
                printf("%d\n", x[i]+y[i]);

            else if(x[i]==y[i]+2)
                printf("%d\n", x[i]+y[i]);
            else
                printf("No Number\n");

        }
        else if(x[i]%2!=0&&y[i]%2!=0)
        {
            if(x[i]==y[i])
                printf("%d\n", x[i]+y[i]-1);
            else if(x[i]==y[i]+2)
                printf("%d\n", x[i]+y[i]-1);
            else
                printf("No Number\n");
        }
        else
        {
            printf("No Number\n");
        }

    }


    return 0;
}
