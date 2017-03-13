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
map<string, int> R;


int main()
{
    //freopen("test.txt", "r", stdin);


    int Test,N, kase=0, Num, part;

    string name;
    double amount;
    bool flag=false;
    while(cin>>N)
    {
        R.clear();
        Set.clear();
        if(flag) cout<<endl;
        flag=true;
        for(int i=0;i<N;i++)
        {
            cin>>name;
            Set.push_back(name);
            R[name]=0;
        }
        for(int i=0;i<N;i++)
        {
            cin>>name>>amount>>Num;

            if(Num!=0)
                part=(int) amount/Num;
            R[name] = R[name]-part*Num;

            for(int j=0;j<Num;j++)
            {
                cin>>name;

                R[name] = R[name] + part;
            }


        }
        for(int i=0;i<Set.size();i++)
            cout<<Set[i]<<" "<<R[Set[i]]<<endl;



    }

    return 0;
}

