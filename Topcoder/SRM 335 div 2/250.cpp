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

class Palindromize
{
public:
	string minAdds(string s)
	{
	    string ans="", temp1, temp2, t;
	    string a[100];
	    int i, j, k;
	    k=-1;

	    for(i=0;i<s.length();i++)
	    {
	        a[i].clear();
	        for(j=i;j>=0;j--)
	        {
	            a[i]+=s[j];
	        }

        }

	    temp1=s;
	    temp2="";
	    for(int u=0;u<s.length();u++)
	    {

	        temp2.clear();
	        for(i=temp1.length()-1;i>=0;i--)
                temp2+=temp1[i];

            if(temp2==temp1) break;

            temp1.clear();
            temp1=s+a[u];


        }
        return temp2;


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

	Palindromize objectPalindromize;

	//test case0
	string param00 = "add";
	string ret0 = objectPalindromize.minAdds(param00);
	string need0 = "adda";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "cigartragic";
	string ret1 = objectPalindromize.minAdds(param10);
	string need1 = "cigartragic";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "redocpot";
	string ret2 = objectPalindromize.minAdds(param20);
	string need2 = "redocpotopcoder";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "acaba";
	string ret3 = objectPalindromize.minAdds(param30);
	string need3 = "acabaca";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "abczyxyz";
	string ret4 = objectPalindromize.minAdds(param40);
	string need4 = "abczyxyzcba";
	assert_eq(4,ret4,need4);

}
