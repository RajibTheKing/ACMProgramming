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

class MysteriousRestaurant
{
public:
	int maxDays(vector <string> prices, int budget)
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

	MysteriousRestaurant objectMysteriousRestaurant;

	//test case0
	vector <string> param00;
	param00.push_back("26");
	param00.push_back("14");
	param00.push_back("72");
	param00.push_back("39");
	param00.push_back("32");
	param00.push_back("85");
	param00.push_back("06");
	int param01 = 13;
	int ret0 = objectMysteriousRestaurant.maxDays(param00,param01);
	int need0 = 5;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("26");
	param10.push_back("14");
	param10.push_back("72");
	param10.push_back("39");
	param10.push_back("32");
	param10.push_back("85");
	param10.push_back("06");
	param10.push_back("91");
	int param11 = 20;
	int ret1 = objectMysteriousRestaurant.maxDays(param10,param11);
	int need1 = 8;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("SRM");
	param20.push_back("512");
	int param21 = 4;
	int ret2 = objectMysteriousRestaurant.maxDays(param20,param21);
	int need2 = 0;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("Dear");
	param30.push_back("Code");
	param30.push_back("rsHa");
	param30.push_back("veFu");
	param30.push_back("nInT");
	param30.push_back("heCh");
	param30.push_back("alle");
	param30.push_back("ngeP");
	param30.push_back("hase");
	param30.push_back("andb");
	param30.push_back("ecar");
	param30.push_back("eful");
	int param31 = 256;
	int ret3 = objectMysteriousRestaurant.maxDays(param30,param31);
	int need3 = 10;
	assert_eq(3,ret3,need3);

}

