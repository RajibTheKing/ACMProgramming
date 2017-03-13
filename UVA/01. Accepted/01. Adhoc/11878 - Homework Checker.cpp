#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <clocale>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)


map<string, int> mp;



int main()
{
    int a, b, c, sgnIndex, eqlIndex, kount=0;
    stringstream ss;

    //freopen("input.txt", "r", stdin);
    string str, s1, s2, s3;
    char sgn;

    while(cin>>str)
    {
        if(str[str.size()-1]=='?')
        {
            continue;
        }
        s1="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='+'||str[i]=='-')
            {
                sgnIndex=i;
                break;
            }
            s1+=str[i];
        }
        ss.clear();
        ss<<s1;
        ss>>a;

        s2="";
        for(int i=sgnIndex+1;i<str.size();i++)
        {
            if(str[i]=='=')
            {
                eqlIndex=i;
                break;
            }
            s2+=str[i];
        }
        ss.clear();
        ss<<s2;
        ss>>b;

        s3="";
        for(int i=eqlIndex+1;i<str.size();i++)
        {
            s3+=str[i];
        }
        ss.clear();
        ss<<s3;
        ss>>c;
        //cout<<"Here: "<<a<<" "<<b<<" "<<c<<endl;
        if(str[sgnIndex]=='+')
        {
            if(a+b==c)
                kount++;
        }
        else
        {
            if(a-b==c)
                kount++;
        }


    }
    cout<<kount<<endl;



    return 0;
}
