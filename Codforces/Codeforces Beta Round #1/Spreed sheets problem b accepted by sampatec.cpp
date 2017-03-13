#define ONLINE_JUDGE
//#define GenerateTest

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <list>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>

//#include "BigInteger\cbignum.h"
using namespace std;
#pragma comment(linker, "/STACK:264777216")

typedef long long LL;
typedef long long cBigNumber;
typedef unsigned int uint;
typedef unsigned long long ULL;
bool is(string st)
{
        istringstream in(st);
        if(st[0] == 'R')
        {
                for(int i = 1;i < st.size();++i)
                {
                        if(st[i] == 'C' && i > 1)
                        {
                                if(i >= st.size() - 1)
                                        return false;
                                for(++i;i < st.size();++i)
                                        if(!(st[i] >= '0' && st[i] <= '9'))
                                                return false;
                                return true;
                        }
                        if(!(st[i] >= '0' && st[i] <= '9'))
                                return false;
                }
        }
        return false;
}
int pow1(int a,int b)
{
        int r = 1;
        for(int i = 0;i < b;++i)
                r *= a;
        return r;
}
void Solve()
{
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i = 0;i < n;++i)
        {
                cin >> v[i];
                if(is(v[i]))
                {
                        LL a = 0, b = 0;
                        for(int j = 1;j < v[i].size();++j)
                        {
                                if(v[i][j] == 'C')
                                {
                                        for(++j;j < v[i].size();++j)
                                                b = b * 10 + v[i][j] - '0';
                                        break;
                                }
                                else
                                        a = a * 10 + v[i][j] - '0';
                        }
                        string B;
                        int res = 0;
                        for(int len = 1;;++len)
                        {
                                res += pow1(26,len);
                                if(res > b)
                                {
                                        res -= pow1(26,len);
                                        for(int i = 0;i < len;++i)
                                        {
                                                B += 'A';
                                                bool ise = false;
                                                for(int j = 'A';j <= 'Z';++j)
                                                {
                                                        B[i] = j;
                                                        res += pow1(26,len - i - 1);
                                                        if(res > b)
                                                                break;
                                                        if(res == b)
                                                        {
                                                                ise = true;
                                                                for(++i;i < len;++i)
                                                                        B += 'Z';
                                                                break;
                                                        }
                                                }
                                                if(ise)
                                                        break;
                                                res -= pow1(26,len - i - 1);
                                        }
                                        break;
                                }
                                else
                                        if(res == b)
                                        {
                                                for(int i = 0;i < len;++i)
                                                        B += 'Z';
                                                break;
                                        }

                        }

                        cout << B << a << endl;
                }
                else
                {
                        string r1, r2;
                        for(int j = 0;j < v[i].size();++j)
                        {
                                if(v[i][j] >= '0' && v[i][j] <= '9')
                                        r1 += v[i][j];
                                else r2 += v[i][j];
                        }
                        int b = 0;
                        for(int i = 0;i < r2.size() - 1;++i)
                        {
                                b += pow1(26,i + 1);
                        }
                        for(int i = 0;i < r2.size();++i)
                                //for(int j = 0; j < r2[j];++j)
                                        b += pow1(26,r2.size() - i  - 1) * (r2[i] - 'A');
                        ++b;
                        cout << "R" << r1 << "C" << b << endl;
                }
        }

}

#ifndef ONLINE_JUDGE
#include <ctime>
#endif
int main()
{

#ifdef ONLINE_JUDGE
        //freopen("getduck.in", "r+", stdin);
        //freopen("getduck.out", "w+", stdout);

#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);

#ifdef GenerateTest

        freopen("output.txt", "wt", stdout);


#endif

        clock_t start = clock();
#endif

        Solve();

#ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout <<"\n\nTime: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
#endif
        return 0;
}
