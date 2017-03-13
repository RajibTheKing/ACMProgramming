#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>
#define INF 999
using namespace std;

typedef struct Node
{
    char name;
    int kount;
};

Node Set[2500];


int dx [] = {-1, 0, 1,  0};
int dy [] = { 0, 1, 0, -1};
int kount, row, column;
string board[100];




int BFS(int x, int y, char c)
{

    int i, m, n;
    queue<int> Q;
    Q.push(x);
    Q.push(y);
    int cnt=1;
    board[x][y]='.';
    while(!Q.empty())
    {

        x = Q.front();  Q.pop();
        y = Q.front();  Q.pop();

        for(i=0;i<4;i++)
        {
            m=x+dx[i];
            n=y+dy[i];

            if(m>=0&&m<row&&n>=0&&n<column&&board[m][n]==c)
            {
                cnt++;

                board[m][n]='.';
                Q.push(m);
                Q.push(n);

            }
        }
    }
    return cnt;
}


bool comp(Node p, Node q)
{
    if(p.kount==q.kount) return p.name<q.name;
    return p.kount>q.kount;
}
int main()
{
    int kase=0;
    while(scanf("%d %d", &row, &column)==2)
    {
        getchar();
        if(row==0||column==0) break;


        for(int i=0;i<row;i++)
            cin>>board[i];

        int k=-1;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(board[i][j]!='.')
                {
                    Set[++k].name=board[i][j];
                    Set[k].kount=BFS(i, j, board[i][j]);
                }
            }
        }
        k++;

        sort(&Set[0], &Set[k], comp);
        printf("Problem %d:\n", ++kase);
        for(int i=0;i<k;i++)
            cout<<Set[i].name<<" "<<Set[i].kount<<endl;

    }
    return 0;
}
