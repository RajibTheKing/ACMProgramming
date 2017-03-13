#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<pair<int,PII> > VIII;

#define pb push_back
#define mp make_pair
#define sz size()
#define ALL(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a),_b(b); i<_b; ++i)
#define RFOR(i,a,b) for(int i=(a)-1,_b(b); i>=_b; --i)
#define CLR(a,v) memset((a),(v),sizeof(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) ((a)<(0)?-(a):(a))
#define HAS(x,k) ((x).find(k)!=(x).end())
#define FILL(a, b) CLR(a, b)

#define PREV(x) ((x)&((x)-1))
#define NEXT(x) (((x)<<1) - PREV(x))

string next(string a)
{
        int p=a.sz-1;
        while(a[p]=='Z')
        {
                --p;
                if (p==-1) return string(a.sz+1,'A');
        }
        a[p]++;
        FOR(i,p+1,a.sz) a[i]='A';
        return a;
}

string getAB(int v)
{
        string ret;
        while(v)
        {
                --v;
                ret+='A'+(v%26), v/=26;
        }
        reverse(ALL(ret));
        return ret;
}
int getnum(string S)
{
        int r=0;
        FOR(i,0,S.sz) {r*=26; r+=S[i]-'A'+1;}
        return r;
}

char ch[1<<20];

string gs()
{
    scanf("%s",ch);
    return string(ch);
}

int main()
{
        //freopen("in.txt","r",stdin);
        //freopen("p5.in","r",stdin);
        //freopen("out.txt","w",stdout);

        //string xx="A";
        //FOR(i,1,1000)printf("%3d  %s\n",i,xx.c_str()),xx=next(xx);return 0;

        int n=0;
        scanf("%d",&n);
        while(n--)
        {
                string s=gs();

                string s1,s2;
                int p=0;
                while(!isdigit(s[p]))
                    s1+=s[p++];

                while(p<s.sz && isdigit(s[p]))
                    s2+=s[p++];

                if (p!=s.sz)
                {
                        string s3,s4;
                        while(!isdigit(s[p])) s3+=s[p++];
                        while(p<s.sz && isdigit(s[p])) s4+=s[p++];
                        int x,y;
                        istringstream iss1(s4); iss1>>x;
                        istringstream iss2(s2); iss2>>y;

                        printf("%s%d\n",getAB(x).c_str(),y);
                }
                else
                {
                        int x,y=getnum(s1);
                        istringstream iss1(s2); iss1>>x;
                        printf("R%dC%d\n",x,y);
                }
        }


        return 0;
}
