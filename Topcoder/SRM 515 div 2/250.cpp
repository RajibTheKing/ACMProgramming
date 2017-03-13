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

class FortunateNumbers
{
public:
	int getFortunate(vector <int> a, vector <int> b, vector <int> c)
	{
	    int i, j, k, temp, count=0, u, p, t;
        bool flag[90000];
        memset(flag, 0, sizeof(flag));
	    for(i=0;i<a.size();i++)
	    {
	        for(j=0;j<b.size();j++)
	        {
	            for(k=0;k<c.size();k++)
	            {
	                temp=a[i]+b[j]+c[k];

	                if(flag[temp]==0)
	                {
	                    u=temp;
                        p=1;
                        for(;u>0 ;)
                        {
                            t=u%10;

                            if(t==5||t==8)
                            {
                                u/=10;
                                continue;
                            }
                            else
                            {
                                p=0;
                                break;
                            }
                        }
                        if(p==1)
                        {
                            count++;
                            flag[temp]=1;
                        }
	                }
	            }
	        }

	    }

	    return count;
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

	FortunateNumbers objectFortunateNumbers;

	//test case0
	vector <int> param00;
	param00.push_back(1);
	param00.push_back(10);
	param00.push_back(100);
	vector <int> param01;
	param01.push_back(3);
	param01.push_back(53);
	vector <int> param02;
	param02.push_back(4);
	param02.push_back(54);
	int ret0 = objectFortunateNumbers.getFortunate(param00,param01,param02);
	int need0 = 2;
	assert_eq(0,ret0,need0);

	//test case1
	vector <int> param10;
	param10.push_back(47);
	vector <int> param11;
	param11.push_back(500);
	vector <int> param12;
	param12.push_back(33);
	int ret1 = objectFortunateNumbers.getFortunate(param10,param11,param12);
	int need1 = 0;
	assert_eq(1,ret1,need1);

	//test case2
	vector <int> param20;
	param20.push_back(100);
	param20.push_back(1);
	param20.push_back(10);
	param20.push_back(100);
	param20.push_back(1);
	param20.push_back(1);
	vector <int> param21;
	param21.push_back(3);
	param21.push_back(53);
	param21.push_back(53);
	param21.push_back(53);
	param21.push_back(53);
	param21.push_back(53);
	param21.push_back(53);
	vector <int> param22;
	param22.push_back(4);
	param22.push_back(54);
	param22.push_back(4);
	param22.push_back(54);
	param22.push_back(4);
	param22.push_back(54);
	int ret2 = objectFortunateNumbers.getFortunate(param20,param21,param22);
	int need2 = 2;
	assert_eq(2,ret2,need2);

	//test case3
	vector <int> param30;
	param30.push_back(500);
	param30.push_back(800);
	vector <int> param31;
	param31.push_back(50);
	param31.push_back(80);
	vector <int> param32;
	param32.push_back(5);
	param32.push_back(8);
	int ret3 = objectFortunateNumbers.getFortunate(param30,param31,param32);
	int need3 = 8;
	assert_eq(3,ret3,need3);

	//test case4
	vector <int> param40;
	param40.push_back(30000);
	param40.push_back(26264);
	vector <int> param41;
	param41.push_back(30000);
	param41.push_back(29294);
	vector <int> param42;
	param42.push_back(30000);
	param42.push_back(29594);
	int ret4 = objectFortunateNumbers.getFortunate(param40,param41,param42);
	int need4 = 3;
	assert_eq(4,ret4,need4);

}

