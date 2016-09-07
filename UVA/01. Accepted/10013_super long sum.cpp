#include<stdio.h>
#include<string.h>


char x[1000010][5], c;
int ans[1000050], m, n, i, j, h, temp;

int main()
{
    scanf("%d", &n);
    scanf("%c", &c);
    while(n--)
    {
        memset(x, 0, sizeof(x));
        scanf("%d", &m);
        scanf("%c", &c);
        for(i=0; i<m; i++)
            gets(x[i]);

        h=0;j=-1;
        for(i=m-1; i>=0; i--)
        {
            temp=x[i][0]+x[i][2]-'0'+h-'0';

            if(temp>=10)
            {
                temp=temp%10;
                h=1;
            }
            else
                h=0;
            ans[++j]=temp;
        }

        for(i=j; i>=0; i--)
            printf("%d", ans[i]);

        if(n>0)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}
