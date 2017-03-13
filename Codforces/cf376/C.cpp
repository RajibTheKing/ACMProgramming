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
vector<int>adj[200005];
map<int,int> mp;

int kolor[200005];
int chk[200005];

int BFS(int x)
{
    //cout<<"Entering for: "<<x<<endl;
    queue<int> Q;
    int total = 1;
    int mx=0;
    Q.push(x);
    mp[kolor[x]]++;
    mx = max(mx, mp[kolor[x]]);

    kolor[x]=-1;
    chk[x]=1;




    while(!Q.empty())
    {
        int now = Q.front(); Q.pop();
        for(int i=0;i<adj[now].size();i++)
        {
            int nxt = adj[now][i];
            if(chk[nxt]==0)
            {
                //cout<<"Found new = "<<nxt<<endl;
                mp[kolor[nxt]]++;
                mx=max(mx,mp[kolor[nxt]]);

                kolor[nxt]=-1;
                chk[nxt]=1;
                total++;
                Q.push(nxt);
            }
        }

    }
    //cout<<"total = "<<total<<", mx = "<<mx<<endl;

    return total-mx;
}
int main()
{
    //freopen("/Users/RajibTheKing/Desktop/OnTry/cf376/input.txt", "r+", stdin);
    int n, m, k, u, v;
    set<int> st;


    cin>>n>>m>>k;
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &kolor[i]);
        }
        memset(chk,0, sizeof(chk));
        mp.clear();
        st.clear();

        int knt = 0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            st.insert(u);
            st.insert(v);
        }

        for(set<int>::iterator it=st.begin(); it!=st.end();it++)
        {

            if(kolor[*it]!=-1)
            {
                mp.clear();
                knt+=BFS(*it);
            }
        }


        cout<<knt<<endl;

    }

    return 0;
}

