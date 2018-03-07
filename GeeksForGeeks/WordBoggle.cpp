#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

char boggle[8][8];
bool visited[8][8];
int n, m;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int x, int y)
{
    if(x<0 || y<0) return false;
    if(x>=n || y>=m) return false;

    return true;
}
bool BFS(int x, int y, string word)
{
    cout<<"Calculating: "<<word<<endl;
    int color[8][8];
    memset(color, 0, sizeof(color));
    int depth = 0;
    queue<int> Q;
    Q.push(x);
    Q.push(y);
    Q.push(depth); //depth
    color[x][y] = 1;
    if(depth == word.size()-1) return true;

    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        y = Q.front(); Q.pop();
        depth = Q.front(); Q.pop();

        cout<<"GotFromQueue: x,y,depth = "<<x<<", "<<y<<", "<<depth<<endl;
        for(int i=0; i<8; i++)
        {
            int tempX = x + dx[i];
            int tempY = y + dy[i];

            if(isValid(tempX, tempY) && color[tempX][tempY] == 0 && word[depth+1] == boggle[tempX][tempY])
            {
                if(depth+1 == word.size() -1) return true;

                cout<<"pusing: "<<boggle[tempX][tempY]<<", depth+1 = "<<(depth+1)<<endl;

                Q.push(tempX);
                Q.push(tempY);
                Q.push(depth+1);
                color[tempX][tempY] = 1;
            }
        }

    }

    return false;
}

bool dfs(int i, int j, int depth, string &word)
{
    if(depth == word.size() - 1) return true;

    for(int k=0; k<8; k++)
    {
        int tempX = i + dx[k];
        int tempY = j + dy[k];

        if(isValid(tempX, tempY) && visited[tempX][tempY] == 0 && word[depth+1] == boggle[tempX][tempY])
        {
            visited[tempX][tempY] = true;

            if(dfs(tempX, tempY, depth+1, word))
            {
                return true;
            }
            visited[tempX][tempY] = false;
        }
    }
    return false;

}

int main()
{
    int T, x;
    cin>>T;
    string words[11];
    string tm;
    map<string, bool> done;

    while(T--)
    {
        done.clear();

        cin>>x;
        for(int i=0; i<x;i++) cin>>words[i];

        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>tm;
                boggle[i][j] = tm[0];
            }
        }

        sort(&words[0], &words[x]);

        bool isFound = false;
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<n; j++)
            {

                for(int k=0; k<m; k++)
                {
                    if(words[i][0] == boggle[j][k] && done[words[i]] == false)
                    {
                        //cout<<"Trying for "<<words[i]<<", j,k = "<<j<<", "<<k<<endl;
                        memset(visited, 0, sizeof(visited));

                        //if(BFS(j, k, words[i]))
                        visited[j][k] = true;
                        if(dfs(j, k, 0, words[i]))
                        {
                            if(isFound == true) cout<<" ";
                            cout<<words[i];
                            isFound = true;
                            done[words[i]] = true;
                        }
                    }
                }
            }

        }
        if(isFound == false)
        {
            cout<<"-1";
        }

        cout<<endl;


    }

    return 0;
}

//f d b c e
//f d c c f


