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

class PrimeSoccer
{
public:
	double getProbability(int skillOfTeamA, int skillOfTeamB)
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

	PrimeSoccer objectPrimeSoccer;

	//test case0
	int param00 = 50;
	int param01 = 50;
	double ret0 = objectPrimeSoccer.getProbability(param00,param01);
	double need0 = 0.5265618908306351;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 100;
	int param11 = 100;
	double ret1 = objectPrimeSoccer.getProbability(param10,param11);
	double need1 = 0.0;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 12;
	int param21 = 89;
	double ret2 = objectPrimeSoccer.getProbability(param20,param21);
	double need2 = 0.6772047168840167;
	assert_eq(2,ret2,need2);

}
