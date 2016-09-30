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
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

typedef struct Node
{
    string userId;
    int num;
};

Node ans[110];


bool cmp(Node a, Node b)
{
    if(a.num==b.num)
        return a.userId<b.userId;
    else
        return a.num>b.num;
}

map<string, bool> mp;
map<string, int> mp2;
map<string, bool> mp3;

int main()
{
    //freopen("input.txt", "r", stdin);
    string str;
    int kount=-1;
    mp.clear();
    mp2.clear();
    mp3.clear();
    while(getline(cin, str))
    {
        //cout<<"Here found: "<<str<<endl;
        if(str.size()<1) continue;
        if(str[0]=='0') break;
        if(str[0]=='1')
        {
            sort(&ans[0], &ans[kount+1], cmp);

            for(int i=0;i<=kount;i++)
                cout<<ans[i].userId<<" "<<ans[i].num<<endl;

            mp.clear();
            mp2.clear();
            mp3.clear();
            kount=-1;
        }

        if(str[0]>='A'&&str[0]<='Z')
        {
            ans[++kount].userId=str;
            ans[kount].num=0;
            continue;
        }

        if(mp3[str]==true)
            continue;

        if(mp[str]==true)
        {
            if(mp2[str]==kount) continue;
            ans[mp2[str]].num--;
            mp3[str]=true;
            continue;
        }

        if(mp[str]==false)
        {
            mp[str]=true;
            mp2[str]=kount;
            ans[kount].num++;
        }
    }



    return 0;
}
