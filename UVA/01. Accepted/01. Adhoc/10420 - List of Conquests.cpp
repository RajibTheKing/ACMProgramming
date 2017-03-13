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


map<string, int> Freq;
map<string, bool> color;
vector<string> Set;

bool comp(string p, string q)
{
    return p<q;
}
int main()
{
    string a, b;

    int Test, kase=0;
    scanf("%d", &Test);
    getchar();
    color.clear();
    Freq.clear();

    while(Test--)
    {
        cin>>a;
        getline(cin, b);
        Freq[a]++;

        if(color[a]==false)
        {
            color[a]=true;
            Set.push_back(a);

        }

        sort(&Set[0], &Set[Set.size()], comp);




    }

    for(int i=0;i<Set.size();i++)
        cout<<Set[i]<<" "<<Freq[Set[i]]<<endl;


    return 0;
}

