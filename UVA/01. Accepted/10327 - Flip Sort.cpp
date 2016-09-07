#include<iostream.h>
#include<string.h>
int a[1001];
int main()
{
    int n;
    while(scanf("%d", &n)==1)
    {
       int i, j, temp, count=0;
       for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(i=0; i<n;i++)
        {
            for(j=0;j<n-i-1; j++)
            {
                if(a[j]>a[j+1])
                {
                    count++;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }

            }

        }
        printf("Minimum exchange operations : %d\n", count);
    }

    return 0;
}
