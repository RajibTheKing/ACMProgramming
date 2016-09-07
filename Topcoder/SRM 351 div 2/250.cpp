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

class RoomNumber
{
public:
	int numberOfSets(int roomNumber)
	{
	    int a[10] , t;
	    //cout<<"rajib";
	    memset(a, 0, sizeof(a));
	    while(roomNumber>0)
	    {
	        t=roomNumber%10;
	        if(t==9) a[6]++;
	        else      a[t]++;
	        roomNumber/=10;
	    }
	    a[6]=(a[6]+1)/2;
	    int max=0;
	    for(int i=0;i<10;i++)
            if(a[i]>max) max=a[i];
       // printf("rajib");
        return max;
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

	RoomNumber objectRoomNumber;

	//test case0
	int param00 = 122;
	int ret0 = objectRoomNumber.numberOfSets(param00);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 9999;
	int ret1 = objectRoomNumber.numberOfSets(param10);
	int need1 = 2;
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 12635;
	int ret2 = objectRoomNumber.numberOfSets(param20);
	int need2 = 1;
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 888888;
	int ret3 = objectRoomNumber.numberOfSets(param30);
	int need3 = 6;
	assert_eq(3,ret3,need3);

}
