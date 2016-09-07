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

class YahtzeeScore
{
public:
	int maxPoints(vector <int> toss)
	{
	    int k, sum;
	    k=toss.size();
        int max=0;
        for(int i=0;i<k;i++)
        {
            sum=0;
            for(int j=0;j<k;j++)
                if(toss[j]==toss[i])
                    sum+=toss[j];
            if(max<sum)
                max=sum;
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

	YahtzeeScore objectYahtzeeScore;

	//test case0
	vector <int> param00;
	param00.push_back(2);
	param00.push_back(2);
	param00.push_back(3);
	param00.push_back(5);
	param00.push_back(4);
	int ret0 = objectYahtzeeScore.maxPoints(param00);
	int need0 = 5;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(6);
	param10.push_back(4);
	param10.push_back(1);
	param10.push_back(1);
	param10.push_back(3);
	int ret1 = objectYahtzeeScore.maxPoints(param10);
	int need1 = 6;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(5);
	param20.push_back(3);
	param20.push_back(5);
	param20.push_back(3);
	param20.push_back(3);
	int ret2 = objectYahtzeeScore.maxPoints(param20);
	int need2 = 10;
	assert_eq(2,ret2,need2);

}
