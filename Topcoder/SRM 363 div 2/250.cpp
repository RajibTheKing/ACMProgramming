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

typedef struct node
{
    int h;
    int m;
};

node a[750], b[750];
class MirroredClock
{
public:
	string whatTimeIsIt(string time)
	{
	    istringstream ss;
	    ss.clear();
	    ss.str(time);
	    char c;
	    int p, q;
	    int k=0;
	    int h1=0, h2=12, m1=0, m2=0;
	    ss>>p>>c>>q;

	    a[0].h=0;a[0].m=0;
	    b[0].h=0;b[0].m=0;

	    for(; ;)
	    {

	        m1++;
	        if(m1==60)
	        {
	            h1++;
	            m1=0;
	        }
	        a[++k].h=h1;
	        a[k].m = m1;

	        m2--;
	        if(m2==-1)
	        {
	            h2--;
	            m2=59;
	        }

	        b[k].h=h2;
	        b[k].m=m2;

	        if(b[k].h==6&&b[k].m==0)
                break;

            //printf("%d: %d      %d: %d\n", a[k].h, a[k].m, b[k].h, b[k].m);
        }

        string s="";



        for(int i=0;i<=k;i++)
        {
            if(a[i].h==p&&a[i].m==q)
            {
               p=b[i].h;
               q=b[i].m;
               break;

            }

            if(b[i].h==p&&b[i].m==q)
            {
               p=a[i].h;
               q=a[i].m;
               break;

            }
        }

        char d;
        if(p<10)
        {
            c='0';
            d=p+'0';
            s+=c;
            s+=d;
        }
        else
        {
            d=p%10+'0';
            p/=10;
            c=p+'0';
            s+=c;
            s+=d;
        }
        s+=':';

        if(q<10)
        {
            c='0';
            d=q+'0';

            s+=c;
            s+=d;
        }
        else
        {
            d=q%10+'0';
            q/=10;
            c=q+'0';
            s+=c;
            s+=d;
        }

        return s;
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

	MirroredClock objectMirroredClock;

	//test case0
	string param00 = "10:00";
	string ret0 = objectMirroredClock.whatTimeIsIt(param00);
	string need0 = "02:00";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "01:15";
	string ret1 = objectMirroredClock.whatTimeIsIt(param10);
	string need1 = "10:45";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "03:40";
	string ret2 = objectMirroredClock.whatTimeIsIt(param20);
	string need2 = "08:20";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "00:00";
	string ret3 = objectMirroredClock.whatTimeIsIt(param30);
	string need3 = "00:00";
	assert_eq(3,ret3,need3);

	//test case4
	string param40 = "11:53";
	string ret4 = objectMirroredClock.whatTimeIsIt(param40);
	string need4 = "00:07";
	assert_eq(4,ret4,need4);

}
