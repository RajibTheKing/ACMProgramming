#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int tests;
	cin>>tests;
	int W, N;
	int distances[1005];
	int weights[1005];
	while(tests--)
	{
		cin>>W>>N;
		int totalWeight = 0;
		for(int i=0; i<N; i++)
		{
			cin>>distances[i] >> weights[i];
			totalWeight += weights[i];
		}

		int totalDistance = 0;
		int currentPosition = 0;
		int currentCapacity = W;

		for(int i=0; i<N; i++)
		{
			if(totalWeight <= 0) break;
			totalDistance+=(distances[i]-currentPosition);
			currentPosition = distances[i];
			if(currentCapacity > weights[i])
			{
				currentCapacity -= weights[i];
				totalWeight -= weights[i];
				weights[i] = 0;
				continue;
			}
			else if(currentCapacity == weights[i])
			{
				totalWeight -= currentCapacity;
				currentCapacity = W;
				weights[i] = 0;
				totalDistance += currentPosition;
				currentPosition = 0;
				i = -1;
				continue;
			}
			else
			{
				
				//totalWeight -= currentCapacity;
				//weights[i] -= currentCapacity;
				currentCapacity = W;
				totalDistance += currentPosition;
				currentPosition = 0;
				i = -1;
				continue;
				
			}
		}
		if(currentPosition != 0) totalDistance += currentPosition;
		cout<<totalDistance<<endl;

	}
	return 0;
}
/*
564 12
1 380
3 551
8 25
15 520
21 36
24 321
30 20
37 517
44 399
49 506
59 319
64 8
*/
//570

