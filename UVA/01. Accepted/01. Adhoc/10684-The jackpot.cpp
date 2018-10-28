#include <iostream>
#include <algorithm>

#include <stdio.h>
#include <limits.h>
using namespace std;

int main()
{
	int n, temp;
	int max_so_far, currentMax;

	while(scanf("%d", &n) == 1)
	{
		if(n == 0) break;
		max_so_far = INT_MIN;
		scanf("%d", &temp);
		currentMax = temp;
		max_so_far = max(max_so_far, currentMax);
		
		for(int i=1; i<n;i++)
		{
			scanf("%d", &temp);

			currentMax = max(currentMax + temp , temp);
			max_so_far = max(max_so_far, currentMax);
		}

		if(max_so_far > 0)
		{
			printf("The maximum winning streak is %d.\n", max_so_far);
		}
		else
		{
			printf("Losing streak.\n");
		}

	}
	return 0;
}