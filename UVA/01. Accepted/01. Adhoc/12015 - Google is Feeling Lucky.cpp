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



int main()
{
    int T;
    cin>>T;
    vector<string> a;
    vector<int> val;
    string s;
    int temp, M, kase=0;

    while(T--)
    {
        a.clear();
        val.clear();
        M = -99999999;
        for(int i=0;i<10;i++)
        {
            cin>>s>>temp;
            a.push_back(s);
            val.push_back(temp);
            if(M<temp)
                M=temp;

        }

        cout<<"Case #"<<++kase<<":"<<endl;
        for(int i=0;i<10;i++)
            if(val[i]==M)
                cout<<a[i]<<endl;



    }



    return 0;
}

