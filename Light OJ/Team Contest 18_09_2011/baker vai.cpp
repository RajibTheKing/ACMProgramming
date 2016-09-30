#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int board[101][101], n, m;
bool flag[101][101];
int t;
void function1(int i, int j)
{
    while(1)
    {
        cout<<i<<" "<<j<<" "<<endl;
        if(i>=n-1&&j>=m-1)
            break;

        if(i+1<n&&j+1<m&&board[i+1][j]>=board[i][j+1]&&flag[i+1][j]==0&&i+1<n)
        {
            flag[i+1][j]=1;
            t+=board[i+1][j];
            i++;
        }
        else if(i+1<n&&j+1<m&&board[i][j+1]>=board[i+1][j]&&flag[i][j+1]&&j+1<m)
        {
            flag[i][j+1]=1;
            t+=board[i][j+1];
            j++;
        }



        cout<<t<<endl;
    }
}

main()
{
    int test, i, j;
    cin>>test;

    while(test--)
    {
        cin>>n>>m;
        t = 0;

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>board[i][j];



        function1(0,0);

        cout<<t<<endl;

    }


}


