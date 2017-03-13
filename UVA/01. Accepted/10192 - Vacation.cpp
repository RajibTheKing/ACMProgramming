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

vector<char> a, b;
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
    int kase=0;
    string s;
    while(getline(cin, s))
    {
        if(s[0]=='#') break;

        a.push_back('7');        //Just for Keep as First element and should not be processed
        b.push_back('8');        //Just for Keep as First element and should not be processed
        memset(board, 0, sizeof(board));

        for(int i=0;i<s.length();i++)
            a.push_back(s[i]);
        getline(cin, s);

        for(int i=0;i<s.length();i++)
            b.push_back(s[i]);

        LCS();

        printf("Case #%d: you can visit at most %d cities.\n",++kase, board[b.size()-1][a.size()-1]);
        a.clear();
        b.clear();
    }

    return 0;
}



