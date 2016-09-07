#include<stdio.h>
#include<string.h>

char board[5][5];

main()
{
    char c;
    int i, j, k, X, O, kase=0;
    int t;
    scanf("%d", &t);
    scanf("%c", &c);

    while(t--)
    {
        memset(board, 0, sizeof(board));
        if(kase>0)
            scanf("%c", &c);

        for(i=0;i<3;i++)
            scanf(" %s", board[i]);



        O=0;X=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(board[i][j]=='O')
                    O++;
                if(board[i][j]=='X')
                    X++;
            }

        }
        if(X<O)
        {
            printf("no\n");
            continue;
        }
        else if((O+1)<X)
        {
            printf("no\n");
            continue;
        }
        else if(X==O+1)
        {
            if(board[0][0]=='O'&&board[0][1]=='O'&&board[0][2]=='O')
            {
                printf("no\n");
                continue;
            }
            else if(board[1][0]=='O'&&board[1][1]=='O'&&board[1][2]=='O')
            {
                printf("no\n");
                continue;
            }
            else if(board[2][0]=='O'&&board[2][1]=='O'&&board[2][2]=='O')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][0]=='O'&&board[1][0]=='O'&&board[2][0]=='O')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][1]=='O'&&board[1][1]=='O'&&board[2][1]=='O')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][2]=='O'&&board[1][2]=='O'&&board[2][2]=='O')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O')
            {
                printf("no\n");
                continue;
            }
            else
            {
                printf("yes\n");
                continue;
            }
        }
        else if(X==O)
        {
            if(board[0][0]=='X'&&board[0][1]=='X'&&board[0][2]=='X')
            {
                printf("no\n");
                continue;
            }
            else if(board[1][0]=='X'&&board[1][1]=='X'&&board[1][2]=='X')
            {
                printf("no\n");
                continue;
            }
            else if(board[2][0]=='X'&&board[2][1]=='X'&&board[2][2]=='X')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][0]=='X'&&board[1][0]=='X'&&board[2][0]=='X')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][1]=='X'&&board[1][1]=='X'&&board[2][1]=='X')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][2]=='X'&&board[1][2]=='X'&&board[2][2]=='X')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X')
            {
                printf("no\n");
                continue;
            }
            else if(board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X')
            {
                printf("no\n");
                continue;
            }
            else
            {
                printf("yes\n");
                continue;
            }
        }
        else
        {
            printf("yes\n");
            continue;
        }

        kase++;
    }
}
