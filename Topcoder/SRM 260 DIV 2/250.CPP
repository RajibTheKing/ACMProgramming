
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

class IsingModel
{
public:
	int energy(vector <string> s)
	{
	    int l, n, i, j;
	    int a=0;
	    char c, d;
	    l=s[0].length();
	    n=s.size();

	    for(j=0;j<n;j++)
	    {
	        for(i=0;i<l-1;i++)
            {

                c=s[j][i];
                d=s[j][i+1];

                if(c=='+'&&d=='-')
                        a+=1;
                else if(c=='-'&&d=='+')
                     a+=1;
                else a+=-1;
            }
        }
        for(j=0;j<n-1;j++)
	    {
	        for(i=0;i<l;i++)
            {

                c=s[j][i];
                d=s[j+1][i];

                if(c=='+'&&d=='-')
                        a+=1;
                else if(c=='-'&&d=='+')
                     a+=1;
                else a+=-1;
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

	IsingModel objectIsingModel;

	//test case0
	vector <string> param00;
	param00.push_back("-++");
	param00.push_back("+-+");
	int ret0 = objectIsingModel.energy(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("+");
	int ret1 = objectIsingModel.energy(param10);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("++-+");
	param20.push_back("-++-");
	param20.push_back("+-+-");
	param20.push_back("++++");
	int ret2 = objectIsingModel.energy(param20);
	int need2 = 4;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("----");
	param30.push_back("---+");
	param30.push_back("-+++");
	param30.push_back("++++");
	int ret3 = objectIsingModel.energy(param30);
	int need3 = -12;
	assert_eq(3,ret3,need3);

}
