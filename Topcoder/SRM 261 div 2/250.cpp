
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

class SpreadsheetColumn
{
public:
	string getLabel(int column)
	{

	    int i, j;
	    char c, d;
	    string s;
	    char a[1000][10];
	    for(i=1;i<=26;i++)
	    {
	        c=i+64;
            a[i][0]=c;


	    }
	    int k=26;
	    for(i=1;i<=26;i++)
	    {
	        for(j=1;j<=26;j++)
	        {
	            c=i+64;
	            d=j+64;
	            a[++k][0]=c;
	            a[k][1]=d;
	        }
	    }


        s="";
        s+=a[column][0];
        if(column>26)
        s+=a[column][1];
        return s;
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

	SpreadsheetColumn objectSpreadsheetColumn;

	//test case0
	int param00 = 1;
	string ret0 = objectSpreadsheetColumn.getLabel(param00);
	string need0 = "A";
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 2;
	string ret1 = objectSpreadsheetColumn.getLabel(param10);
	string need1 = "B";
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 27;
	string ret2 = objectSpreadsheetColumn.getLabel(param20);
	string need2 = "AA";
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 111;
	string ret3 = objectSpreadsheetColumn.getLabel(param30);
	string need3 = "DG";
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 702;
	string ret4 = objectSpreadsheetColumn.getLabel(param40);
	string need4 = "ZZ";
	assert_eq(4,ret4,need4);

}
