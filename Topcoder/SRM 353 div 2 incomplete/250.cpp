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

class EllipseCoverage
{
public:
	int calculateCoverage(int x1, int y1, int x2, int y2, int d)
	{

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

	EllipseCoverage objectEllipseCoverage;

	//test case0
	int param00 = 0;
	int param01 = 0;
	int param02 = 0;
	int param03 = 0;
	int param04 = 4;
	int ret0 = objectEllipseCoverage.calculateCoverage(param00,param01,param02,param03,param04);
	int need0 = 9;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = -3;
	int param11 = 0;
	int param12 = 3;
	int param13 = 0;
	int param14 = 10;
	int ret1 = objectEllipseCoverage.calculateCoverage(param10,param11,param12,param13,param14);
	int need1 = 59;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 10;
	int param21 = 12;
	int param22 = 8;
	int param23 = 14;
	int param24 = 50;
	int ret2 = objectEllipseCoverage.calculateCoverage(param20,param21,param22,param23,param24);
	int need2 = 1941;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 0;
	int param31 = 0;
	int param32 = 0;
	int param33 = 0;
	int param34 = 200;
	int ret3 = objectEllipseCoverage.calculateCoverage(param30,param31,param32,param33,param34);
	int need3 = 31397;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 13;
	int param41 = -23;
	int param42 = 49;
	int param43 = 91;
	int param44 = 200;
	int ret4 = objectEllipseCoverage.calculateCoverage(param40,param41,param42,param43,param44);
	int need4 = 25187;
	assert_eq(4,ret4,need4);

}
