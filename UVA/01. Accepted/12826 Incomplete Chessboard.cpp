#include <stdio.h>
#include<sstream>
#include<string>
#include<iostream>
#include <queue>
#include<string.h>
using namespace std;


int r1, c1, r2, c2, r3, c3;
bool check(int x, int y){
    if(x>8 || y>8 || x<1 || y<1) return false;
    if(x==r3 && y==c3 ) return false;
    return true;
}

int main()
{
    bool arr[10][10];
    int dist[10][10];
    int dx[]={1,1,0,-1,-1,-1,0,1};
    int dy[]={0,1,1,1,0,-1,-1,-1};

    queue<int>Q;
    int k=0;
    while(cin>>r1>>c1>>r2>>c2>>r3>>c3)
    {
        memset(arr, 0, sizeof(arr));
        memset(dist, 127, sizeof(dist));

        //cout<<dist[0][0]<<" "<<dist[0][1]<<endl;

        while(!Q.empty()){
            Q.pop();
        }
        Q.push(r1);
        Q.push(c1);
        arr[r1][c1] =1;
        dist[r1][c1] =0;
        while(!Q.empty()){
            int x, y, tx, ty;
            x = Q.front(); Q.pop();
            y = Q.front(); Q.pop();

            for(int i=0; i<8; i++){
                tx = x + dx[i];
                ty = y + dy[i];
                if(check(tx, ty) && arr[tx][ty]==0)
                {
                    dist[tx][ty] = min(dist[tx][ty], 1+ dist[x][y]);
                    Q.push(tx);Q.push(ty);
                    arr[tx][ty]=1;
                }
            }
        }
        cout<<"Case "<<(++k)<<": "<<dist[r2][c2]<<endl;



    }
    return 0;
}
