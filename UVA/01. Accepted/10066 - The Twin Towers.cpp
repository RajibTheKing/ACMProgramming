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

vector<int> a, b,ans;
int board[150][150];
void LCS(void)
{


    for(int i=1;i<b.size();i++)
        for(int j=1;j<a.size();j++)
            if(a[j]==b[i])
                board[i][j]=board[i-1][j-1]+1;
            else
                board[i][j]=max(board[i-1][j], board[i][j-1]);

    return;
}

int main()
{
    int N1, N2, temp, kase=0;
    while(cin>>N1)
    {
        a.push_back(99);        //Just for Keep as First element and should not be processed
        b.push_back(77);        //Just for Keep as First element and should not be processed
        memset(board, 0, sizeof(board));
        cin>>N2;
        if(N2==0&&N1==0) break;

        for(int i=0;i<N1;i++)
        {
            cin>>temp;
            a.push_back(temp);

        }
        for(int j=0;j<N2;j++)
        {
            cin>>temp;
            b.push_back(temp);
        }
        LCS();
        printf("Twin Towers #%d\n", ++kase);
        printf("Number of Tiles : %d\n\n", board[b.size()-1][a.size()-1]);
        a.clear();
        b.clear();
    }

    return 0;
}



