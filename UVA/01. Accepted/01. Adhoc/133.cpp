#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	int n, k, m;
	int arr[100];

	while(cin>>n>>k>>m)
	{
		if(n == 0 && k == 0 && m == 0) break;
		memset(arr, 0, sizeof(arr));

		int kounter = n;
		int loop1 = 0;
		int loop2 = n+1;
		while(kounter)
		{
			int tempK = k;
			while(tempK)
			{
				tempK--;
				loop1++;
				if(loop1>n) loop1 = 1;
				if(arr[loop1] != 0) 
				{
					tempK++;
					continue;
				}
				//cout<<"loop1: "<<loop1<<endl;
				
			}

			int tempM = m;
			while(tempM)
			{
				tempM--;
				loop2--;
				if(loop2<1) loop2 = n;
				if(arr[loop2] != 0)
				{
					tempM++;
					continue;
				}

				//cout<<"loop2: "<<loop2<<endl;

			}

			if(kounter < n)
				printf(",");
			if(loop1 == loop2)
			{
				printf("%3d", loop1);
				kounter--;	
			}
			else
			{

				printf("%3d%3d", loop1, loop2);
				kounter-=2;
			}
			
			arr[loop1] = 1;
			arr[loop2] = 1;
		}
		cout<<endl;

	}
	return 0;
}