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
    //freopen("input.txt", "r", stdin);
    long long n, k, sum;
    char c=' ';
    string a[100];
    long long b[100];
    while(cin>>n&&n!=0)
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            getline(cin, a[i]);
        }
        memset(b, 0, sizeof(b));
        for(int i=0;i<n;i++)
        {
            k=0;
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]==c)
                        k++;
            }
            b[i]=k;
        }
        sort(b, b+n);
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=b[i]-b[0];
            //cout<<b[i]<<" ";
        }

        cout<<sum<<endl;
    }

    return 0;
}
