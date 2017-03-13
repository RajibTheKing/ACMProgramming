#include<bits/stdc++.h>
using namespace std;
#define SZ 25
int dp[SZ][1001];
int arr[SZ];
int T, Target, n;
bool rec(int cur, int sum, int Target)
{
    if(sum==Target) return true;
    if(cur>=n) return false;
    if(sum>Target) return false;

    int &ret = dp[cur][sum];
    if(ret!=-1) return ret;
    ret = false;
    ret|=rec(cur+1, sum+arr[cur], Target);
    ret|=rec(cur+1, sum, Target);
    return ret;
}
int main()
{

    cin>>T;
    while(T--)
    {
        memset(dp, -1, sizeof(dp));
        cin>>Target;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(rec(0,0,Target))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
