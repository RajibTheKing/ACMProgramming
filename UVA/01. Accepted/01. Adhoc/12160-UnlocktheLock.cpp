#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string.h>
#include <limits.h>
#include <stdio.h>
using namespace std;

int buttons[11];
int dp[20000];
int L, V, R;

int main()
{
	//freopen("in.txt", "r", stdin);
	int kase = 0;
	while(cin>>L>>V>>R)
	{
		if(L == 0 && V == 0 && R == 0) break;
		for(int i=0; i<R; i++)
		{
			cin>>buttons[i];
		}

		memset(dp, -1, sizeof(dp));
		/*
		int target;
		if(V < L)
		{
			target = 10000 - L;
			target += V;
		}
		else
		{
			target = V - L;
		}

		//cout<<"Here: target = "<<target<<endl;
		dp[0] = 0;
		for(int i=1; i<=9999; i++)
		{
			dp[i] = INT_MAX; 
		}
		map<int, bool> mp;
		for(int i=0; i<R; i++)
		{
			mp.clear();
			int prevValue = dp[0];
			for(int j=buttons[i]; mp[j]==false; j+=buttons[i])
			{
				j = j % 10000;
				dp[j] = min(prevValue+1, dp[j]);
				prevValue = dp[j];
				mp[j] = true;
			}
		}
		
		for(int i=5970; i<5990; i++)
		{
			cout<<i<<": "<<dp[i]<<endl;
		}
		cout<<endl;
		*/

		queue<int> Q;
		while(!Q.empty()) Q.pop();

		Q.push(L);
		dp[L] = 0;
		while(!Q.empty())
		{
			int now = Q.front(); Q.pop();
			for(int i=0; i<R; i++)
			{
				int temp = now + buttons[i];
				temp = temp%10000;
				if(dp[temp] == -1)
				{
					dp[temp] = dp[now] + 1;
					Q.push(temp);
				}
			}
		}



		if(dp[V] == -1)
			printf("Case %d: Permanently Locked\n", ++kase);
		else
			printf("Case %d: %d\n", ++kase, dp[V]);

	}

	return 0;
}

/*
5234 1212 3
1023 0101 0001

5234 1212 3
1023 0101 0001

5978
1023 * 5 =  5115
101 * 8  = 808

1023 * 3 = 3069
101 * 28 = 2828

1023 * 2 = 2046
101 * 38 = 3838



*/





