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


char chk[]="MARGIT";
int chkVal[200];

void Initialize_Value()
{
    chkVal['M']=1;
    chkVal['A']=3;
    chkVal['R']=2;
    chkVal['G']=1;
    chkVal['I']=1;
    chkVal['T']=1;
}
int main()
{
    Initialize_Value();
    char s[700];
    int kount[200];
    int T, L;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        memset(kount, 0, sizeof(kount));
        L = strlen(s);

        for(int i=0;i<L;i++)
            kount[s[i]]++;

        int ans = 1<<20;
        for(int i=0;i<6;i++)
        {
            kount[chk[i]] /= chkVal[chk[i]];
            ans = min(ans, kount[chk[i]]);

        }
        printf("%d\n", ans);

    }


    return 0;
}

