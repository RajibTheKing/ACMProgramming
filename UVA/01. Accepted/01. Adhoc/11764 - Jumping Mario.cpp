
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;


vector<int> Wall;
int LowJump, HighJump;

void rec(int ptr, int cur)
{
    if(cur>=Wall.size())
        return;
    else
    {
        if(Wall[ptr]<Wall[cur]) HighJump++;
        if(Wall[ptr]>Wall[cur]) LowJump++;
        rec(ptr+1, cur+1);
    }

    return;
}
int main()
{
    int Test, kase=0, N, temp;
    scanf("%d", &Test);
    getchar();

    while(Test--)
    {
        cin>>N;
        Wall.clear();
        for(int i=0;i<N;i++)
        {
            cin>>temp;
            Wall.push_back(temp);
        }
        LowJump=0; HighJump=0;
        rec(0,1);
        printf("Case %d: %d %d\n", ++kase, HighJump, LowJump);

    }

    return 0;
}
