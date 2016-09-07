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

class TheEquation
{
public:
	int leastSum(int X, int Y, int P)
	{
	    int l = 9999999;
        int i, j;
        for(i=1;i<=P;i++)
        {
            for(j=1;j<=P;j++)
            {
                if(((i*X+j*Y)%P==0) && (l>(i+j)))
                {
                    l=i+j;
                }
            }
        }
        return l;
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

	TheEquation objectTheEquation;

	//test case0
	int param00 = 2;
	int param01 = 6;
	int param02 = 5;
	int ret0 = objectTheEquation.leastSum(param00,param01,param02);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 5;
	int param11 = 5;
	int param12 = 5;
	int ret1 = objectTheEquation.leastSum(param10,param11,param12);
	int need1 = 2;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 998;
	int param21 = 999;
	int param22 = 1000;
	int ret2 = objectTheEquation.leastSum(param20,param21,param22);
	int need2 = 501;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 1;
	int param31 = 1;
	int param32 = 1000;
	int ret3 = objectTheEquation.leastSum(param30,param31,param32);
	int need3 = 1000;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 347;
	int param41 = 873;
	int param42 = 1000;
	int ret4 = objectTheEquation.leastSum(param40,param41,param42);
	int need4 = 34;
	assert_eq(4,ret4,need4);

}

