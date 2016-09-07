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

class MarbleDecoration
{
public:
	int maxLength(int R, int G, int B)
	{
	    int a[3];
	    a[0]=R;a[1]=G;a[2]=B;
	    std::sort(a, a+3);
        if(a[2]>a[1])
            return (a[1]*2+1);
        else
            return (a[1]*2);

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

	MarbleDecoration objectMarbleDecoration;

	//test case0
	int param00 = 0;
	int param01 = 0;
	int param02 = 0;
	int ret0 = objectMarbleDecoration.maxLength(param00,param01,param02);
	int need0 = 0;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 3;
	int param11 = 0;
	int param12 = 0;
	int ret1 = objectMarbleDecoration.maxLength(param10,param11,param12);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 5;
	int param21 = 1;
	int param22 = 2;
	int ret2 = objectMarbleDecoration.maxLength(param20,param21,param22);
	int need2 = 5;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 7;
	int param31 = 7;
	int param32 = 4;
	int ret3 = objectMarbleDecoration.maxLength(param30,param31,param32);
	int need3 = 14;
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 2;
	int param41 = 3;
	int param42 = 5;
	int ret4 = objectMarbleDecoration.maxLength(param40,param41,param42);
	int need4 = 7;
	assert_eq(4,ret4,need4);

	//test case5
	int param50 = 13;
	int param51 = 13;
	int param52 = 13;
	int ret5 = objectMarbleDecoration.maxLength(param50,param51,param52);
	int need5 = 26;
	assert_eq(5,ret5,need5);

}

