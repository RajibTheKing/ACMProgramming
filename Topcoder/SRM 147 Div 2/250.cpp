
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

class CCipher
{
public:
	string decode(string cipherText, int shift)
	{
	    string a="";
	    int t;
	    for(int i=0;i<cipherText.length();i++)
        {
            t = cipherText[i]-shift;
            if(t<65) t+=26;
            a+=t;
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

	CCipher objectCCipher;

	//test case0
	string param00 = "VQREQFGT";
	int param01 = 2;
	string ret0 = objectCCipher.decode(param00,param01);
	string need0 = "TOPCODER";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int param11 = 10;
	string ret1 = objectCCipher.decode(param10,param11);
	string need1 = "QRSTUVWXYZABCDEFGHIJKLMNOP";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "TOPCODER";
	int param21 = 0;
	string ret2 = objectCCipher.decode(param20,param21);
	string need2 = "TOPCODER";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "ZWBGLZ";
	int param31 = 25;
	string ret3 = objectCCipher.decode(param30,param31);
	string need3 = "AXCHMA";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "DBNPCBQ";
	int param41 = 1;
	string ret4 = objectCCipher.decode(param40,param41);
	string need4 = "CAMOBAP";
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "LIPPSASVPH";
	int param51 = 4;
	string ret5 = objectCCipher.decode(param50,param51);
	string need5 = "HELLOWORLD";
	assert_eq(5,ret5,need5);

}
