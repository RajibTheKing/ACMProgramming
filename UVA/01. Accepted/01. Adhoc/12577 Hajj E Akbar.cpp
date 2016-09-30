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
   string str;
   int kase=0;
   while(cin>>str)
   {
       if(str[0]=='*')
            break;

        if(str=="Hajj")
            printf("Case %d: Hajj-e-Akbar\n", ++kase);
        else
            printf("Case %d: Hajj-e-Asghar\n", ++kase);
   }

    return 0;
}

