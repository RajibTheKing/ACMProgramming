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

class SRMCards
{
public:
	int maxTurns(vector <int> cards)
	{
	    sort(&cards[0], &cards[cards.size()]);
	    int kount = 0;

	    for(int i=0;i<cards.size();i++)
	    {
	        if(cards[i]!=0)
                kount++;
            if(cards[i+1]==cards[i]+1) cards[i+1] = 0;
	    }

	    return kount;
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

	SRMCards objectSRMCards;

	//test case0
	vector <int> param00;
	param00.push_back(498);
	param00.push_back(499);
	int ret0 = objectSRMCards.maxTurns(param00);
	int need0 = 1;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(491);
	param10.push_back(492);
	param10.push_back(495);
	param10.push_back(497);
	param10.push_back(498);
	param10.push_back(499);
	int ret1 = objectSRMCards.maxTurns(param10);
	int need1 = 4;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(100);
	param20.push_back(200);
	param20.push_back(300);
	param20.push_back(400);
	int ret2 = objectSRMCards.maxTurns(param20);
	int need2 = 4;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(11);
	param30.push_back(12);
	param30.push_back(102);
	param30.push_back(13);
	param30.push_back(100);
	param30.push_back(101);
	param30.push_back(99);
	param30.push_back(9);
	param30.push_back(8);
	param30.push_back(1);
	int ret3 = objectSRMCards.maxTurns(param30);
	int need3 = 6;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(118);
	param40.push_back(321);
	param40.push_back(322);
	param40.push_back(119);
	param40.push_back(120);
	param40.push_back(320);
	int ret4 = objectSRMCards.maxTurns(param40);
	int need4 = 4;
	assert_eq(4,ret4,need4);

	//test case5
	vector <int> param50;
	param50.push_back(10);
	param50.push_back(11);
	param50.push_back(12);
	param50.push_back(13);
	param50.push_back(14);
	param50.push_back(1);
	param50.push_back(2);
	param50.push_back(3);
	param50.push_back(4);
	param50.push_back(5);
	param50.push_back(6);
	param50.push_back(7);
	param50.push_back(8);
	param50.push_back(9);
	int ret5 = objectSRMCards.maxTurns(param50);
	int need5 = 7;
	assert_eq(5,ret5,need5);

}
