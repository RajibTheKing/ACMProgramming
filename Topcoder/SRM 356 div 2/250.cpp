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

class SMSLanguage
{
public:
	string translate(string t)
	{

	    string a;
	    a.clear();
	    int l=t.length();
	    t+="rrr";
        int i;
        for(i=0;i<l;i++)
            if(t[i]>='A'&&t[i]<='Z')
                t[i]+=32;
        for(i=0;i<l;i++)
        {




            if(t[i]=='.'||t[i]==','||t[i]=='?'||t[i]=='!')
                continue;


            if(t[i]=='a'&&t[i+1]=='n'&&t[i+2]=='d')
            {
                a+='&';
                i+=2;
                continue;
            }
            else if(t[i]=='a'&& t[i+1]=='t'&& t[i+2]=='e')
            {

                a+='8';
                i+=2;
                continue;
            }
            else if(t[i]=='a'&&t[i+1]=='t')
            {
                a+='@';
                i+=1;
                continue;
            }
            else if(t[i]=='y'&&t[i+1]=='o'&&t[i+2]=='u')
            {
                a+='U';
                i+=2;
                continue;
            }
            else
                a+=t[i];
        }


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

	SMSLanguage objectSMSLanguage;

	//test case0
	string param00 = "I HATE rats, and you?";
	string ret0 = objectSMSLanguage.translate(param00);
	string need0 = "i h8 r@s & U";
	assert_eq(0,ret0,need0);

	//test case1
	string param10 = "What is the weather like today?";
	string ret1 = objectSMSLanguage.translate(param10);
	string need1 = "wh@ is the we@her like today";
	assert_eq(1,ret1,need1);

	//test case2
	string param20 = "It is not too late to..";
	string ret2 = objectSMSLanguage.translate(param20);
	string need2 = "it is not too l8 to";
	assert_eq(2,ret2,need2);

	//test case3
	string param30 = "this text is already in sms language";
	string ret3 = objectSMSLanguage.translate(param30);
	string need3 = "this text is already in sms language";
	assert_eq(3,ret3,need3);

}

