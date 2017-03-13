#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>

#include<string.h>
#include<stdio.h>

using namespace std;

#define SZ 60

int dx[] = {1,0,-1,0 };
int dy[] = {0,1,0,-1 };


int row,col, k;

string board[SZ];


bool isBorder(int x, int y)
{
    if(x<0||x>=row) return true;
    if(y<0||y>=col) return true;

    return false;
}

bool isValid(int x, int y)
{
    if(isBorder(x,y)) return false;

    if(board[x][y]=='*') return false;

    return true;
}

int BFS(int x, int y)
{
    queue<int> Q;
    while(!Q.empty())
    {
        Q.pop();
    }
    int knt = 0;

    Q.push(x);
    Q.push(y);
    board[x][y]='*';
    knt++;
    int a, b;
    bool flag = true;

    while(!Q.empty())
    {
        a = Q.front(); Q.pop();
        b = Q.front(); Q.pop();
        for(int i=0;i<4;i++)
        {
            int tx = a+dx[i];
            int ty = b+dy[i];

            if(isBorder(tx,ty))
            {
                flag = false;
            }

            if(isValid(tx,ty))
            {
                Q.push(tx);
                Q.push(ty);
                knt++;
                board[tx][ty]='*';
            }


        }
    }

    if(flag)
    {
        return knt;
    }


    return 0;


}
typedef struct Node
{
    int totalKnt;
    int arrx;
    int arry;
};

//bool cmp(Node a, Node b)
//{
//    return a.totalKnt<b.totalKnt;
//
//}

bool cmp(Node a, Node b)
{
    if(a.totalKnt!=b.totalKnt) return a.totalKnt<b.totalKnt;
    if(a.arrx!=b.arrx) return a.arrx<b.arrx;
    return a.arry<b.arry;

}


    Node arr[SZ*SZ];

    string tempBoard[SZ];

int main()
{

    string ss;



    while(cin>>row>>col>>k)
    {

        for(int i=0;i<row;i++)
        {
            cin>>board[i];
            tempBoard[i] = board[i];
        }

//        memset(arr, 0, sizeof(arr));

        int knt;
        int indx = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='.')
                {
                    knt = BFS(i,j);
                    if(knt!=0)
                    {
                        arr[indx].totalKnt = knt;
                        arr[indx].arrx = i;
                        arr[indx].arry = j;
                        indx++;

                    }

                }
            }
        }

        sort(arr, arr+indx, cmp);

        for(int i=0;i<row;i++)
        {
            board[i]=tempBoard[i];
        }



        int ans = indx-k;

        int realAns = 0;
        for(int i=0;i<ans;i++)
        {
            realAns+=arr[i].totalKnt;
            BFS(arr[i].arrx, arr[i].arry);
        }

        cout<<realAns<<endl;

        for(int i=0;i<row;i++)
        {
            cout<<board[i]<<endl;
        }


    }

    return 0;

}
