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

int a[200], b[200];

int Find(int t)
{
   // cout<<"here: "<<t<<endl;
    if(a[t]!=0) return a[t];

    return Find(b[t]);
}
int main()
{
    int T, n, t, ans;
    cin>>T;
    string s;

    while(T--)
    {
        cin>>n;
        memset(a, 0, sizeof(a));
        memset(b, -1, sizeof(b));
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            if(s=="LEFT")
            {
                a[i]=-1;
                ans+=a[i];
            }
            else if(s=="RIGHT")
            {
                a[i]=1;
                ans+=a[i];
            }
            if(s=="SAME")
            {
                cin>>s;
                cin>>t;
                b[i]=t;
                ans+=Find(t);

            }
        }


        cout<<ans<<endl;
    }

    return 0;
}
