#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

using namespace std;
string board[50];
string food = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int flag[50][50];
int row, n, m;


int BFS(int x, int y, char item)
{
    int i;
    queue<int> Q;
    Q.push(x);
    Q.push(y);

    flag[x][y]=0;
    while(!Q.empty())
    {
        x = Q.front();  Q.pop();
        y = Q.front();  Q.pop();

        for(i=0;i<4;i++)
        {
            m=x+dx[i];
            n=y+dy[i];
            if(m>=0&&m<row&&n>=0&&n<row&&board[m][n] && board[m][n]!='#'&&flag[m][n]==-1)
            {
                if(board[m][n]==item)
                {
                    flag[m][n]=flag[x][y]+1;
                    return flag[m][n];
                }

                if(board[m][n]=='.')
                {

                    flag[m][n]=flag[x][y]+1;
                    Q.push(m);
                    Q.push(n);
                }

            }
        }
    }
    return -1;
}

int input ()
{
    int i, j, x, y, result = 0, temp, num;
    for(i=0;i<row;i++)
        cin>>board[i];

    num = 0;

    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++)
        {
            if(board[i][j]=='A')
            {
                x=i;y=j;

            }

            if(board[i][j]>='A'&&board[i][j]<='Z')
                num++;
        }
    }

    board[x][y]='.';
    for(j=1;j<num;j++)
    {
        memset(flag, -1, sizeof(flag));
        temp = BFS(x, y, food[j]);

        if(temp==-1)
            return -1;
        else
        {
            board[m][n]='.';

            result = result + temp;
            x=m;
            y=n;
        }
    }

    return result;
}

int main()
{
    int n, kase=0, ans;
    scanf("%d", &n);

    while(n--)
    {

        scanf("%d", &row);
        ans = input();

        if(ans!=-1)
            printf("Case %d: %d\n", ++kase, ans);
        else
            printf("Case %d: Impossible\n", ++kase);


    }

    return 0;
}

