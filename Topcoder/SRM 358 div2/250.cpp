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

class CyclicWords
{
public:
	int differentCW(vector <string> words)
	{
	    int i, j, k;
	    string temp1, temp2;
	    k=words.size();
        int ans = k;

	    for(i=0;i<k;i++)
	    {
	        if(words[i]=="#") continue;

	        temp1 = words[i];


	        for(j=0;j<k;j++)
	        {
	            if(i==j) continue;
                temp2 = words[j];
                if(temp2.size()==temp1.size())
                {
                   char c = temp1[0];
                   for(int p = 0;p<temp2.size();p++)
                   {
                       if(temp2[p]==c)
                       {
                           int m = p;
                           bool f = true;
                           for(int q = 0;q<temp1.size() ;q++ )
                           {
                               if(temp1[q]!=temp2[m])
                               {
                                   f=false;
                                   break;
                               }
                               m++;
                               if(m==temp1.size()) m=0;
                            }

                            if(f==true)
                            {
                                words[j]="#";
                                ans--;
                                break;
                            }
                       }
                   }
                }
	        }
	    }


	    return ans;
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

	CyclicWords objectCyclicWords;

	//test case0
	vector <string> param00;
	param00.push_back("picture");
	param00.push_back("turepic");
	param00.push_back("icturep");
	param00.push_back("word");
	param00.push_back("ordw");
	int ret0 = objectCyclicWords.differentCW(param00);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("ast");
	param10.push_back("ats");
	param10.push_back("tas");
	param10.push_back("tsa");
	param10.push_back("sat");
	param10.push_back("sta");
	param10.push_back("ttt");
	int ret1 = objectCyclicWords.differentCW(param10);
	int need1 = 3;
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("aaaa");
	param20.push_back("aaa");
	param20.push_back("aa");
	param20.push_back("aaaa");
	param20.push_back("aaaaa");
	int ret2 = objectCyclicWords.differentCW(param20);
	int need2 = 4;
	assert_eq(2,ret2,need2);

}
