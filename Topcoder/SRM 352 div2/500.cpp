#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class NumberofFiboCalls
{
public:
	vector <int> fiboCallsMade(int n)
	{
	    vector<int> a;
	    int dp[100];
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=1;

	    for(int i=3;i<=n;i++)
	    {
	        dp[i]=dp[i-1] + dp[i-2];
	    }

        if(n==0)
        {
            a.push_back(1);
            a.push_back(0);
            return a;
        }

	    a.push_back(dp[n-1]);
	    a.push_back(dp[n]);

	    return a;
	}
};


template<typename T> void print( T a ) {
    cerr << a;
}

void print( long long a ) {
    cerr << a << "L";
}

void print( string a ) {
    cerr << '"' << a << '"';
}

template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}

template<typename T> void assert_eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

template<typename T> void assert_eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
void assert_eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

main( int argc, char* argv[] )
{

	NumberofFiboCalls objectNumberofFiboCalls;

	//test case0
	int param00 = 0;
	vector <int> ret0 = objectNumberofFiboCalls.fiboCallsMade(param00);
	vector <int> need0;
	need0.push_back(1);
	need0.push_back(0);
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 3;
	vector <int> ret1 = objectNumberofFiboCalls.fiboCallsMade(param10);
	vector <int> need1;
	need1.push_back(1);
	need1.push_back(2);
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 6;
	vector <int> ret2 = objectNumberofFiboCalls.fiboCallsMade(param20);
	vector <int> need2;
	need2.push_back(5);
	need2.push_back(8);
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 22;
	vector <int> ret3 = objectNumberofFiboCalls.fiboCallsMade(param30);
	vector <int> need3;
	need3.push_back(10946);
	need3.push_back(17711);
	assert_eq(3,ret3,need3);

}

