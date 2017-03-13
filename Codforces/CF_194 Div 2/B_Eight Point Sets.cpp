#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define bug puts("here");
#define N 100100

using namespace std;

struct point
{
    int x,y;
};

int cmp(point a,point b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    point m[10];
    int i;
    for(i=0;i<8;i++)
        cin >> m[i].x >> m[i].y;
    sort(m,m+8,cmp);
    bool flag = true;
    if(!(m[0].x == m[1].x && m[1].x == m[2].x))
        flag =false;
    if(!(m[4].x == m[3].x))
        flag =false;
    if(!(m[7].x == m[5].x && m[5].x == m[6].x))
        flag = false;
    if(!(m[0].y == m[5].y && m[1].y == m[6].y && m[2].y == m[7].y))
        flag =false;
    if(!(m[0].y == m[3].y && m[2].y == m[4].y))
        flag =false;
    if(m[2].x == m[3].x)
        flag =false;
    if(m[4].x == m[5].x)
        flag =false;
    if(m[0].y == m[1].y || m[1].y == m[2].y)
        flag =false;

    if(flag) cout << "respectable" << endl;
    else cout << "ugly" << endl;
    return 0;
}
