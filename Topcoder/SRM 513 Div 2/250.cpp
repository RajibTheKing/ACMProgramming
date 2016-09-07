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

class TrainingCamp
{
public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics)
	{
        int i, j, k,f;
        vector<string> ans;

        for(k=0; k<attendance.size(); k++)
        {
            string s="";


            for(i=0; i<problemTopics.size(); i++)
            {

                f=1;
                for(j=0; j<problemTopics[i].size(); j++)
                {
                    if(problemTopics[i][j]=='X'&&attendance[k][j]=='-')
                        f=0;
                }

                if(f) s=s+'X';
                else s=s+'-';


            }

            ans.push_back(s);
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

	TrainingCamp objectTrainingCamp;

	//test case0
	vector <string> param00;
	param00.push_back("XXX");
	param00.push_back("XXX");
	param00.push_back("XX-");
	vector <string> param01;
	param01.push_back("---");
	param01.push_back("XXX");
	param01.push_back("-XX");
	param01.push_back("XX-");
	vector <string> ret0 = objectTrainingCamp.determineSolvers(param00,param01);
	vector <string> need0;
	need0.push_back("XXXX");
	need0.push_back("XXXX");
	need0.push_back("X--X");
	assert_eq(0,ret0,need0);

	//test case1
	vector <string> param10;
	param10.push_back("-XXXX");
	param10.push_back("----X");
	param10.push_back("XXX--");
	param10.push_back("X-X-X");
	vector <string> param11;
	param11.push_back("X---X");
	param11.push_back("-X---");
	param11.push_back("XXX--");
	param11.push_back("--X--");
	vector <string> ret1 = objectTrainingCamp.determineSolvers(param10,param11);
	vector <string> need1;
	need1.push_back("-X-X");
	need1.push_back("----");
	need1.push_back("-XXX");
	need1.push_back("X--X");
	assert_eq(1,ret1,need1);

	//test case2
	vector <string> param20;
	param20.push_back("-----");
	param20.push_back("XXXXX");
	vector <string> param21;
	param21.push_back("XXXXX");
	param21.push_back("-----");
	param21.push_back("--X-X");
	vector <string> ret2 = objectTrainingCamp.determineSolvers(param20,param21);
	vector <string> need2;
	need2.push_back("-X-");
	need2.push_back("XXX");
	assert_eq(2,ret2,need2);

	//test case3
	vector <string> param30;
	param30.push_back("-");
	param30.push_back("X");
	param30.push_back("X");
	param30.push_back("-");
	param30.push_back("X");
	vector <string> param31;
	param31.push_back("-");
	param31.push_back("X");
	vector <string> ret3 = objectTrainingCamp.determineSolvers(param30,param31);
	vector <string> need3;
	need3.push_back("X-");
	need3.push_back("XX");
	need3.push_back("XX");
	need3.push_back("X-");
	need3.push_back("XX");
	assert_eq(3,ret3,need3);

	//test case4
	vector <string> param40;
	param40.push_back("X----X--X");
	param40.push_back("X--X-X---");
	param40.push_back("--X-X----");
	param40.push_back("XXXX-X-X-");
	param40.push_back("XXXX--XXX");
	vector <string> param41;
	param41.push_back("X----X-X-");
	param41.push_back("-----X---");
	param41.push_back("-X----X-X");
	param41.push_back("-X-X-X---");
	param41.push_back("-----X---");
	param41.push_back("X-------X");
	vector <string> ret4 = objectTrainingCamp.determineSolvers(param40,param41);
	vector <string> need4;
	need4.push_back("-X--XX");
	need4.push_back("-X--X-");
	need4.push_back("------");
	need4.push_back("XX-XX-");
	need4.push_back("--X--X");
	assert_eq(4,ret4,need4);

}
