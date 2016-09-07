#include<stdio.h>
#include<string.h>

char board[150][150];


main()
{
    char c, t;
    int kase=0;
    int n, m;
    int i, j, k;
    while(1)
    {
        scanf("%d%d", &n, &m);
        scanf("%c", &c);

        if(n==0&&m==0)
            break;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%c", &board[i][j]);
            scanf("%c", &t);
        }

        if(kase) printf("\n");
        printf("Field #%d:\n", ++kase);
        int z;

        for(z=1;z<=n+1;z++)
				board[z][m+1]='\0';

        for(z=1;z<=m+1;z++)
				board[n+1][z]='\0';

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                k=0;
                t=board[i][j];
                if(t=='*')
                    printf("%c", board[i][j]);
                else
                {
                    if(board[i][j-1]=='*') k++;
                    if(board[i-1][j-1]=='*') k++;
                    if(board[i-1][j]=='*') k++;
                    if(board[i-1][j+1]=='*') k++;
                    if(board[i][j+1]=='*') k++;
                    if(board[i+1][j+1]=='*') k++;
                    if(board[i+1][j]=='*') k++;
                    if(board[i+1][j-1]=='*') k++;
                    printf("%d", k);
                }
            }
            printf("\n");
        }
    }
}
