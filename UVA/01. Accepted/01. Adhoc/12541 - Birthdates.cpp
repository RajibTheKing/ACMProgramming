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

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

typedef struct Node
{
    string name;
    int d, m, y;
};

bool cmp(Node a, Node b)
{
    if(a.y==b.y)
        if(a.m==b.m)
            return a.d<b.d;
    if(a.y==b.y)
        return a.m<b.m;
    return a.y<b.y;
}

int main()
{

    int n, dd, yy, mm;
    string s;
    vector<Node> data;
    Node temp;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>s;
            cin>>dd>>mm>>yy;
            temp.name=s;
            temp.d=dd;
            temp.m=mm;
            temp.y=yy;
            data.pb(temp);
        }

        sort(data.begin(), data.end(), cmp);
//        for(int i=0;i<n;i++)
//            cout<<data[i].name<<endl;



        cout<<data[n-1].name<<endl;
        cout<<data[0].name<<endl;

    }



    return 0;
}

