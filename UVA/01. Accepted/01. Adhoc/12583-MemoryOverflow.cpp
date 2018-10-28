#include <iostream>
#include <algorithm> 
#include <string>
#include <stdio.h>
using namespace std;

bool isFound(int cur, string str, int k)
{
	char charToFind = str[cur];
	int start = max(0, cur-k);
	for(int i = start; i<cur; i++)
	{
		if(str[i] == charToFind) return true;
	}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int kase = 0;
	int T;
	cin>>T;
	int n, k;
	string names;
	while(T--)
	{
		cin>>n>>k;
		cin>>names;
		int ans = 0;
		for(int i=0; i<names.size(); i++)
		{
			if(isFound(i, names, k) == true)
			{
				//cout<<"Cur = "<<i<<endl;
				ans++;
			}
		}
		printf("Case %d: %d\n", ++kase, ans);
	}
	return 0;
}
/*
3
6 2 SULTAN
6 1 MAHBUB
6 2 MAHBUB
*/
