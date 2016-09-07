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

class ProfitCalculator
{
public:
	int percent(vector <string> items)
	{
	    double  xx, yy;
	    double x=0,y=0;
	    istringstream ss;
	    for(int i=0;i<items.size();i++)
	    {
	        ss.clear();
	        ss.str(items[i]);
	        ss>>xx>>yy;
	        x+=xx; y+=yy;
	    }
	   // cout<<x<<"  "<<y<<endl;
	    return int(((x-y)*100)/x);
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

	ProfitCalculator objectProfitCalculator;

	//test case0
	vector <string> param00;
	param00.push_back("012.99 008.73");
	param00.push_back("099.99 050.00");
	param00.push_back("123.45 101.07");
	int ret0 = objectProfitCalculator.percent(param00);
	int need0 = 32;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("000.00 049.99");
	param10.push_back("999.99 936.22");
	param10.push_back("033.99 025.64");
	param10.push_back("249.99 211.87");
	int ret1 = objectProfitCalculator.percent(param10);
	int need1 = 4;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("822.77 704.86");
	param20.push_back("829.42 355.45");
	param20.push_back("887.18 949.38");
	int ret2 = objectProfitCalculator.percent(param20);
	int need2 = 20;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("612.72 941.34");
	param30.push_back("576.46 182.66");
	param30.push_back("787.41 524.70");
	param30.push_back("637.96 333.23");
	param30.push_back("345.01 219.69");
	param30.push_back("567.22 104.77");
	param30.push_back("673.02 885.77");
	int ret3 = objectProfitCalculator.percent(param30);
	int need3 = 23;
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("811.22 275.32");
	param40.push_back("433.89 006.48");
	param40.push_back("141.28 967.41");
	param40.push_back("344.47 786.23");
	param40.push_back("897.47 860.61");
	param40.push_back("007.42 559.29");
	param40.push_back("255.72 460.00");
	param40.push_back("419.35 931.19");
	param40.push_back("419.25 490.52");
	param40.push_back("199.78 114.44");
	param40.push_back("505.63 276.58");
	param40.push_back("720.96 735.00");
	param40.push_back("719.90 824.46");
	param40.push_back("816.58 195.94");
	param40.push_back("498.68 453.05");
	param40.push_back("399.48 921.39");
	param40.push_back("930.88 017.63");
	param40.push_back("422.20 075.39");
	param40.push_back("380.22 917.27");
	param40.push_back("630.83 995.87");
	param40.push_back("821.07 126.87");
	param40.push_back("715.73 985.62");
	param40.push_back("246.23 134.64");
	param40.push_back("168.28 550.33");
	param40.push_back("707.28 046.72");
	param40.push_back("117.76 281.87");
	param40.push_back("595.43 410.45");
	param40.push_back("345.28 532.42");
	param40.push_back("554.24 264.34");
	param40.push_back("195.73 814.87");
	param40.push_back("131.98 041.28");
	param40.push_back("595.13 939.47");
	param40.push_back("576.04 107.70");
	param40.push_back("716.00 404.75");
	param40.push_back("524.24 029.96");
	param40.push_back("673.49 070.97");
	param40.push_back("288.09 849.43");
	param40.push_back("616.34 236.34");
	param40.push_back("401.96 316.33");
	param40.push_back("371.18 014.27");
	param40.push_back("809.63 508.33");
	param40.push_back("375.68 290.84");
	param40.push_back("334.66 477.89");
	param40.push_back("689.54 526.35");
	param40.push_back("084.77 316.51");
	param40.push_back("304.76 015.91");
	param40.push_back("460.63 636.56");
	param40.push_back("357.84 436.20");
	param40.push_back("752.24 047.64");
	param40.push_back("922.10 573.12");
	int ret4 = objectProfitCalculator.percent(param40);
	int need4 = 10;
	assert_eq(4,ret4,need4);

}
