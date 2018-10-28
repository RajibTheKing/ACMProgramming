#include <iostream>
#include <string.h>
using namespace std;

int t, n, g;
int dp[1005][30005];
pair<int,int> pr[1005];

int solve(int cur, int weightSum)
{
	if(cur>=n || weightSum <= 0) 
	{
		return 0;
	} 


	int &ret = dp[cur][weightSum];
	if(ret != -1) return ret;
	ret = 0; 
	if(weightSum >= pr[cur].second)
	{
		ret = pr[cur].first + solve(cur+1, weightSum - pr[cur].second);
	}
	ret = max(ret, solve(cur+1, weightSum));

	return ret;
}

int main()
{
	cin>>t;
	int lmt[105];

	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		cin>> n;
		for(int i=0; i<n;i++)
		{
			cin>>pr[i].first>>pr[i].second; //Price and Weight
		}
		cin>>g;
		for(int i=0;i<g;i++)
		{
			cin>>lmt[i];
		}
		int ans = 0;
		for(int i=0; i<g; i++)
		{
			ans += solve(0, lmt[i]);
		}
		cout<<ans<<endl;


	}

	return 0;
}