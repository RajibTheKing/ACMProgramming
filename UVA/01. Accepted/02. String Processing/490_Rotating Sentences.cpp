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


int Max(int p, int q)
{
    if(p>q) return p;
    else return q;
}

int main()
{
    string a[1000];
    int row=0;
    //freopen("input.txt", "r", stdin);
    int maxlength=0;
    while(getline(cin, a[row]))
    {
        maxlength = Max(maxlength, a[row].length());
        row++;
    }
    for(int j=0;j<maxlength;j++)
    {
        for(int i=row-1;i>=0;i--)
        {
            if(j<a[i].length())
                cout<<a[i][j];
            else cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}

