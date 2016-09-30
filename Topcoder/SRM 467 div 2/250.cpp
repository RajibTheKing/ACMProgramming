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

int rec(int k, int n)
{
    if(k==1) return n*(n+1)/2;
    else
    {
        int sum = 0;

        for(int l=1;l<=n;l++)
        {
             sum+=rec(k-1, l);
        }
        return sum;
    }
}
class ShorterSuperSum
{
public:
	int calculate(int k, int n)
	{
	    if(k==1) return n*(n+1)/2;
	    else return rec(k, n);

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

	ShorterSuperSum objectShorterSuperSum;

	//test case0
	int param00 = 1;
	int param01 = 3;
	int ret0 = objectShorterSuperSum.calculate(param00,param01);
	int need0 = 6;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 2;
	int param11 = 3;
	int ret1 = objectShorterSuperSum.calculate(param10,param11);
	int need1 = 10;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 4;
	int param21 = 10;
	int ret2 = objectShorterSuperSum.calculate(param20,param21);
	int need2 = 2002;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 10;
	int param31 = 10;
	int ret3 = objectShorterSuperSum.calculate(param30,param31);
	int need3 = 167960;
	assert_eq(3,ret3,need3);

}
