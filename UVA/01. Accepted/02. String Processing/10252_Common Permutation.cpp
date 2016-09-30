#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;




int main()
{
    char a[1005], b[1005];
    char c;
    int p[26], q[26], ans[26];
    while(gets(a))
    {
        gets(b);

        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));
        memset(ans, 0, sizeof(ans));

        for(int i=0;i<strlen(a);i++)
            p[a[i]-'a']++;
        for(int j=0;j<strlen(b);j++)
            q[b[j]-'a']++;

        for(int i=0;i<26;i++)
            ans[i]=min(p[i], q[i]);

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<ans[i];j++)
            {
                printf("%c", i+'a');
            }
        }
        cout<<endl;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

    }

    return 0;
}

