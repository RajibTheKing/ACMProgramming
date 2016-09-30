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


int dx[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int dy[] = {-2, -1,  1,  2, 2, 1, -1, -2};
int kount, row=8, column=8;
map<char, int> Set;

int Time[10][10];



void BFS(int x, int y)
{

    int i, m, n;
    queue<int> Q;
    Q.push(x);
    Q.push(y);


    Time[x][y]=0;


    while(!Q.empty())
    {

        x = Q.front();  Q.pop();
        y = Q.front();  Q.pop();

        for(i=0;i<8;i++)
        {
            m=x+dx[i];
            n=y+dy[i];

            if(m>0&&m<=row&&n>0&&n<=column&& (Time[x][y]+1) < Time[m][n])
            {

                Time[m][n]=Time[x][y]+1;
                Q.push(m);
                Q.push(n);

            }
        }
    }
}



int main()
{
    for(char c='a'; c<='h';c++)
        Set[c] = c-'a' + 1;

    int x1, y1, x2, y2, kase=0;
    char c1, c2;


    while(scanf("%c%d %c%d", &c1, &y1, &c2, &y2)==4)
    {
        getchar();
        x1 = Set[c1];
        x2 = Set[c2];
        for(int i=0;i<=8;i++)
            for(int j=0;j<=8;j++)
                Time[i][j]=INF;
        BFS(x1, y1);
        printf("To get from %c%d to %c%d takes %d knight moves.\n", c1, y1, c2, y2, Time[x2][y2]);

    }
    return 0;
}
