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

#define SZ 8
#define ROW SZ
#define COL SZ


int Dx[]= {-2,-1, 1, 2, 2,1,-1,-2};
int Dy[]= {-1,-2,-2,-1, 1,2, 2, 1};
int color[ROW][COL];
int sourceI, sourceJ, desI, desJ;

bool isValid(int x, int y)
{
    if(x<0 || x>=ROW) return false;
    if(y<0 || y>=COL) return false;
    return true;
}
bool isDest(int x, int y)
{
    if(x==desI&&y==desJ) return true;
    return false;
}
int BFS(int x, int y)
{
    queue<int> Q;
    Q.push(x);
    Q.push(y);
    Q.push(0);

    int mn = 8*8;

    if(isDest(x,y))
    {
       mn = min(mn, 0);

       return mn;
    }
    else
    {
        color[x][y]=1;
    }

    int depth;

    while(!Q.empty())
    {
        x=Q.front(); Q.pop();
        y=Q.front(); Q.pop();
        depth=Q.front();Q.pop();

        //cout<<"Now: "<<x<<", "<<y<<", "<<depth<<endl;

        for(int i=0;i<SZ;i++)
        {
            int tx = x+Dx[i];
            int ty = y+Dy[i];

            if(isValid(tx,ty) && color[tx][ty]==0)
            {
                if(isDest(tx,ty))
                {
                    cout<<"GottttttMy Destttttttttt "<<tx<<", "<<ty<<", depth = "<<depth + 1<<endl;
                    mn = min(mn, depth+1);
                }
                else
                {
                    Q.push(tx);
                    Q.push(ty);
                    Q.push(depth+1);
                    color[tx][ty]=1;
                }
            }
        }
    }

    return mn;

}



int main()
{
    string s1, s2;

    while(cin>>s1>>s2)
    {
        sourceI = s1[0]-'a';
        sourceJ = s1[1]-'0'-1;

        desI = s2[0]-'a';
        desJ = s2[1]-'0'-1;

        memset(color, 0, sizeof(color));
        cout<<sourceI<<", "<<sourceJ<<" ---> "<<desI<<", "<<desJ<<endl;

        int ans = BFS(sourceI, sourceJ);

        cout<<"Answer is: "<<ans<<endl;



    }
    return 0;
}
