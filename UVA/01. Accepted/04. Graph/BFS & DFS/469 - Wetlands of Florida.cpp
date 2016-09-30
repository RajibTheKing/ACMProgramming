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
using namespace std;

int dx [] = {-1, 0, 1,  0, -1, 1,  1, -1};
int dy [] = { 0, 1, 0, -1,  1, 1, -1, -1};

char board[1000][1000];
int color[200][200];
vector<int> X, Y;
int kount, row, column;

void DFS_Visit(int m, int n)
{

    if(m<0||n<0||m>=row||n>=column||color[m][n]==1||board[m][n]=='L')
        return;

    kount++;
    color[m][n]=1;

    for(int i=0;i<8;i++)
    {

        DFS_Visit(m+dx[i], n + dy[i]);
    }

}
int main()
{
    //freopen("test.txt", "r", stdin);

    bool flag=false;
    char temp[1000];
    int Test, r, c;
    scanf("%d", &Test);
    getchar();
    getchar();

    while(Test--)
    {
        memset(color, 0, sizeof(color));
        int k=-1; X.clear();Y.clear();

        if(flag) printf("\n"); flag=true;
        while(gets(temp))
        {
            if(strlen(temp)==0) break;

            if(temp[0]=='L'||temp[0]=='W')
            {
                strcpy(board[++k], temp);
            }
            else
            {
                istringstream iss(temp);
                iss>>r;
                iss>>c;
                X.push_back(r);
                Y.push_back(c);
            }

        }
        row=k+1;
        column=strlen(board[0]);
        for(int i=0;i<X.size();i++)
        {
            kount=0;
            memset(color, 0, sizeof(color));

            DFS_Visit(X[i]-1, Y[i]-1);
            printf("%d\n", kount);
        }

    }

    return 0;
}
