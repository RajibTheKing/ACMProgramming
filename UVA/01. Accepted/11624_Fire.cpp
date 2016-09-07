#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
#define SZ 1000+5

int fireWeight[SZ][SZ];
int moveWeight[SZ][SZ];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int Row, Col;
string board[SZ];
int color[SZ][SZ];

bool isValid(int x, int y)
{
    if(x<0||x>=Row)
        return false;
    if(y<0||y>=Col)
        return false;
    if(board[x][y]=='#') return false;
    return true;

}
void FireBFS(int x, int y)
{
    memset(color, 0, sizeof(color));
    queue<int> Q;
    while(!Q.empty()) Q.pop();

    Q.push(x);
    Q.push(y);

    fireWeight[x][y]=0;
    color[x][y]=1;

    while(!Q.empty())
    {
        int nowX = Q.front(); Q.pop();
        int nowY = Q.front(); Q.pop();
        int weight = fireWeight[nowX][nowY];
        //cout<<nowX<<", "<<nowY<<endl;
        for(int i=0;i<4;i++)
        {
            int a, b;
            a=nowX+dx[i];
            b=nowY+dy[i];
            if(isValid(a,b) && color[a][b]==0 && (weight+1)<fireWeight[a][b])
            {
                fireWeight[a][b] = min(fireWeight[a][b], weight+1);

                Q.push(a);
                Q.push(b);
                color[a][b]=1;
            }
        }


    }

}
int MoveBFS(int x, int y)
{

    memset(color, 0, sizeof(color));
    for(int i=0;i<Row;i++) for(int j=0;j<Col;j++) moveWeight[i][j]=(SZ)*3;

    queue<int> Q;
    while(!Q.empty()) Q.pop();

    Q.push(x);
    Q.push(y);

    moveWeight[x][y] = 0;
    color[x][y]=1;
    int ans = (SZ)*3;

    if(x==0||x==(Row-1))
    {
        ans=min(ans,moveWeight[x][y]);
    }
    if(y==0||y==(Col-1))
    {
        ans=min(ans,moveWeight[x][y]);
    }

    while(!Q.empty())
    {
        int nowX = Q.front(); Q.pop();
        int nowY = Q.front(); Q.pop();
        int weight = moveWeight[nowX][nowY];
        //cout<<nowX<<",, "<<nowY<<endl;
        for(int i=0;i<4;i++)
        {
            int a, b;
            a=nowX+dx[i];
            b=nowY+dy[i];

            if(isValid(a,b) && color[a][b]==0 && (weight+1)<fireWeight[a][b])
            {
                moveWeight[a][b] = min(moveWeight[a][b], weight+1);

                Q.push(a);
                Q.push(b);
                if(a==0||a==(Row-1))
                {
                    ans=min(ans,moveWeight[a][b]);
                }
                if(b==0||b==(Col-1))
                {
                    ans=min(ans,moveWeight[a][b]);
                }
                color[a][b]=1;
            }
        }


    }
    return ans;

}
int main()
{
    freopen("/Users/RajibTheKing/Desktop/input.txt", "r+", stdin);
    int TestCase;
    cin>>TestCase;
    while(TestCase--)
    {
        cin>>Row>>Col;
        for(int i=0;i<Row;i++)
        {
            cin>>board[i];
        }
        for(int i=0;i<Row;i++) for(int j=0;j<Col;j++) fireWeight[i][j] = (SZ)*3;

        int mx, my;

        for(int i=0;i<Row;i++)
        {
            for(int j=0;j<Col;j++)
            {
                if(board[i][j]=='F')
                {
                    FireBFS(i,j);
                }
                if(board[i][j]=='J')
                {
                    mx=i;
                    my=j;
                }
            }
        }

        int ans = MoveBFS(mx,my);

        if(ans==(SZ)*3)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<ans+1<<endl;


    }
    return 0;
}
/*
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/
