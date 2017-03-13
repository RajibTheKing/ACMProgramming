
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

class PairingPawns
{
public:
	int savedPawnCount(vector <int> start)
	{
	    int n;
	    n=start.size();
	    int temp=0, x=0;
	    for(int i=n-1;i>=0;i--)
	    {
	        temp=start[i]+x;
	        x=ceil(temp/2);
        }
        return temp;



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

	PairingPawns objectPairingPawns;

	//test case0
	vector <int> param00;
	param00.push_back(0);
	param00.push_back(2);
	int ret0 = objectPairingPawns.savedPawnCount(param00);
	int need0 = 1;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(10);
	param10.push_back(3);
	int ret1 = objectPairingPawns.savedPawnCount(param10);
	int need1 = 11;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(0);
	param20.push_back(0);
	param20.push_back(0);
	param20.push_back(8);
	int ret2 = objectPairingPawns.savedPawnCount(param20);
	int need2 = 1;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(0);
	param30.push_back(1);
	param30.push_back(1);
	param30.push_back(2);
	int ret3 = objectPairingPawns.savedPawnCount(param30);
	int need3 = 1;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(123456);
	int ret4 = objectPairingPawns.savedPawnCount(param40);
	int need4 = 0;
	assert_eq(4,ret4,need4);

	//test case5
	vector <int> param50;
	param50.push_back(1000);
	param50.push_back(2000);
	param50.push_back(3000);
	param50.push_back(4000);
	param50.push_back(5000);
	param50.push_back(6000);
	param50.push_back(7000);
	param50.push_back(8000);
	int ret5 = objectPairingPawns.savedPawnCount(param50);
	int need5 = 3921;
	assert_eq(5,ret5,need5);

}
