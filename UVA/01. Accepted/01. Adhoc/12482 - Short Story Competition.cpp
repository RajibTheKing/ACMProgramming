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

int main(){
    int N,L,C;
    int len[1000];
    char s[71];

    while(scanf("%d %d %d",&N,&L,&C) == 3){
        for(int i = 0;i < N;++i){
            scanf("%s",s);
            len[i] = strlen(s);
        }

        int ans = 1;

        for(int i = 0,cont = 0;i < N;++i){
            if(cont + len[i] + 1 <= C + 1) cont += len[i] + 1;
            else{
                cont = len[i] + 1;
                ++ans;
            }
        }

        printf("%d\n",(ans + L - 1) / L);
    }

    return 0;
}
