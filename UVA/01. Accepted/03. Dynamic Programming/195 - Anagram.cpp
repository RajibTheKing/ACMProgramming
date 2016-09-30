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



vector<string> Set;
bool comp(const char &p, const char &q)
{
    int temp = tolower(p) - tolower(q);
    if(temp)
        return temp<0;
    else
        return p<q;

}

int main()
{
    //freopen("test.txt", "r", stdin);
    char s[100];
    int test;
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        gets(s);
        sort(&s[0], &s[strlen(s)], comp);
        Set.clear();
        Set.push_back(s);

        while(next_permutation(s, s+strlen(s), comp))
        {
            Set.push_back(s);
        }

        for(int i=0;i<Set.size();i++)
            cout<<Set[i]<<endl;

    }

    return 0;
}


