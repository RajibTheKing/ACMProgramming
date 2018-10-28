#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int arr[10];

	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(arr, 0, sizeof(arr));
		for(int i=1; i<=n; i++)
		{
			int temp = i;
			while(temp)
			{
				arr[temp%10]++;
				temp/=10;

			}
		}
		for(int i=0; i<10; i++)
		{
			if(i) cout<<" "<<arr[i];
			else cout<<arr[i];
		}
		cout<<endl;
	}
	return 0;
}