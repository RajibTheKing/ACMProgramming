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

int main()
{
    string str;
    int T, N;
    int a[200];
    cin>>T;
    int kase=0;
    while(T--)
    {

        cin>>N;
        cin>>str;
        memset(a, 0, sizeof(a));
        for(int j=0; j<N; j++)
        {
            a[str[j]]++;
        }
        csprnt;
        if(a['B']>0&&a['W']==0&&a['T']==0)
            cout<<"BANGLAWASH"<<endl;
        else if(a['W']>0&&a['B']==0&&a['T']==0)
            cout<<"WHITEWASH"<<endl;
        else if(a['B']==0&&a['W']==0&&a['T']==0)
            cout<<"ABANDONED"<<endl;
        else if(a['B']>a['W'])
            cout<<"BANGLADESH "<<a['B']<<" - "<<a['W']<<endl;
        else if(a['W']>a['B'])
            cout<<"WWW "<<a['W']<<" - "<<a['B']<<endl;
        else if(a['W']==a['B'])
            cout<<"DRAW "<<a['B']<<" "<<a['T']<<endl;


    }

    return 0;
}
