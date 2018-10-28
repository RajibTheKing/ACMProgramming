#include <iostream>
#include <algorithm>
#include <map>

#include <stdio.h>
#include <limits.h>
using namespace std;

int digitSquareSum(int n)
{
	int sum = 0;
	while(n)
	{
		int temp = n%10;
		sum+=(temp*temp);
		n/=10;
	}
	return sum;
}

int main()
{
	int tests, n;
	map<int,bool> mp;
	cin>>tests;
	for(int kase = 1; kase<=tests; kase++)
	{
		mp.clear();
		cin>>n;
		int temp = n;
		while(mp[temp] == false)
		{
			mp[temp] = true;
			temp = digitSquareSum(temp);
		}
		if(mp[1] == true)
		{
			printf("Case #%d: %d is a Happy number.\n", kase, n);
		}
		else
		{
			printf("Case #%d: %d is an Unhappy number.\n", kase, n);	
		}
	}
	return 0;
}