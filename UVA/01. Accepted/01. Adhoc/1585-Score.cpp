#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set> 

#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int n;
	string str;
	while(cin>>n)
	{
		for(int i=0; i<n;i++)
		{
			cin>>str;
			
			long long sum = 0;
			long long now = 1;

			for(int i=0; i<str.size();i++)
			{
				//cout<<str[i]<<endl;

				if(str[i] == 'O')
				{
					sum+=now;
					now++;
				}
				else
				{
					now = 1;
				}
			}
			cout<<sum<<endl;
		}
	}
	

	return 0;
}
/*
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX
*/