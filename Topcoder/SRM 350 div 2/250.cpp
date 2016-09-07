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

class DistanceBetweenStrings
{
public:
	int getDistance(string a, string b, string letterSet)
	{
	    int ans=0;
	    int t, p,q;
	    for(int i=0;i<letterSet.length();i++)
	    {
	        p=0;q=0;
	        for(int j=0;j<a.length();j++)
	        {
	            if(a[j]==letterSet[i])
                    p++;
	        }
	        for(int k=0;k<b.length();k++)
	        {
	            if(b[k]==letterSet[i])
                    q++;
	        }
	        ans+=(p-q)*(p-q);
	    }
	    return ans;
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

	DistanceBetweenStrings objectDistanceBetweenStrings;

	//test case0
	string param00 = "topcoder";
	string param01 = "contest";
	string param02 = "tcp";
	int ret0 = objectDistanceBetweenStrings.getDistance(param00,param01,param02);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "abcdef";
	string param11 = "fedcba";
	string param12 = "fed";
	int ret1 = objectDistanceBetweenStrings.getDistance(param10,param11,param12);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "aaaaa";
	string param21 = "bbbbb";
	string param22 = "a";
	int ret2 = objectDistanceBetweenStrings.getDistance(param20,param21,param22);
	int need2 = 25;
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "aaAaB";
	string param31 = "BbaAa";
	string param32 = "ab";
	int ret3 = objectDistanceBetweenStrings.getDistance(param30,param31,param32);
	int need3 = 2;
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string param41 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	string param42 = "ba";
	int ret4 = objectDistanceBetweenStrings.getDistance(param40,param41,param42);
	int need4 = 5000;
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "ToPcOdEr";
	string param51 = "tOpCoDeR";
	string param52 = "wxyz";
	int ret5 = objectDistanceBetweenStrings.getDistance(param50,param51,param52);
	int need5 = 0;
	assert_eq(5,ret5,need5);

}
