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
#include<string.h>

using namespace std;
int dp[205][205][205];
int num;
int mm;
void rec(int n1, int n2, int n3)
{
    if(dp[n1][n2][n3]==0) return;
    dp[n1][n2][n3]=0;

    if(n1*n2*n3==num)
    {
        if(mm>(n1+n2+n3))
            mm =  n1+n2+n3;
    }

    if(n1==num||n2==num||n3==num) return;




    if(dp[n1+1][n2][n3]==-1)
        rec(n1+1, n2, n3);

    if(dp[n1][n2+1][n3]==-1)
        rec(n1, n2+1, n3);
    if(dp[n1][n2][n3+1]==-1)
        rec(n1, n2, n3+1);
}

class ShippingCubes
{
public:
	int minimalCost(int N)
	{
	    mm=9999999;
        memset(dp, -1, sizeof(dp));
	    num = N;
	    rec(1,1,1);
	    return mm;


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

	ShippingCubes objectShippingCubes;

	//test case0
	int param00 = 1;
	int ret0 = objectShippingCubes.minimalCost(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 6;
	int ret1 = objectShippingCubes.minimalCost(param10);
	int need1 = 6;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 7;
	int ret2 = objectShippingCubes.minimalCost(param20);
	int need2 = 9;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 200;
	int ret3 = objectShippingCubes.minimalCost(param30);
	int need3 = 18;
	assert_eq(3,ret3,need3);

}

