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

class KingSort
{
public:
	vector <string> getSortedList(vector <string> kings)
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

void main( int argc, char* argv[] )
{

	KingSort objectKingSort;

	//test case0
	vector <string> param00;
	param00.push_back("Louis IX");
	param00.push_back("Louis VIII");
	vector <string> ret0 = objectKingSort.getSortedList(param00);
	vector <string> need0;
	need0.push_back("Louis VIII");
	need0.push_back("Louis IX");
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("Louis IX");
	param10.push_back("Philippe II");
	vector <string> ret1 = objectKingSort.getSortedList(param10);
	vector <string> need1;
	need1.push_back("Louis IX");
	need1.push_back("Philippe II");
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("Richard III");
	param20.push_back("Richard I");
	param20.push_back("Richard II");
	vector <string> ret2 = objectKingSort.getSortedList(param20);
	vector <string> need2;
	need2.push_back("Richard I");
	need2.push_back("Richard II");
	need2.push_back("Richard III");
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("John X");
	param30.push_back("John I");
	param30.push_back("John L");
	param30.push_back("John V");
	vector <string> ret3 = objectKingSort.getSortedList(param30);
	vector <string> need3;
	need3.push_back("John I");
	need3.push_back("John V");
	need3.push_back("John X");
	need3.push_back("John L");
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("Philippe VI");
	param40.push_back("Jean II");
	param40.push_back("Charles V");
	param40.push_back("Charles VI");
	param40.push_back("Charles VII");
	param40.push_back("Louis XI");
	vector <string> ret4 = objectKingSort.getSortedList(param40);
	vector <string> need4;
	need4.push_back("Charles V");
	need4.push_back("Charles VI");
	need4.push_back("Charles VII");
	need4.push_back("Jean II");
	need4.push_back("Louis XI");
	need4.push_back("Philippe VI");
	assert_eq(4,ret4,need4);

	//test case5
	vector <string> param50;
	param50.push_back("Philippe II");
	param50.push_back("Philip II");
	vector <string> ret5 = objectKingSort.getSortedList(param50);
	vector <string> need5;
	need5.push_back("Philip II");
	need5.push_back("Philippe II");
	assert_eq(5,ret5,need5);

}
