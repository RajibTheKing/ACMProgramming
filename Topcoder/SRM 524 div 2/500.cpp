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

class MagicDiamonds
{
public:
	long long minimalTransfer(long long n)
	{


	    if(n==1) return 1;
	    if(n==2) return 2;

	    bool flag;
	    flag=true;
	    for(long long i=3;i<=sqrt(n);i++)
            if(n%i==0)
            {
                flag=false;
                break;
            }

        if(flag==true)
            return 2;
        else return 1;
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

	MagicDiamonds objectMagicDiamonds;

	//test case0
	long long param00 = 2;
	long long ret0 = objectMagicDiamonds.minimalTransfer(param00);
	long long need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	long long param10 = 42949677;
	long long ret1 = objectMagicDiamonds.minimalTransfer(param10);
	long long need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	long long param20 = 2147483647;
	long long ret2 = objectMagicDiamonds.minimalTransfer(param20);
	long long need2 = 2;
	assert_eq(2,ret2,need2);

	//test case3
	long long param30 = 1;
	long long ret3 = objectMagicDiamonds.minimalTransfer(param30);
	long long need3 = 1;
	assert_eq(3,ret3,need3);

}
