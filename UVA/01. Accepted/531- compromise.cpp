
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

vector<string> a, b,ans;
int board[150][150];
int flag[150][150];

void Print(int i, int j);
void LCS(void)
{
    flag[0][0]=5;

    for(int i=1;i<b.size();i++)
    {
        for(int j=1;j<a.size();j++)
        {
            if(a[j]==b[i])
            {
                board[i][j]=board[i-1][j-1]+1;
                flag[i][j]=0;
            }
            else if(board[i][j-1]>board[i-1][j])
            {
                board[i][j]=max(board[i-1][j], board[i][j-1]);
                flag[i][j]=1;
            }
            else
            {
                board[i][j]=max(board[i-1][j], board[i][j-1]);
                flag[i][j]=2;
            }
        }

    }
    return;
}
int main()
{
    string s;
    //freopen("a.txt", "r", stdin);
    a.push_back("rajib");
    b.push_back("aporba");
    memset(flag, -1, sizeof(flag));
    memset(board, 0, sizeof(board));


    int r=0;
    while(cin>>s)
    {

        if(s[0]=='#') r++;

        if(r==1)
        {
            while(cin>>s)
            {

                if(s[0]=='#') r++;

                if(r==2)
                {
                    r=0;
                    LCS();
                    Print(b.size()-1, a.size()-1);
                    for(int i=0;i<ans.size();i++)
                    {
                        if(i!=0) cout<<" ";
                        cout<<ans[i];
                    }
                    cout<<endl;
                    a.clear();
                    b.clear();
                    ans.clear();
                    memset(flag, -1, sizeof(flag));
                    memset(board, 0, sizeof(board));
                    s="rajib";
                    b.push_back("aporba");
                    break;
                }
                b.push_back(s);
            }
        }
        a.push_back(s);
    }
    return 0;
}

void Print(int i , int j)
{
	if(i==0||j==0)
		return;
	if(flag[i][j]==0)
	{
		Print(i-1,j-1);
		//strcpy(store[z++].c ,str1[i-1].c);
		ans.push_back(b[i]);
	}
	else if(flag[i][j]==1)
        Print(i , j-1);

	else
        Print(i-1 ,j);

}

