#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<ctype.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<map>
#include<sstream>
#include<cmath>
#include<bitset>
#include<utility>
#include<set>
#include<numeric>

using namespace std;
#define INF 99999
int row, column;
string matrix[1005], board[1005];
int jane[1005][1005], fire[1005][1005];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void print_this();
int find_ans();

void BFS_Jane(int x, int y)
{

    int i, m, n;
    queue<int> Q;
    Q.push(x);
    Q.push(y);
    jane[x][y]=0;

    board[x][y]='#';
   // kount=0;

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
                //kount++;
                jane[m][n]=min(jane[m][n], jane[x][y]+1);

                Q.push(m);
                Q.push(n);
                board[m][n] = '#';
            }
        }
    }
}

void BFS_Fire(int x, int y)
{
    int i, m, n, temp;
    queue<int> Q;
    Q.push(x);
    Q.push(y);
    fire[x][y]=0;
    while(!Q.empty())
    {

        x = Q.front();  Q.pop();
        y = Q.front();  Q.pop();

        for(i=0;i<4;i++)
        {
            m=x+dx[i];
            n=y+dy[i];
            temp=fire[x][y]+1;

            if(m>=0&&m<row&&n>=0&&n<column&&fire[m][n]>temp)
            {

                fire[m][n]=temp;
                Q.push(m);
                Q.push(n);
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int T, kase=0;
    cin>>T;
    while(T--)
    {
        cin>>row>>column;
        for(int i=0;i<row;i++)
        {
            cin>>matrix[i];
            board[i]=matrix[i];
        }
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
                jane[i][j]=fire[i][j]=INF;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(matrix[i][j]=='J')
                {
                    BFS_Jane(i, j);
                    goto next;
                }
            }
        }
    next:
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
                if(matrix[i][j]=='F')
                    BFS_Fire(i, j);



        int result = find_ans();

        if(result==-1)
            printf("Case %d: IMPOSSIBLE\n", ++kase);
        else
            printf("Case %d: %d\n", ++kase, result);

        print_this();


    }
    return 0;
}
int find_ans()
{
    bool flag=false;
    int M=9999999;

    for(int i=0;i<row;i++)
    {
        if(fire[i][0]>jane[i][0])
        {
            flag=true;
            M=min(M, jane[i][0]+1);
        }
    }
    for(int i=0;i<row;i++)
    {
        if(fire[i][column-1]>jane[i][column-1])
        {
            flag=true;
            M=min(M, jane[i][column-1]+1);
        }
    }
    for(int i=0;i<column;i++)
    {
        if(fire[0][i]>jane[0][i])
        {
            flag=true;
            M=min(M, jane[0][i]+1);
        }
    }

    for(int i=0;i<column;i++)
    {
        if(fire[row-1][i]>jane[row-1][i])
        {
            flag=true;
            M=min(M, jane[row-1][i]+1);
        }
    }
    if(flag==false)
        return -1;
    else
        return M;


}
void print_this(void)
{
    cout<<"For jane: "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            printf("%6d", jane[i][j]);
        cout<<endl;
    }
    cout<<"Fore fire: "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            printf("%6d", fire[i][j]);
        cout<<endl;
    }

}
