#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define INF 99999999
int N, T, minimum, ans;
int color[100];
int a[100];
vector<int> b;

void rec(int cur, int sum)
{
    if(sum>N) return;
    if(cur>T) return;

    if((N-sum)<minimum)
    {
        minimum=N-sum;
        ans=sum;
        b.clear();
        for(int i=0;i<T;i++)
        {
            if(color[i]==1)
                b.push_back(a[i]);
        }

    }
    if(color[cur]==0)
    {
        color[cur]=1;
        rec(cur+1, sum+a[cur]);
    }
    color[cur]=0;
    rec(cur+1, sum);
    return;
}
int main()
{
    while(cin>>N)
    {
        cin>>T;
        minimum=INF;
        memset(color, 0, sizeof(0));
        for(int i=0;i<T;i++)
            cin>>a[i];

        rec(0, 0);

        for(int i=0;i<b.size();i++)
            cout<<b[i]<<" ";
        cout<<"sum:"<<ans<<endl;

    }
}
