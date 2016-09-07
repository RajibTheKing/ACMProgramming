
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

class HiddenMessage
{
public:
	string getMessage(string text)
	{
	    string a="";
	    int l;
	    l=text.length();
	    for(int i=0;i<l;i++)
	    {
	        if(text[i]>='a'&&text[i]<='z')
            {
                if((i-1)==-1)
                    a+=text[i];
                else if(text[i-1]==' ')
                    a+=text[i];
            }
	    }
        return a;
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

	HiddenMessage objectHiddenMessage;

	//test case0
	string param00 = "compete online design event rating";
	string ret0 = objectHiddenMessage.getMessage(param00);
	string need0 = "coder";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "  c    o d     e      r    ";
	string ret1 = objectHiddenMessage.getMessage(param10);
	string need1 = "coder";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "round  elimination during  onsite  contest";
	string ret2 = objectHiddenMessage.getMessage(param20);
	string need2 = "redoc";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = " ";
	string ret3 = objectHiddenMessage.getMessage(param30);
	string need3 = "";
	assert_eq(3,ret3,need3);

}
