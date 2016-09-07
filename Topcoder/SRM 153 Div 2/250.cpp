
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

class MostProfitable
{
public:
	string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string>items)
	{
        int k;
        string ss;
        k=costs.size();
        int a[k];
        for(int i=0;i<k;i++)
        {
            a[i]=(prices[i]-costs[i])*sales[i];
        }

        int max=-1, ans=-1;
        for(int i=0;i<k;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
                ans = i;
            }
        }
        if(max<=0)  ss="";
        else        ss=items[ans];

        return ss;
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

	MostProfitable objectMostProfitable;

	//test case0
	vector <int> param00;
	param00.push_back(100);
	param00.push_back(120);
	param00.push_back(150);
	param00.push_back(1000);
	vector <int> param01;
	param01.push_back(110);
	param01.push_back(110);
	param01.push_back(200);
	param01.push_back(2000);
	vector <int> param02;
	param02.push_back(20);
	param02.push_back(100);
	param02.push_back(50);
	param02.push_back(3);
	vector <string> param03;
	param03.push_back("Video Card");
	param03.push_back("256M Mem");
	param03.push_back("CPU/Mobo combo");
	param03.push_back("Complete machine");
	string ret0 = objectMostProfitable.bestItem(param00,param01,param02,param03);
	string need0 = "Complete machine";
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(100);
	vector <int> param11;
	param11.push_back(100);
	vector <int> param12;
	param12.push_back(134);
	vector <string> param13;
	param13.push_back("Service, at cost");
	string ret1 = objectMostProfitable.bestItem(param10,param11,param12,param13);
	string need1 = "";
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(38);
	param20.push_back(24);
	vector <int> param21;
	param21.push_back(37);
	param21.push_back(23);
	vector <int> param22;
	param22.push_back(1000);
	param22.push_back(643);
	vector <string> param23;
	param23.push_back("Letter");
	param23.push_back("Postcard");
	string ret2 = objectMostProfitable.bestItem(param20,param21,param22,param23);
	string need2 = "";
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(10);
	param30.push_back(10);
	vector <int> param31;
	param31.push_back(11);
	param31.push_back(12);
	vector <int> param32;
	param32.push_back(2);
	param32.push_back(1);
	vector <string> param33;
	param33.push_back("A");
	param33.push_back("B");
	string ret3 = objectMostProfitable.bestItem(param30,param31,param32,param33);
	string need3 = "A";
	assert_eq(3,ret3,need3);

}
