#include <iostream> 
using namespace std;

bool isOnBorder(int a, int b, int x, int y)
{
	if( a == x || b == y) return true;
	return false;
}

int main()
{
	int K;
	int a, b;
	int x, y;
	while(cin>>K)
	{
		if (K == 0) break;
		cin >> a >> b;
		for(int i = 0; i < K ; i++)
		{
			cin >> x >> y;
			if( a == x || b == y) 
				cout << "divisa" << endl;
			else if( x < a && y < b)
				cout << "SO" << endl;
			else if( x < a && y > b)
				cout << "NO" << endl;
			else if( x > a && y > b)
				cout << "NE" << endl;
			else 
				cout << "SE" << endl;
		}

	}
	return 0;
}
/*
3
2 1
10 10
-10 1
0 33
4
-1000 -1000
-1000 -1000
0 0
-2000 -10000
-999 -1001
0
*/