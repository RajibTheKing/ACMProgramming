#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
string board[50];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int kount, row, column;


void BFS(int x, int y)
{

    int i, m, n;
    queue<int> Q;
    Q.push(x);
    Q.push(y);

    board[x][y]='#';
    kount=0;

    while(!Q.empty())
    {

        x = Q.front();  Q.pop();
        y = Q.front();  Q.pop();

        for(i=0;i<4;i++)
        {
            m=x+dx[i];
            n=y+dy[i];

            if(m>=0&&m<row&&n>=0&&n<column&&board[m][n]=='.')
            {
                kount++;
                Q.push(m);
                Q.push(n);
                board[m][n] = '#';
            }
        }
    }
}

void input ()
{
    int i, j, x, y;
    for(i=0;i<row;i++)
        cin>>board[i];

    for(i=0;i<row;i++)
        for(j=0;j<column;j++)
            if(board[i][j]=='@')
            {
                x=i;y=j;
            }

    BFS(x, y);
}

int main()
{
    int n, kase=0;
    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &column);
        scanf("%d", &row);
        input();

        printf("Case %d: %d\n", ++kase, ++kount);

    }
    return 0;
}
