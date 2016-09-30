#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#define INF 99999999
using namespace std;

int R, C;
struct Node
{
    char name;
    char parent;
    int number;

};

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int A[505][505];
Node matrix[505][505];
string board[505];
bool flag[505][505];

queue<int> Q;

void BFS()
{

    int x, y;
    memset(flag, false, sizeof(flag));
    while(!Q.empty())
    {
        x=Q.front();Q.pop();
        y=Q.front();Q.pop();

        for(int i=0;i<4;i++)
        {
            int m, n;

            m=x+dx[i];
            n=y+dy[i];
            //cout<<A[m][n]<<endl;


            if(m>=0&&m<R&&n>=0&&n<C&&board[m][n]!='#'&&A[m][n]>=A[x][y]+1&&flag[x][y]!=true)
            {
               // cout<<"For: "<<matrix[x][y].name<<endl;

                if(A[m][n]==A[x][y]+1&&matrix[m][n].name!=matrix[x][y].name)
                {

                    matrix[m][n].number=2;
                    flag[m][n]=true;
                }
                else if(A[m][n]>A[x][y]+1)
                {

                    A[m][n]=A[x][y]+1;
                    matrix[m][n].number=1;
                    //matrix[m][n].parent=c;
                    matrix[m][n].name=matrix[x][y].name;
                    //cout<<m<<", "<<n<<endl;
                    Q.push(m);
                    Q.push(n);
                }


            }
        }
    }

}
int main()
{
   // freopen("input.txt", "r", stdin);

    int t;
    cin>>t;

    while(t--)
    {
        cin>>R>>C;
        for(int i=0;i<R;i++)
            cin>>board[i];

        memset(flag, false, sizeof(flag));
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            {
                A[i][j]=INF;
                matrix[i][j].number=0;
            }

        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {


                if(board[i][j]>='a'&&board[i][j]<='z')
                {

                    Q.push(i);
                    Q.push(j);
                    flag[i][j]=true;
                    A[i][j]=0;
                    matrix[i][j].number=0;
                    matrix[i][j].name=board[i][j];
                }
            }
        }
        BFS();

        /*for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                cout<<matrix[i][j].number<<" ";
            }
            cout<<endl;

        }
        cout<<endl;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;

        }*/

        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(matrix[i][j].number==0)
                    printf("%c", board[i][j]);
                else if(matrix[i][j].number==1)
                    printf("%c", matrix[i][j].name);
                else
                    printf("*");
            }
            printf("\n");
        }
        cout<<endl;



    }
}
