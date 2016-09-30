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

class TwiceString
{
public:
	string getShortest(string s)
	{
	    string ans="";
        int i, j, k , l;
	    int flag;

	    for(i=s.length()-1; ;i--)
	    {
	        ans=s;
	        for(j=i;j<s.length();j++)
                ans+=s[j];

            flag=0;
            l=ans.length()-1;
            for(k=s.length()-1;k>=0;k--, l--)
            {
                if(s[k]!=ans[l])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {

                return ans;
            }
	    }

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

	TwiceString objectTwiceString;

	//test case0
	string param00 = "aba";
	string ret0 = objectTwiceString.getShortest(param00);
	string need0 = "ababa";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "xxxxx";
	string ret1 = objectTwiceString.getShortest(param10);
	string need1 = "xxxxxx";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "topcoder";
	string ret2 = objectTwiceString.getShortest(param20);
	string need2 = "topcodertopcoder";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "abracadabra";
	string ret3 = objectTwiceString.getShortest(param30);
	string need3 = "abracadabracadabra";
	assert_eq(3,ret3,need3);

}

