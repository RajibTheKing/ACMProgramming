#include<stdio.h>
#include<iostream.h>
int main()
{

    char a[1005], b[30], d;
    int n;
    int i, j, k, l, o;
    scanf("%d\n", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; ; j++)
        {
            scanf("%c", &a[j]);

            if(a[j]=='\n')
                break;

        }
        j--;

        for(k=1; ;k++)
        {
            scanf("%c", &b[k]);
            if(b[k]=='\n')
            {
                k--;
                break;
            }
        }
//        for(l=1; l<=k; l++)
//         printf("%d. %c\n", l, b[l]);
        printf("%d ", i);
        for(l=1; l<=j; l++)
        {
            if(a[l]>='A'&&a[l]<='Z')
            {
                d=a[l];
                o=d-64;
                printf("%c", b[o]);
            }
            else
            printf("%c", a[l]);
        }
        printf("\n");


    }
    return 0;
}
