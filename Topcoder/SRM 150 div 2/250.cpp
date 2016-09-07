
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
#include<string>

using namespace std;

class WidgetRepairs
{
public:
	int days(vector <int> arrivals, int numPerDay)
	{
	    int i, k;
	    int a[10000];
	    memset(a, 0, sizeof(a));
	    k=arrivals.size();
	    int days = 0;
	    for(i=0;i<k;i++)
            a[i]=arrivals[i];

	    for(i=0; i<10000 ;i++)
	    {
            if(a[i]<=0) continue;
	        a[i]=a[i]-numPerDay;
            if(a[i]>0)
                a[i+1]+=a[i];
            days++;

        }
	    return days;
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

	WidgetRepairs objectWidgetRepairs;

	//test case0
	vector <int> param00;
	param00.push_back(10);
	param00.push_back(0);
	param00.push_back(0);
	param00.push_back(4);
	param00.push_back(20);
	int param01 = 8;
	int ret0 = objectWidgetRepairs.days(param00,param01);
	int need0 = 6;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(0);
	param10.push_back(0);
	param10.push_back(0);
	int param11 = 10;
	int ret1 = objectWidgetRepairs.days(param10,param11);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(100);
	param20.push_back(100);
	int param21 = 10;
	int ret2 = objectWidgetRepairs.days(param20,param21);
	int need2 = 20;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(27);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(0);
	param30.push_back(9);
	int param31 = 9;
	int ret3 = objectWidgetRepairs.days(param30,param31);
	int need3 = 4;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(6);
	param40.push_back(5);
	param40.push_back(4);
	param40.push_back(3);
	param40.push_back(2);
	param40.push_back(1);
	param40.push_back(0);
	param40.push_back(0);
	param40.push_back(1);
	param40.push_back(2);
	param40.push_back(3);
	param40.push_back(4);
	param40.push_back(5);
	param40.push_back(6);
	int param41 = 3;
	int ret4 = objectWidgetRepairs.days(param40,param41);
	int need4 = 15;
	assert_eq(4,ret4,need4);

}
