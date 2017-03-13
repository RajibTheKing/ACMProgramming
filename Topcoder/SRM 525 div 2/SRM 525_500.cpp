
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
int k, mm=999999999;
bool flag ;
int find(vector<string> b)
{
    int f=0;
    for(int i=0;i<b.size();i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            if(b[i][j]=='o')
                f++;
        }
    }

    return f;
}
void rec(int n, vector <string> board)
{
    int c = find(board);
    if(c<k) return;

    cout<<c<<endl;

    if(c==k)
    {
        flag=true;
        if(mm>n)
            mm=n;
    }
    vector <string> b;

    for(int i=0;i<board.size();i++)
    {
        for(int j=1;j<board[i].size();j++)
        {
            b[i][j]=board[i][j-1];
        }
        b[i][0]='.';
    }

    rec(n+1, b);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size()-1;j++)
        {
            b[i][j]=board[i][j+1];
        }

        b[i][j]='.';
    }
    rec(n+1, b);

    for(int j=0;j<board[0].size();j++)
    {
        for(int i=1;i<board.size();i++)
        {
            b[i][j]=b[i-1][j];
        }
        b[0][j]='.';
    }

    rec(n+1, b);
    for(int j=0;j<board[0].size();j++)
    {
        for(int i=0;i<board.size()-1;i++)
        {
            b[i][j]=board[i+1][j];
        }
        b[i][j]='.';
    }

    rec(n+1, b);

}
class DropCoins
{
public:
	int getMinimum(vector <string> board, int K)
	{
	    k=K;
	    flag=false;
	    rec(0, board);
        cout<<mm<<endl;

	    return mm;

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

	DropCoins objectDropCoins;

	//test case0
	vector <string> param00;
	param00.push_back(".o..");
	param00.push_back("oooo");
	param00.push_back("..o.");
	int param01 = 3;
	int ret0 = objectDropCoins.getMinimum(param00,param01);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back(".....o");
	param10.push_back("......");
	param10.push_back("oooooo");
	param10.push_back("oooooo");
	param10.push_back("......");
	param10.push_back("o.....");
	int param11 = 12;
	int ret1 = objectDropCoins.getMinimum(param10,param11);
	int need1 = 3;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("....");
	param20.push_back(".oo.");
	param20.push_back(".oo.");
	param20.push_back("....");
	int param21 = 3;
	int ret2 = objectDropCoins.getMinimum(param20,param21);
	int need2 = -1;
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back(".......");
	param30.push_back("..ooo..");
	param30.push_back("ooooooo");
	param30.push_back(".oo.oo.");
	param30.push_back("oo...oo");
	int param31 = 12;
	int ret3 = objectDropCoins.getMinimum(param30,param31);
	int need3 = 4;
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back(".................");
	param40.push_back(".ooooooo...oooo..");
	param40.push_back(".ooooooo..oooooo.");
	param40.push_back(".oo.......oo..oo.");
	param40.push_back(".oo.......oo..oo.");
	param40.push_back(".ooooo.....oooo..");
	param40.push_back(".ooooooo...oooo..");
	param40.push_back(".....ooo..oo..oo.");
	param40.push_back("......oo..oo..oo.");
	param40.push_back(".ooooooo..oooooo.");
	param40.push_back(".oooooo....oooo..");
	param40.push_back(".................");
	int param41 = 58;
	int ret4 = objectDropCoins.getMinimum(param40,param41);
	int need4 = 6;
	assert_eq(4,ret4,need4);

}
