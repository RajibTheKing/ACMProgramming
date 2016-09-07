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

class PrefixCode
{
public:
	string isOne(vector <string> words)
	{
	    string a="";
	    string t;
	    int flag=1;
	    int k = words.size();
	    if(k==1)
	    {
	        a+="Yes";
	        return a;
	    }
	    int i, j;
	    for(i=0;i<k;i++)
	    {

	        for(j=0;j<k;j++)
	        {
	            if(i==j) continue;
	            flag=1;
	            for(int l=0;l<words[j].size();l++)
	            {
	                if(words[j][l]!=words[i][l])
	                {
	                    flag=0;
	                    break;
	                }

	            }
	            if(flag==1)
	            {
	                a+="No, ";
	                if(words[j].size()<words[i].size())
                        a+=j+'0';
                    else
                        a+=i+'0';
                    return a;
	            }

	        }

	    }
	    a+="Yes";
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

	PrefixCode objectPrefixCode;

	//test case0
	vector <string> param00;
	param00.push_back("trivial");
	string ret0 = objectPrefixCode.isOne(param00);
	string need0 = "Yes";
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("10001");
	param10.push_back("011");
	param10.push_back("100");
	param10.push_back("001");
	param10.push_back("10");
	string ret1 = objectPrefixCode.isOne(param10);
	string need1 = "No, 2";
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("no");
	param20.push_back("nosy");
	param20.push_back("neighbors");
	param20.push_back("needed");
	string ret2 = objectPrefixCode.isOne(param20);
	string need2 = "No, 0";
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("1010");
	param30.push_back("11");
	param30.push_back("100");
	param30.push_back("0");
	param30.push_back("1011");
	string ret3 = objectPrefixCode.isOne(param30);
	string need3 = "Yes";
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("No");
	param40.push_back("not");
	string ret4 = objectPrefixCode.isOne(param40);
	string need4 = "Yes";
	assert_eq(4,ret4,need4);

}
