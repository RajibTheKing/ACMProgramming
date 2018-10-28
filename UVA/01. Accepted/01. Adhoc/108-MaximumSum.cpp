#include <iostream>
#include <string.h>
#include <stdint.h>
#include <limits.h>
using namespace std;
#define MX 105

int KadanesAgorithm(int temp[], int &start, int &end, int len)
{
	int maxSum = temp[0];
	int currentSum = temp[0];
	int tempStart = 0;
	int tempEnd = 0;
	for(int i=1; i<len; i++)
	{
		if(currentSum + temp[i] < temp[i])
		{
			tempStart = i;
			tempEnd = i;
			currentSum = temp[i];
		}
		else
		{
			tempEnd = i;
			currentSum = currentSum + temp[i];

		}

		if(maxSum < currentSum)
		{
			maxSum = currentSum;
			start = tempStart;
			end = tempEnd;
		}
	}

	return maxSum;

}

int main()
{
	int N;
	int input[MX][MX];
	int temp[MX];
	int maxSum, maxLeft, maxRight, maxUp, maxDown, start, end;

	while(scanf("%d", &N) == 1)
	{
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &input[i][j]);
		
		maxSum = INT_MIN;

		for(int left = 0; left < N; left++)
		{
			memset(temp, 0, sizeof(temp));
			for(int right = left; right < N; right++)
			{
				for(int i=0; i<N;i++)
					temp[i] = temp[i] + input[i][right];
				int currentSum = KadanesAgorithm(temp, start, end, N);
				if(maxSum < currentSum)
				{
					maxSum = currentSum;
					maxLeft = left;
					maxRight = right;
					maxUp = start;
					maxDown = end;
				}

			}
		}

		printf("%d\n", maxSum);
	}

	return 0;
}

/*
4
0 -2 -7 0 
9 2 -6 2
-4 1 -4 1 
-1 8 0 -2
*/



