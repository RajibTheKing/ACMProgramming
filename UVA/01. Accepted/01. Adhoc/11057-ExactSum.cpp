#include <iostream>
#include <stdio.h>
using namespace std;

int getDiff(int a, int b)
{
	if(a>b) return a-b;
	else return b-a;
}

int main()
{
	int n;
	int arr[10005];
	int price;
	while(cin>>n)
	{
		for(int i=0; i<n; i++) cin>>arr[i];
		cin>> price;
		int diff = 1000001;
		int maxSum = 0;
		int ansI, ansJ;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i == j) continue;
				int sum = arr[i] + arr[j];
				if(sum <= price)
				{
					if(sum >= maxSum)
					{
						if(sum == maxSum)
						{
							if(getDiff(arr[i], arr[j]) < getDiff(ansI, ansJ))
							{
								ansI = arr[i];
								ansJ = arr[j];
							}
						}
						else
						{
							maxSum = sum;
							ansI = arr[i];
							ansJ = arr[j];
						}
					}
				}

			}
		}

		if(ansI > ansJ)
		{
			int temp = ansI;
			ansI = ansJ;
			ansJ = temp;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", ansI, ansJ);

	}
	return 0;
}