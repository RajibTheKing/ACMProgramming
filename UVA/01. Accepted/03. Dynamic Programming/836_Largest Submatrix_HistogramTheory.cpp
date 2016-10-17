#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<string>
#include<algorithm>
#include<regex>

#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

string  board[27];
int n;


int getMaxArea(int hist[], int n)
{
    stack<int> s;

    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar

    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top

            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}



int color[27][27];

int main()
{
    //freopen("/Users/RajibTheKing/Desktop/OnTry/input.txt", "r+", stdin);
    cin>>n;
    string s;
    int kase = 0;
    while(n--)
    {
        cin>>board[0];
        for(int i=1;i<board[0].size();i++)
        {
            cin>>board[i];
        }

        int Len = board[0].size();

        int mx = 0;

        memset(color, 0, sizeof(color));

        for(int j=0;j<Len;j++)
        {
            if(board[Len-1][j]=='1')
            {
                color[Len-1][j]=1;
            }
            for(int i=Len-2;i>=0;i--)
            {
                if(board[i][j]=='1')
                {
                    color[i][j]=max(color[i+1][j]+1,1);
                }
            }
        }

        /*for(int i=0;i<Len;i++)
        {
            for(int j=0;j<Len;j++)
            {
                cout<<color[i][j]<<" ";

            }
            cout<<endl;

        }*/

        for(int i=0;i<Len;i++)
        {
            mx = max(mx, getMaxArea(color[i], Len));
        }

        if(kase)
            cout<<endl;

        cout<<mx<<endl;

        kase++;

    }
    return 0;
}
