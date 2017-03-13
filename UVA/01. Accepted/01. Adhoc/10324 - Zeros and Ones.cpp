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
    char s[1000005];
    int i, j, n, kase=0;

    while(gets(s))
    {
        if(strlen(s)==0) break;

        cin>>n;
        printf("Case %d:\n", ++kase);
        for(int q=0;q<n;q++)
        {
            scanf("%d %d", &i, &j);
            getchar();

            bool flag=true;
            char c=s[min(i, j)];
            for(int k=min(i, j)+1;k<=max(i, j);k++)
            {
                if(s[k]!=c)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }

    }

    return 0;
}

