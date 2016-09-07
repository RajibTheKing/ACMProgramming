
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

class DietPlan
{
public:
	string chooseDinner(string d, string b, string l)
	{

	    int a[300];
	    memset(a, 0, sizeof(a));
	    int i, t;
	    cout<<d.length();
	    for(i=0;i<d.length();i++)
        {
            t=d[i];

            a[t]++;
        }

        for(i=0;i<b.length();i++)
        {
            t=b[i];
            a[t]--;

        }
        for(i=0;i<l.length();i++)
        {
            t=l[i];
            a[t]--;
        }
        int flag=0;
        for(i=0;i<200;i++)
        {
            if(a[i]<0)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            return "CHEATER";
        char c;
        string s="";
        for(i=0;i<200;i++)
        {
            if(a[i]>0)
            {
                c=i;
                s+=c;
            }
        }
        return s;

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

	DietPlan objectDietPlan;

	//test case0
	string param00 = "ABCD";
	string param01 = "AB";
	string param02 = "C";
	string ret0 = objectDietPlan.chooseDinner(param00,param01,param02);
	string need0 = "D";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "ABEDCS";
	string param11 = "";
	string param12 = "";
	string ret1 = objectDietPlan.chooseDinner(param10,param11,param12);
	string need1 = "ABCDES";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "EDSMB";
	string param21 = "MSD";
	string param22 = "A";
	string ret2 = objectDietPlan.chooseDinner(param20,param21,param22);
	string need2 = "CHEATER";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "";
	string param31 = "";
	string param32 = "";
	string ret3 = objectDietPlan.chooseDinner(param30,param31,param32);
	string need3 = "";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "IWANTSODER";
	string param41 = "SOW";
	string param42 = "RAT";
	string ret4 = objectDietPlan.chooseDinner(param40,param41,param42);
	string need4 = "DEIN";
	assert_eq(4,ret4,need4);

}
