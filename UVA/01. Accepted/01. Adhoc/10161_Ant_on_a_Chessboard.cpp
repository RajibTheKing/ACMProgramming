#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long n;
	while(cin>>n)
	{
		if(n == 0) break;
		double sroot = sqrt(n);
		long long index1 = floor(sroot);
		long long index2 = index1 + 1;

		long long diff = index2 * index2 - index1 * index1;
		long long relativeDiff = n - (index1 * index1);
		long long lenUpOrDown = (long long)diff / 2;
		long long ansX, ansY;
		if(index1 % 2 == 0)
		{
			if(relativeDiff == 0)
			{
				ansX = index1;
				ansY = 1;
			}
			else if(relativeDiff <= lenUpOrDown)
			{	
				ansX = index1 + 1;
				ansY = relativeDiff;
			}
			else if(relativeDiff == lenUpOrDown + 1)
			{
				ansX = index1 + 1;
				ansY = index1 + 1;
			}
			else if(relativeDiff > lenUpOrDown + 1)
			{
				ansX = index1 + 1 - (relativeDiff - lenUpOrDown - 1);
				ansY = index1 + 1;
			}
		}
		else
		{
			if(relativeDiff == 0)
			{
				ansX = 1;
				ansY = index1;
			}
			else if(relativeDiff <= lenUpOrDown)
			{	
				ansX = relativeDiff;
				ansY = index1 + 1;
			}
			else if(relativeDiff == lenUpOrDown + 1)
			{
				ansX = index1 + 1;
				ansY = index1 + 1;
			}
			else if(relativeDiff > lenUpOrDown + 1)
			{
				ansX = index1 + 1 ;
				ansY = index1 + 1 - (relativeDiff - lenUpOrDown - 1);
			}
		}
		cout<<ansX<<" "<<ansY<<endl;
		
	}
	return 0;
}