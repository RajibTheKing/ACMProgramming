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

class DivisorDigits
{
public:
	int howMany(int number)
	{
	    int i, t, count;
	    t=number;
	    count = 0;

	    while(t>0)
	    {
	        i=t%10;
	        t=t/10;
	        if(i==0) continue;
	        if(number%i==0) count++;
        }

        return count;
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

	DivisorDigits objectDivisorDigits;

	//test case0
	int param00 = 12345;
	int ret0 = objectDivisorDigits.howMany(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 661232;
	int ret1 = objectDivisorDigits.howMany(param10);
	int need1 = 3;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 52527;
	int ret2 = objectDivisorDigits.howMany(param20);
	int need2 = 0;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 730000000;
	int ret3 = objectDivisorDigits.howMany(param30);
	int need3 = 0;
	assert_eq(3,ret3,need3);

}
