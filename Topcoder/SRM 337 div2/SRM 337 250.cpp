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

class Palindromize2
{
public:
	string minChanges(string s)
	{
	    int l, i, j, m, n;
	    l=s.length();
	    for(i=0, j=l-1;i<l/2;i++, j--)
	    {
	        if(s[i]!=s[j])
            {
                if(s[i]>s[j])
                    s[i]=s[j];
                else
                    s[j]=s[i];

            }
	    }
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

	Palindromize2 objectPalindromize2;

	//test case0
	string param00 = "ameba";
	string ret0 = objectPalindromize2.minChanges(param00);
	string need0 = "abeba";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "cigartragic";
	string ret1 = objectPalindromize2.minChanges(param10);
	string need1 = "cigartragic";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "abcdef";
	string ret2 = objectPalindromize2.minChanges(param20);
	string need2 = "abccba";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "cxbpaxz";
	string ret3 = objectPalindromize2.minChanges(param30);
	string need3 = "cxapaxc";
	assert_eq(3,ret3,need3);

}

