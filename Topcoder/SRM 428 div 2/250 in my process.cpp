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

class ThePalindrome
{
public:
	int find(string s)
	{
	    string t1, t2;
	    t1 = s;
	    int i, j, k=-1;

	    while(1)
	    {
	        t2="";

	        for(i=t1.size()-1;i>=0;i--)
                t2+=t1[i];

            //cout<<t1<<endl<<t2<<endl;
            if(t1==t2) break;

            else
            {
                t1=s;
                k++;
                for(j=k;j>=0;j--)
                    t1+=s[j];
            }


	    }

	    return t1.size();
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

	ThePalindrome objectThePalindrome;

	//test case0
	string param00 = "abab";
	int ret0 = objectThePalindrome.find(param00);
	int need0 = 5;
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "abacaba";
	int ret1 = objectThePalindrome.find(param10);
	int need1 = 7;
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "qwerty";
	int ret2 = objectThePalindrome.find(param20);
	int need2 = 11;
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "abdfhdyrbdbsdfghjkllkjhgfds";
	int ret3 = objectThePalindrome.find(param30);
	int need3 = 38;
	assert_eq(3,ret3,need3);

}

