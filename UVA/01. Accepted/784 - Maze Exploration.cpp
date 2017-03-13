#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<queue>
using namespace std;

char  board[100][100];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int row;

void print_answer(void)
{
    for(int i=0;i<=row;i++)
    {
        for(int j = 0;j<strlen(board[i]);j++)
            printf("%c", board[i][j]);
        cout<<endl;
    }


}
void BFS(int x, int y)
{
    int i, m, n;
    queue<int>Q;
    Q.push(x);
    Q.push(y);
    board[x][y]='#';
    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        y = Q.front(); Q.pop();

        for(i=0;i<4;i++)
        {
            m = x+dx[i];
            n = y+dy[i];
            if(m>=0&&m<=row&&n>=0&&board[m][n]==' ')
            {

                Q.push(m);
                Q.push(n);
                board[m][n] = '#';
            }
        }
    }

}
void input()
{
    int i, j, x, y;
    char t;
    for(i=0; ;i++)
    {
       gets(board[i]);

       if(board[i][0]=='_') break;
    }

    row = i;

    for(i=0;i<=row;i++)
        for(j=0;j<strlen(board[i]);j++)
            if(board[i][j]=='*')
            {
                x=i;y=j;
                break;
            }



    BFS(x, y);
}
int main()
{
    int n;
    char c;

    scanf("%d", &n);
    scanf("%c", &c);
    while(n--)
    {
        input();

        print_answer();
    }
}
