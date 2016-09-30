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

bool comp(string p, string q)
{
    return p<q;
}
int main()
{
    char s[100];
    int test;
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        gets(s);
        sort(s, s+strlen(s));
        Set.clear();
        Set.push_back(s);
        while(next_permutation(s, s+strlen(s)))
        {
            Set.push_back(s);
        }
        sort(&Set[0], &Set[Set.size()], comp);
        for(int i=0;i<Set.size();i++)
            cout<<Set[i]<<endl;
        cout<<endl;
    }

    return 0;
}


