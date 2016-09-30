
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

class RainyRoad
{
public:
	string isReachable(vector <string> road)
	{
	    int x=0, y=0;
	    int i, j, k;
	    i=road.size();
	    j=road[0].size();
	    if(road[0][j-1]=='W') return "NO";

	    while(1)
	    {
	        if(x==0&&y==j-1)
                return "YES";

            if(x==0)
            {
                if(road[x][y+1]=='.')
                {
                    y++;
                    continue;
                }
                if(road[x+1][y+1]=='.')
                {
                    x++;
                    y++;
                    continue;
                }
            }
            if(x==1)
            {
                if(road[x-1][y+1]=='.')
                {
                    x--;
                    y++;
                    continue;
                }
                if(road[x][y+1]=='.')
                {
                    y++;
                    continue;
                }


            }
            return "NO";

	    }
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

	RainyRoad objectRainyRoad;

	//test case0
	vector <string> param00;
	param00.push_back(".W..");
	param00.push_back("....");
	string ret0 = objectRainyRoad.isReachable(param00);
	string need0 = "YES";
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back(".W..");
	param10.push_back("..W.");
	string ret1 = objectRainyRoad.isReachable(param10);
	string need1 = "YES";
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back(".W..W..");
	param20.push_back("...WWW.");
	string ret2 = objectRainyRoad.isReachable(param20);
	string need2 = "NO";
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("..");
	param30.push_back("WW");
	string ret3 = objectRainyRoad.isReachable(param30);
	string need3 = "YES";
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back(".WWWW.");
	param40.push_back("WWWWWW");
	string ret4 = objectRainyRoad.isReachable(param40);
	string need4 = "NO";
	assert_eq(4,ret4,need4);

	//test case5
	vector <string> param50;
	param50.push_back(".W.W.W.");
	param50.push_back("W.W.W.W");
	string ret5 = objectRainyRoad.isReachable(param50);
	string need5 = "YES";
	assert_eq(5,ret5,need5);

	//test case6
	vector <string> param60;
	param60.push_back(".............................................W.");
	param60.push_back(".............................................W.");
	string ret6 = objectRainyRoad.isReachable(param60);
	string need6 = "NO";
	assert_eq(6,ret6,need6);

}
