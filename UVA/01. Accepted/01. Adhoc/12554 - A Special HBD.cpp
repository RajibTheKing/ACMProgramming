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

int main()
{
    string hbd[16];
    hbd[0]="Happy";
    hbd[1]="birthday";
    hbd[2]="to";
    hbd[3]="you";
    hbd[4]="Happy";
    hbd[5]="birthday";
    hbd[6]="to";
    hbd[7]="you";
    hbd[8]="Happy";
    hbd[9]="birthday";
    hbd[10]="to";
    hbd[11]="Rujia";
    hbd[12]="Happy";
    hbd[13]="birthday";
    hbd[14]="to";
    hbd[15]="you";

    int n;
    string name[2000];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>name[i];
        int kount=0;
        for(int i=0, j=0;i<16;i++, j++)
        {
            cout<<name[j]<<": "<<hbd[i]<<endl;
            kount++;
            if(i==15&&kount>=n) break;

            if(i==15)
                i=-1;
            if(j==n-1)
                j=-1;

        }
    }


    return 0;
}
