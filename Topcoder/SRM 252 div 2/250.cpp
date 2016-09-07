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

class WarCry
{
public:
	int alertTime(string outposts)
	{
	    int a[100];
	    int min1, min2, k=-1, count;
	    for(int i=0;i<outposts.length();i++)
	    {
	        if(outposts[i]=='x')
	        {
	            a[++k]=0;

	            continue;
	        }
	        min1=999;min2=999;
	        count=0;
	        for(int j=i;;j++)
	        {
	            if(j==outposts.length())
	            {
	                count=999;
	                break;
	            }
	            if(outposts[j]=='x') break;
	            count++;
	        }
	        min1=count;
	        count=0;
	        for(int j=i;;j--)
	        {
	            if(j<0)
	            {
	                count=999;
	                break;
	            }
	            if(outposts[j]=='x') break;

	            count++;
	        }
	        min2=count;
	        if(min1>min2) a[++k]=min2;
	        else    a[++k]=min1;


	    }
	    int max=0;
	    for(int i=0;i<outposts.length();i++)
        {
            if(a[i]>max)
                max=a[i];
        }
        return max;
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

	WarCry objectWarCry;

	//test case0
	string param00 = "-x---x-";
	int ret0 = objectWarCry.alertTime(param00);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "xx--xx";
	int ret1 = objectWarCry.alertTime(param10);
	int need1 = 1;
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "xx----xx";
	int ret2 = objectWarCry.alertTime(param20);
	int need2 = 2;
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "xx-------xx";
	int ret3 = objectWarCry.alertTime(param30);
	int need3 = 4;
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	int ret4 = objectWarCry.alertTime(param40);
	int need4 = 0;
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "x------------------------------------------------x";
	int ret5 = objectWarCry.alertTime(param50);
	int need5 = 24;
	assert_eq(5,ret5,need5);

	//test case6
	string param60 = "--x----x----x--";
	int ret6 = objectWarCry.alertTime(param60);
	int need6 = 2;
	assert_eq(6,ret6,need6);

	//test case7
	string param70 = "x";
	int ret7 = objectWarCry.alertTime(param70);
	int need7 = 0;
	assert_eq(7,ret7,need7);

}
