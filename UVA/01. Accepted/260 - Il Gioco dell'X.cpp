#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<string.h>

using namespace std;

int dx[] = {0, -1, 0, 1, -1, 1};
int dy[] = {1, 0, -1, 0, -1, 1};
int row;

bool BFS(int x, int y, string board[])
{

   int i, m, n;
   queue<int> Q;
   Q.push(x);
   Q.push(y);
   board[x][y]='#';



   while(!Q.empty())
   {


       x = Q.front();  Q.pop();
       y = Q.front();  Q.pop();

       for(i=0;i<6;i++)
       {
           m=x+dx[i];
           n=y+dy[i];

           if(m>=0&&m<row&&n>=0&&n<row&&board[m][n]=='b')
           {
               if(row-1==m) return true;
               Q.push(m);
               Q.push(n);
               board[m][n]='#';

           }
       }
   }
   return false;

}

char input ()
{
   string board[205];
   int i, j;
   bool k;
   for(i=0;i<row;i++)
       cin>>board[i];

    for(j=0;j<row;j++)
    {
        if(board[0][j]=='b')
            k = BFS(0, j, board);
        if(k) return 'B';
    }

   return 'W';
}

int main()
{
   int n, kase=0;
   char ans;
   while(scanf("%d", &n)==1)
   {
       scanf("%c", &ans);

       if(n==0) break;
       row = n;
       ans = input();

       printf("%d %c\n", ++kase, ans);

   }

   return 0;
}
