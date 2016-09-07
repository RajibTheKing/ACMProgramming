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

class BiggestRectangleEasy
{
public:
	int findArea(int N)
	{
	    int ans, k, a, b;
	    if(N%2!=0)
            N--;
        ans = N/2;

        if(ans%2!=0)
        {
            a=ans/2+1;
            b=ans-a;
        }
        else
        {
            a=ans/2;
            b=ans-a;
        }

        return a*b;

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

	BiggestRectangleEasy objectBiggestRectangleEasy;

	//test case0
	int param00 = 11;
	int ret0 = objectBiggestRectangleEasy.findArea(param00);
	int need0 = 6;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 5;
	int ret1 = objectBiggestRectangleEasy.findArea(param10);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 64;
	int ret2 = objectBiggestRectangleEasy.findArea(param20);
	int need2 = 256;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 753;
	int ret3 = objectBiggestRectangleEasy.findArea(param30);
	int need3 = 35344;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 7254;
	int ret4 = objectBiggestRectangleEasy.findArea(param40);
	int need4 = 3288782;
	assert_eq(4,ret4,need4);

}

