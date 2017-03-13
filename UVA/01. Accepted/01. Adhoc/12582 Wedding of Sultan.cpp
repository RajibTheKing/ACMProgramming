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
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

string str;

int FindNextChar(char c, int indx)
{
    int L=str.size();
    for(int i=indx;i<L;i++)
        if(str[i]==c)
            return i;

}

int main()
{
    int T, kase=0, L, Start, Finish;
    cin>>T;

    int ans[200];
    while(cin>>str)
    {
        memset(ans, 0, sizeof(ans));
        L = str.size();
        for(int i=0;i<L-1;i++)
        {
            char c = str[i];
            if(ans[c]) continue;
            Start = i;
            Finish =FindNextChar(c, i+1);
            int sum=0;
            for(int j=Start+1;j<Finish;j++)
            {
                char ss = str[j];
                if(ss==c) break;
                sum++;
                j=FindNextChar(ss,j+1);

            }
            ans[c]=sum+1;

        }
        ans[str[0]]--;
        cout<<"Case "<<++kase<<endl;
        for(int i=0;i<200;i++)
            if(ans[i])
                printf("%c = %d\n", i, ans[i]);

    }

    return 0;
}

