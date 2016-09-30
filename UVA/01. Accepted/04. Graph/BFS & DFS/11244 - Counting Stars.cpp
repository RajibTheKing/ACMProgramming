#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;


int r, c;
int dx [] = {-1, 0, 1,  0, -1, 1,  1, -1};
int dy [] = { 0, 1, 0, -1,  1, 1, -1, -1};

vector<string> board;

bool isValid(int p, int q)
{
    if(p<0||p>=r||q<0||q>=c) return false;
    return true;

}


bool check(int p, int q)
{
    for(int i=0;i<8;i++)
    {
        int x, y;
        x=p+dx[i];
        y=q+dy[i];
        if(isValid(x,y))
        if(board[x][y]=='*') return false;
    }
    return true;
}
int main()
{

    while(cin>>r>>c)
    {

        string s;
        board.clear();
        if(r==0&&c==0) break;
        for(int i=0;i<r;i++)
        {

            cin>>s;
            board.push_back(s);

        }
        int kount=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='*')
                {
                    if(check(i,j)) kount++;
                }
            }
        }
        cout<<kount<<endl;

    }




    return 0;
}

