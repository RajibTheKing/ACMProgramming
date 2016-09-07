#include<stdio.h>
#include<string.h>
#include<math.h>

bool square[10005];
char a[10010];
char board[105][105];

main()
{
    char c;
    int i, j, k, t, n, l;
    for(i=1;i<=100;i++)
    {
        k=i*i;
        square[k]=true;

    }
    scanf("%d", &t);
    scanf("%c", &c);
    while(t--)
    {
        scanf(" %[^\n]", a);

        k=strlen(a);

        if(square[k]==true)
        {
            l=-1;
            n=sqrt(k);
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    board[i][j]=a[++l];
                }
            }

            for(j=0;j<n;j++)
            {
                for(i=0;i<n;i++)
                    printf("%c", board[i][j]);
            }
            printf("\n");

        }
        else
        {
            printf("INVALID\n");
        }

        memset(a, 0, sizeof(a));
    }
}
