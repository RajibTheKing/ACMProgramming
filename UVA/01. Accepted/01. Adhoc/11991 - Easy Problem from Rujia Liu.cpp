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
vector<int> a;
vector<int> store[100005];
map<int, int> M;


void findAns()
{
    int index;
    int L = a.size();
    for(int i=0;i<L;i++)
    {
        index = M[a[i]];
        store[index].push_back(i);
    }

}

int main()
{
    int n, m, temp, p, q;


    while(scanf("%d %d", &n, &m)==2)
    {
        M.clear();
        a.clear();
        for(int i=0;i<100005;i++)
            store[i].clear();

        for(int i=0;i<n;i++)
        {
            scanf("%d", &temp);
            a.push_back(temp);

            if(M[temp]==0)
            {
                M[temp]=i;
            }


        }
        findAns();

        for(int i=0;i<m;i++)
        {
            scanf("%d %d", &p, &q);
            if(p<=store[M[q]].size())
                cout<<store[M[q]][p-1]+1<<endl;
            else
                cout<<"0"<<endl;
        }

    }


    return 0;
}

