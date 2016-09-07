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

class FormatAmt
{
public:
	string amount(int dollars, int cents)
	{

	    string a="", p="", q="", r="";
	    a+='$';
	    if(dollars<=0) a+='0';
	    int i, j, k;
	    char c, d;
	    q+='.';
	    if(cents<10) q+='0';
	    k=cents%10; c=k+'0'; cents=cents/10;
	    if(cents!=0)
        {k=cents%10; d=k+'0'; q+=d;}
        q+=c;
        j=0;
        for(;dollars>0;)
        {
            k=dollars%10;
            c=k+'0';
            j++;
            if(j==4)
            {
                j=1;
                p+=',';
            }
            p+=c;

            dollars=dollars/10;
        }
        r=q;
        q=p;
        j=-1;
        for(i=p.length()-1;i>=0;i--)
            q[++j]=p[i];

        a+=q;
        a+=r;
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

	FormatAmt objectFormatAmt;

	//test case0
	int param00 = 123456;
	int param01 = 0;
	string ret0 = objectFormatAmt.amount(param00,param01);
	string need0 = "$123,456.00";
	assert_eq(0,ret0,need0);

	//test case1
	int param10 = 49734321;
	int param11 = 9;
	string ret1 = objectFormatAmt.amount(param10,param11);
	string need1 = "$49,734,321.09";
	assert_eq(1,ret1,need1);

	//test case2
	int param20 = 0;
	int param21 = 99;
	string ret2 = objectFormatAmt.amount(param20,param21);
	string need2 = "$0.99";
	assert_eq(2,ret2,need2);

	//test case3
	int param30 = 249;
	int param31 = 30;
	string ret3 = objectFormatAmt.amount(param30,param31);
	string need3 = "$249.30";
	assert_eq(3,ret3,need3);

	//test case4
	int param40 = 1000;
	int param41 = 1;
	string ret4 = objectFormatAmt.amount(param40,param41);
	string need4 = "$1,000.01";
	assert_eq(4,ret4,need4);

}
