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
    int Test, N, kount, P, t;
    int a[4000];
    cin>>Test;
    while(Test--)
    {
        cin>>N;
        memset(a, 0, sizeof(a));
        cin>>P;
        kount=0;
        for(int i=0;i<P;i++)
        {
            cin>>t;
            for(int j=t;j<=N;j+=t)
            {
                if(j%7==6||j%7==0)
                    continue;
                if(a[j]==0)
                {
                    kount++;
                    a[j]=1;
                }

            }

        }
        cout<<kount<<endl;
    }

    return 0;
}
