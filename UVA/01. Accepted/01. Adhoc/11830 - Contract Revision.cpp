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
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)


char input[100000], str[100000];
void PrintAnswer(char c, char *s)
{
    int len=strlen(s);
    bool flag;


    for (int i=0 ; i<len ; i++)
    {
        if (s[i]==c)
            s[i]='#';
    }

    flag=false;
    for (int i=0 ; i<len ; i++)
    {
        if (s[i]!='0' && s[i]!='#')
            flag=true;
        if (flag && s[i]!='#')
            printf("%c", s[i]);
    }

    if (flag==false)
        printf("0");

    printf("\n");

}

int main()
{
    //freopen("input.txt", "r", stdin);
    char c;
    while (gets(input))
    {
        if (!strcmp("0 0",input))
            break;
        sscanf(input,"%c %s",&c,str);

        PrintAnswer(c, str);
    }
    return 0;
}
