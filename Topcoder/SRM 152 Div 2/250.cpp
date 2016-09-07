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

class FixedPointTheorem
{
public:
	double cycleRange(double R)
	{
	    double X = 0.25;
        double high, low;

	    for(int i=0;i<200000;i++)
            X=R*X*(1.0-X);



        high=0.0;low=1.0;

        for(int i=0;i<1000;i++)
        {
            X=R*X*(1.0-X);
            if(high<X) high=X;
            if(low>X) low=X;

        }

        return high-low;
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

	FixedPointTheorem objectFixedPointTheorem;

	//test case0
	double param00 = 0.1;
	double ret0 = objectFixedPointTheorem.cycleRange(param00);
	double need0 = 0.0;
	assert_eq(0,ret0,need0);

	//test case1
	double param10 = 3.05;
	double ret1 = objectFixedPointTheorem.cycleRange(param10);
	double need1 = 0.14754098360655865;
	assert_eq(1,ret1,need1);

	//test case2
	double param20 = 3.4499;
	double ret2 = objectFixedPointTheorem.cycleRange(param20);
	double need2 = 0.4175631735867292;
	assert_eq(2,ret2,need2);

	//test case3
	double param30 = 3.55;
	double ret3 = objectFixedPointTheorem.cycleRange(param30);
	double need3 = 0.5325704489850351;
	assert_eq(3,ret3,need3);

	//test case4
	double param40 = 3.565;
	double ret4 = objectFixedPointTheorem.cycleRange(param40);
	double need4 = 0.5454276003030636;
	assert_eq(4,ret4,need4);

	//test case5
	double param50 = 3.5689;
	double ret5 = objectFixedPointTheorem.cycleRange(param50);
	double need5 = 0.5489996297493569;
	assert_eq(5,ret5,need5);

	//test case6
	double param60 = 3.00005;
	double ret6 = objectFixedPointTheorem.cycleRange(param60);
	double need6 = 0.004713996108955176;
	assert_eq(6,ret6,need6);

}
