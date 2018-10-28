#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	double sum;
	double vals[1005];
	while(cin>>n)
	{
		if(n==0) break;
		sum = 0;
		for(int i=0; i<n; i++)
		{
			cin>>vals[i];
			vals[i]*=100.00;
			sum+=vals[i];
		}
		//cout<<"Here: sum  = "<<sum<<endl;
		double avgDouble = sum / (n * 1.0);
		//cout<<"Here: avgDouble = "<<avgDouble<<endl;

		double negetive = 0;
		double positive = 0;
		for(int i=0; i<n; i++)
		{
			if(vals[i] < avgDouble)
			{
				negetive += (long)(avgDouble - vals[i])/100.0;
			}
			if(vals[i]>avgDouble)
			{
				positive += (long)(vals[i] - avgDouble)/100.0;
			}
		}

		printf("$%.2lf\n", negetive > positive? negetive : positive);
		
	}

	return 0;
}