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


typedef struct Node
{
    double x1, x2, y1, y2;
};

map<int, Node> Set;
vector<double> X, Y;

int main()
{
    Node t;
    char c;
    int kount=0;
    double p, q;
    while(scanf("%c", &c)==1)
    {
        if(c=='r')
        {
            scanf("%lf %lf %lf %lf", &t.x1, &t.y1, &t.x2, &t.y2);
            getchar();
            Set[++kount]=t;
        }
        if(c=='*') break;
    }
    while(cin>>p>>q)
    {
        if(p==9999.9&&q==9999.9) break;
        X.push_back(p);
        Y.push_back(q);
    }

    for(int i=0;i<X.size();i++)
    {
        bool flag=false;
        for(int j=1;j<=Set.size();j++)
        {
            if(Set[j].x1<X[i]&&Set[j].x2>X[i]&&Set[j].y1>Y[i]&&Set[j].y2<Y[i])
            {
                flag=true;
                printf("Point %d is contained in figure %d\n", i+1, j);
            }
        }
        if(flag==false)
            printf("Point %d is not contained in any figure\n", i+1);

    }

    return 0;
}

