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

class GameOfLifeDivTwo
{
public:
	string theSimulation(string init, int T)
	{
	    string a;
	    a=init;
	    int k, i, m, n, t;
	    k=init.length();

	    while(T--)
	    {
	        for(i=0;i<k;i++)
            {

                t=0;
                if(i==0)
                {
                    m=k-1;
                    n=i+1;
                }
                else if(i==k-1)
                {
                    m=i-1;
                    n=0;
                }
                else
                {
                    m=i-1;
                    n=i+1;
                }


                if(init[m]=='1')  t++;
                if(init[i]=='1')  t++;
                if(init[n]=='1') t++;


                if(t>=2) a[i]='1';
                else a[i]='0';
            }
            init = a;
        }
        return init;
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

	GameOfLifeDivTwo objectGameOfLifeDivTwo;

	//test case0
	string param00 = "01010";
	int param01 = 2;
	string ret0 = objectGameOfLifeDivTwo.theSimulation(param00,param01);
	string need0 = "00000";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "010101";
	int param11 = 5;
	string ret1 = objectGameOfLifeDivTwo.theSimulation(param10,param11);
	string need1 = "101010";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "111010";
	int param21 = 58;
	string ret2 = objectGameOfLifeDivTwo.theSimulation(param20,param21);
	string need2 = "111111";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "111111111";
	int param31 = 511;
	string ret3 = objectGameOfLifeDivTwo.theSimulation(param30,param31);
	string need3 = "111111111";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "110010000010111110010100001001";
	int param41 = 1000;
	string ret4 = objectGameOfLifeDivTwo.theSimulation(param40,param41);
	string need4 = "110000000001111110000000000001";
	assert_eq(4,ret4,need4);

	//test case5
	string param50 = "00101110011";
	int param51 = 0;
	string ret5 = objectGameOfLifeDivTwo.theSimulation(param50,param51);
	string need5 = "00101110011";
	assert_eq(5,ret5,need5);

}

