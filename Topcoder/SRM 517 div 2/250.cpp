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

class MonochromaticBoard
{
public:
	int theMin(vector <string> board)
	{
	    int n, m, i, j;
	    n=board.size();
	    m=board[0].size();
	    int flag, row, column;

	    flag=1; // all is black
	    for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(board[i][j]=='W')
                    flag=0;

        if(flag==1)
        {
            if(n<m) return n;
            else return m;
        }

        flag=1; // all is White
	    for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(board[i][j]=='B')
                    flag=0;

        if(flag) return 0;

        row = 0;
        column = 0;
        for(i=0;i<n;i++)
        {
            flag=0;

            for(j=0;j<m;j++)
                if(board[i][j]=='B')
                    flag++;
            if(flag==m)
                row++;
        }

        for(j=0;j<m;j++)
        {
            flag=0;

            for(i=0;i<n;i++)
                if(board[i][j]=='B')
                    flag++;
            if(flag==n)
                column++;
        }

        return column+row;


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

	MonochromaticBoard objectMonochromaticBoard;

	//test case0
	vector <string> param00;
	param00.push_back("WBWBW");
	param00.push_back("BBBBB");
	param00.push_back("WBWBW");
	param00.push_back("WBWBW");
	int ret0 = objectMonochromaticBoard.theMin(param00);
	int need0 = 3;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("BBBB");
	param10.push_back("BBBB");
	param10.push_back("BBBB");
	int ret1 = objectMonochromaticBoard.theMin(param10);
	int need1 = 3;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("BBBBB");
	param20.push_back("BBBBB");
	param20.push_back("BBBBB");
	param20.push_back("BBBBB");
	param20.push_back("BBBBB");
	param20.push_back("BBBBB");
	param20.push_back("BBBBB");
	param20.push_back("BBBBB");
	int ret2 = objectMonochromaticBoard.theMin(param20);
	int need2 = 5;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("WW");
	param30.push_back("WW");
	int ret3 = objectMonochromaticBoard.theMin(param30);
	int need3 = 0;
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("BBBBBBBB");
	param40.push_back("BBBBBBBB");
	param40.push_back("BBBBBBBB");
	param40.push_back("WBWBBBWB");
	param40.push_back("BBBBBBBB");
	int ret4 = objectMonochromaticBoard.theMin(param40);
	int need4 = 9;
	assert_eq(4,ret4,need4);

}

