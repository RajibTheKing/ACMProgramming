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
#include<math.h>
using namespace std;
class CountingSeries
{
public:
	long long countThem(long long a, long long b, long long c, long long d, long long u)
	{
	    long long total=0;
	    if(u-a>=0)
            total = (u-a)/b + 1;

	    for(long long r=c;r<=u;r*=d)
	    {
	        if(r>=a&&(r-a)%b==0)
            {
                if(d==1) break;
                continue;
            }
            total++;
            if(d==1) break;
        }

        return total;
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

	CountingSeries objectCountingSeries;

	//test case0
	long long param00 = 1;
	long long param01 = 1;
	long long param02 = 1;
	long long param03 = 2;
	long long param04 = 1000;
	long long ret0 = objectCountingSeries.countThem(param00,param01,param02,param03,param04);
	long long need0 = 1000;
	assert_eq(0,ret0,need0);

	//test case1
	long long param10 = 3;
	long long param11 = 3;
	long long param12 = 1;
	long long param13 = 2;
	long long param14 = 1000;
	long long ret1 = objectCountingSeries.countThem(param10,param11,param12,param13,param14);
	long long need1 = 343;
	assert_eq(1,ret1,need1);

	//test case2
	long long param20 = 40;
	long long param21 = 77;
	long long param22 = 40;
	long long param23 = 100000;
	long long param24 = 40;
	long long ret2 = objectCountingSeries.countThem(param20,param21,param22,param23,param24);
	long long need2 = 1;
	assert_eq(2,ret2,need2);

	//test case3
	long long param30 = 452;
	long long param31 = 24;
	long long param32 = 4;
	long long param33 = 5;
	long long param34 = 600;
	long long ret3 = objectCountingSeries.countThem(param30,param31,param32,param33,param34);
	long long need3 = 10;
	assert_eq(3,ret3,need3);

	//test case4
	long long param40 = 234;
	long long param41 = 24;
	long long param42 = 377;
	long long param43 = 1;
	long long param44 = 10000;
	long long ret4 = objectCountingSeries.countThem(param40,param41,param42,param43,param44);
	long long need4 = 408;
	assert_eq(4,ret4,need4);

}
