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

class AlphabetPath
{
public:
	string doesItExist(vector <string> M)
	{

	    int k=66, x, y, h=1;

	    char c='B';
	    int i, j;
	    for(i=0;i<M.size();i++)
	    {
	        for(j=0;j<M[i].size();j++)
	        {

	            if(M[i][j]=='A')
                {
                    x=i;
                    y=j;
                    break;
                }
	        }

	    }


	    while(h<26)
	    {


	        if(x+1 < M.size()&& M[x+1][y]==k )
	        {
                h++;
	            k++;
	            x=x+1;
	            continue;
	        }

            if(x-1>=0 && M[x-1][y]==k)
	        {
	           // c++;
	            h++;
	            k++;
	            x=x-1;
	            continue;
	        }

	        if(y-1>=0 && M[x][y-1]==k)
	        {
	            //c++;
	            h++;
	            k++;
	            y=y-1;
	            continue;
	        }

            if(y+1<M[x].size() && M[x][y+1]==k)
	        {
	           //c++;
	            h++;
	            k++;
	            y=y+1;
	            continue;
	        }

            break;
        }

	    if(h==26) return "YES";
	    else    return "NO";
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

	AlphabetPath objectAlphabetPath;

	//test case0
	vector <string> param00;
	param00.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string ret0 = objectAlphabetPath.doesItExist(param00);
	string need0 = "YES";
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("ADEHI..Z");
	param10.push_back("BCFGJK.Y");
	param10.push_back(".PONML.X");
	param10.push_back(".QRSTUVW");
	string ret1 = objectAlphabetPath.doesItExist(param10);
	string need1 = "YES";
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("ACBDEFGHIJKLMNOPQRSTUVWXYZ");
	string ret2 = objectAlphabetPath.doesItExist(param20);
	string need2 = "NO";
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("ABC.......");
	param30.push_back("...DEFGHIJ");
	param30.push_back("TSRQPONMLK");
	param30.push_back("UVWXYZ....");
	string ret3 = objectAlphabetPath.doesItExist(param30);
	string need3 = "NO";
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("..............");
	param40.push_back("..............");
	param40.push_back("..............");
	param40.push_back("...DEFGHIJK...");
	param40.push_back("...C......L...");
	param40.push_back("...B......M...");
	param40.push_back("...A......N...");
	param40.push_back("..........O...");
	param40.push_back("..ZY..TSRQP...");
	param40.push_back("...XWVU.......");
	param40.push_back("..............");
	string ret4 = objectAlphabetPath.doesItExist(param40);
	string need4 = "YES";
	assert_eq(4,ret4,need4);

}

