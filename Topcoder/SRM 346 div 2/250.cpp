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

class DiamondHunt
{
public:
	int countDiamonds(string mine)
	{
	    int flag, ans = 0, p, q;

	    for(; ;)
	    {
	        flag=0;
	        for(int j=0;j<mine.length();j++)
	        {
	           if(mine[j]=='<')
                {
                    p=j;
                    flag = 1;
                }
                if(mine[j]=='>'&&flag==1)
                {
                    q=j;
                    flag=2;
                    break;
                }

	        }
	        if(flag==2)
                {
                    mine[q]=NULL;
                    mine[p]=NULL;
                    ans++;
                }
                else
                    break;
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

	DiamondHunt objectDiamondHunt;

	//test case0
	string param00 = "><<><>>><";
	int ret0 = objectDiamondHunt.countDiamonds(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = ">>>><<";
	int ret1 = objectDiamondHunt.countDiamonds(param10);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "<<<<<<<<<>>>>>>>>>";
	int ret2 = objectDiamondHunt.countDiamonds(param20);
	int need2 = 9;
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "><<><><<>>>><<>><<><<>><<<>>>>>><<<";
	int ret3 = objectDiamondHunt.countDiamonds(param30);
	int need3 = 14;
	assert_eq(3,ret3,need3);

}

