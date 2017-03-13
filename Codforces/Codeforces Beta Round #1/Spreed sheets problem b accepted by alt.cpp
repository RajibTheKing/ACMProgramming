//* Problem  :
//* Date     : 2010.02.19
//* Author   : alt
//* Tags     :

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <string>
#include <vector>
#include <cctype>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

//stack
//#pragma comment(linker, "/STACK:16777216")

// to disable Visual C++ secure warnings
#pragma warning(disable : 4996)

///BEGIN CUT HERE
// types
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int,int> PII;
typedef vector <int> VI;
typedef vector <int64> VI64;
typedef vector <string> VS;
typedef vector <vector<string> > VVS;
typedef vector <vector<int> > VVI;
typedef vector <pair<int,int> > VPII;
typedef vector <vector<pair<int,int> > > VVPII;
typedef map<int, int > MII;
typedef map<string, int > MSI;
typedef queue<int > QI;
typedef queue<PII > QPII;
//loops
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define FORR(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define FORE(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FORER(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define FORSZ(i, a) FOR(i, SZ(a))
#define FORSZR(i, a) FORR(SZ(a), i)
#define FORO(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define FOROR(i, x) for (typeof((x).end()) i = (x).end(); i != (x).begin(); i--)
#define REP(n) for (int _foo = (int)(n) - 1; _foo >= 0; _foo--)
#define REP2(n) for (int _foo2 = (int)(n) - 1; _foo2 >= 0; _foo2--)

#define VAR(a, b) typeof(b) a=(b)
#define FOREACH(it, c) for(VAR(it,(c).begin()); it!=(c).end(); it++)
//sorting & c
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define RSORT(a) sort(RALL(a))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define REVERSE(a) reverse(ALL(a))
//filling
#define FLA(a,val) memset(a, val, sizeof(a))
#define FLO(o,val) memset(&o, val, sizeof(o))
#define CLA(a) FLA(a, 0)
#define CLO(a) FLO(a, 0)
//misc
#define _x first
#define _y second
#define MP make_pair
#define PB push_back
#define SZ(a) (int)a.size()
#define POP(a) a.top(), a.pop()
#define FRONT(a) a.front(), a.pop()
//const
const int INF = 1000000000;
const int64 INFL = 1000000000000000000LL;
const double PI = acos(-1.0);
const double EPS = 1E-9;

const int dx4[] = {-1, 1, 0, 0};
const int dy4[] = {0, 0, -1, 1};
const int dx8[] = {-1, 1, 0, 0, -1, -1,  1, 1};
const int dy8[] = {0, 0, -1, 1, -1,   1, -1, 1};

//some math
template <typename T> inline T gcd(T a, T b)                { return b ? gcd(b, a % b) : a; }
template <typename T> inline T gcd2(T a, T b)               { while (a && b) (a > b) ? a %= b : b %= a; return a + b;}
template <typename T> inline T lcm(T a, T b)                { return a / gcd(a, b) * b; }
template <typename T> inline T abs(T a)                 { return a < 0 ? -a : a; }
template <typename T> inline T sqr(T a)                 { return a * a; }
template <typename T> inline double hypot(T a, T b)     { return sqrt(1.0 * a * a + b * b);}
//template <typename T> inline double hypot(T a, T b, T с)  { return sqrt(1.0 * a * a + b * b + с * с);}
template <typename T> inline T hypot2(T a, T b)         { return a * a + b * b;}
//template <typename T> inline T hypot2(T a, T b, T c)      { return a * a + b * b + c * c;}
template <typename T> inline void chMin(T& a, T b) { if (b < a) a = b; }
template <typename T> inline void chMax(T& a, T b) { if (b > a) a = b; }

//assertions
#ifdef _DEBUG
#define ASSERT(f) if (!(f)) printf("%s\n", "ASSERTION FAILED!");
#define ASSERTS(f, s) if (!(f)) printf("%s [%s]\n", "ASSERTION FAILED!", s);
#else
#define ASSERT(f) f
#define ASSERTS(f, s) f
#endif

int cmp_int(const void *a, const void *b){return *(int*)a - *(int*)b;}
int cmp_double(const void *a, const void *b){double t = *(double*)a - *(double*)b;return (fabs(t) < EPS) ? 0 : t > 0 ? 1 : -1;}
int cmp_int64(const void *a, const void *b){int64 t = *(int64*)a - *(int64*)b; return !t ? 0 : t > 0 ? 1 : -1;}

//input
inline void ri(int &tt){ASSERTS(scanf("%d", &tt) == 1, "ReadInt failed");}
inline int ri(){int tt; ASSERTS(scanf("%d", &tt) == 1, "ReadInt failed"); return tt;}
inline void ri64(int64 &tt){ASSERTS(scanf("%lld", &tt) == 1, "ReadInt64 failed");}
inline int64 ri64(){int64 tt; ASSERTS(scanf("%lld", &tt) == 1, "ReadInt64 failed"); return tt;}
inline void rd(double &tt){ASSERTS(scanf("%lf", &tt) == 1, "ReadDouble failed"); }
inline double rd(){double tt; ASSERTS(scanf("%lf", &tt) == 1, "ReadDouble failed"); return tt;}
inline void rs(char *s){ASSERTS(scanf("%s", s) == 1, "ReadChar* failed");}
//output
inline void pvi(int *a, int n){FOR(i, n) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');}
inline void pvi(VI a){FORSZ(i,a) printf("%d%c", a[i], i == a.size() - 1 ? '\n' : ' ');}
inline void pi(int n){printf("%d\n", n);}
inline void pi64(int64 n){printf("%lld\n", n);}

inline void _pi64(int64 n)
{
    if (n < 0) {putchar('-'); n = -n;}
    if (!n) {putchar('0'); return;}
    char stack[30]; int istack = 0;
    while (n)
    {
        stack[istack++] = (n % 10) + '0'; n /= 10;
    }
    while (istack > 0)
        putchar(stack[--istack]);
}

///END CUT HERE

int64 n, res, m, a;

char t[64];

void solve()
{
}

char s[10000];

string to_str(int n)
{
    string r;
    int len = 1, p26 = 26;
    while (n > p26)
    {
        n -= p26;
        p26 *= 26;
        len++;
    }
    n--;
    while (len)
    {
        r.push_back((n % 26) + 'A');
        n /= 26;
        len--;
    }
    reverse(ALL(r));
    return r;
}

int from_str(string s)
{
    int r = 0;
    int clen = 1, p26 = 26;
    while (clen < s.length())
    {
        r += p26;
        p26 *= 26;
        clen++;
    }
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        c = 26 * c + s[i] - 'A';
    }
    return c + r + 1;
}


int main()
{
#ifdef _DEBUG
    freopen("1064", "r", stdin);
//  freopen("1064o", "w", stdout);
#endif
    REP(ri())
    {
        rs(s);
        int rn, cn;
        if (sscanf(s, "R%dC%d", &rn, &cn) == 2)
        {
            cout<<to_str(cn)<<rn<<endl;
        }
        else
        {
            char *p = s;
            while (!isdigit(*p)) p++;
            char c = *p; *p = 0;
            int rn = from_str(s);
            *p = c;
            cout<<"R"<<p<<"C"<<rn<<endl;
        }
    }
    return 0;
}
