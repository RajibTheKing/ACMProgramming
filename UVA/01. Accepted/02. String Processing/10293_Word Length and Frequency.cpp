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



map<int, int> M;
int MM;
void showOutput(void)
{
    for(int i=0;i<=MM;i++)
    {
        if(M[i]!=0)
        {
            printf("%d %d\n", i, M[i]);
        }
    }
    cout<<endl;
    return;
}
int main()
{

    M.clear();
    char a[100];
    char apostrophes=39;
    int i, j, temp, l=0;
    bool flag=false;
    while(gets(a))
    {

        if(a[0]=='#')
        {
            showOutput();
            flag=false;
            l=0;
            MM=0;
            M.clear();
            continue;

        }

        for(i=0;i<strlen(a);i++)
        {
            if(isalpha(a[i])&&flag==false)
            {
                l=1;
                flag=true;
                continue;
            }
            if(isalpha(a[i])&&flag==true)
            {
                l++;
                continue;
            }
            if(a[i]=='-'||a[i]==apostrophes)
                continue;

            if(!isalpha(a[i])&&flag==true)
            {
                if(l>MM)
                    MM=l;
                M[l]++;
                flag=false;
                continue;
            }


        }
        if(isalpha(a[strlen(a)-1]))
        {
            if(l>MM)
                MM=l;
            M[l]++;
                flag=false;

        }
        memset(a, 0, sizeof(a));

    }

    return 0;
}

