#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<queue>
#include<string.h>

using namespace std;

char board[505][505];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int ans[505][505];
int kount,kase = 0;

int BFS(int x, int y, int row, int column)
{
    if(ans[x][y]!=-1) return ans[x][y];
    int flag[505][505];

    memset(flag, -1, sizeof(flag));
    kount = 0;
    int t1, t2;
    t1 = x;
    t2 = y;
    int i, m, n;
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    if(board[x][y]=='C') kount++;

    flag[x][y]=0;

    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        y = Q.front(); Q.pop();
        for(i=0;i<4;i++)
        {
            m = x + dx[i];
            n = y + dy[i];
            if(m>=0&&m<row&&n>=0&&n<column&&flag[m][n]==-1&&(board[m][n]=='C'||board[m][n]=='.'))
            {
                if(board[m][n]=='C')
                    kount++;

                flag[m][n]=0;
                Q.push(m);
                Q.push(n);
            }
        }
    }



    memset(flag, -1, sizeof(flag));
    x = t1;
    y = t2;

    queue<int>R;
    R.push(x);
    R.push(y);
    flag[x][y]=0;
    ans[x][y]=kount;

    while(!R.empty())
    {
        x = R.front(); R.pop();
        y = R.front(); R.pop();
        for(i=0;i<4;i++)
        {
            m = x + dx[i];
            n = y + dy[i];
            if(m>=0&&m<row&&n>=0&&n<column&&flag[m][n]==-1&&(board[m][n]=='C'||board[m][n]=='.'))
            {

                ans[m][n]=kount;
                flag[m][n]=0;
                R.push(m);
                R.push(n);
            }
        }
    }


    return kount;
}
void input()
{
    memset(ans, -1, sizeof(ans));
    int m, n, q;
    scanf("%d%d%d", &m, &n, &q);

    int i, j, k, l;
    int a[1005], b[1005];

    for(i=0;i<m;i++)
        scanf("%s", board[i]);

    for(i=0;i<q;i++)
        scanf("%d%d", &a[i], &b[i]);

    printf("Case %d:\n", ++kase);

    for(i=0;i<q;i++)
    {

        printf("%d\n", BFS(a[i]-1, b[i]-1, m, n));
    }
    return;
}

main()
{
    int n;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        input();
    }

}
