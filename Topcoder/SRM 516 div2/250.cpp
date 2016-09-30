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

class NetworkXZeroOne
{
public:
	string reconstruct(string message)
	{
	    int flag, i, n;
	    n=message.length();

	    string ans="";
	    flag=1;
	    for(i=0;i<n;i++)
            if(message[i]=='?')
                flag=0;
        if(flag)
            return message;

	    flag=1;
	    for(i=0;i<n;i++)
            if(message[i]=='x'||message[i]=='o')
                flag=0;
        if(flag==1)
        {
            ans+="o";
            for(i=1;i<n;i++)
            {
                if(ans[i-1]=='o')
                    ans+="x";
                else ans+="o";
            }
            return ans;
        }
        else
        {
            for(i=0;i<n;i++)
                if(message[i]=='x'||message[i]=='o')
                        break;

            for(int j=i-1;j>=0;j--)
                if(message[j+1]=='o')
                    message[j]='x';
                else
                    message[j]='o';
            for(int j=i+1;j<n;j++)
            {
                if(message[j-1]=='o')
                    message[j]='x';
                else
                    message[j]='o';
            }
            return message;

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

	NetworkXZeroOne objectNetworkXZeroOne;

	//test case0
	string param00 = "x?x?";
	string ret0 = objectNetworkXZeroOne.reconstruct(param00);
	string need0 = "xoxo";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "?xo?";
	string ret1 = objectNetworkXZeroOne.reconstruct(param10);
	string need1 = "oxox";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "xo";
	string ret2 = objectNetworkXZeroOne.reconstruct(param20);
	string need2 = "xo";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "o??x??o";
	string ret3 = objectNetworkXZeroOne.reconstruct(param30);
	string need3 = "oxoxoxo";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "???????x";
	string ret4 = objectNetworkXZeroOne.reconstruct(param40);
	string need4 = "oxoxoxox";
	assert_eq(4,ret4,need4);

}

