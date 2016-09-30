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
    int T, kase=0, n, NumberOfTree;
    char str[40];

    map<string, int> M;
    scanf("%d\n\n", &T);
    while(T--)
    {
        if(kase++) printf("\n");
        M.clear();
        NumberOfTree=0;
        while(gets(str))
        {
            if(strlen(str)==0) break;
            //cout<<"Here: "<<str<<endl;
            if(M.count(string(str))==0)
                M[string(str)]=1;
            else
                M[string(str)] = M[string(str)]+1;
            NumberOfTree++;


        }
        int L = M.size();
        for (map<string,int>::iterator it = M.begin(); it!=M.end(); it++)
        {
            //cout << it->first << " => " << it->second << '\n';
            string nm= it->first;
            //cout<<it->second<<endl;
            double ans = (double) it->second * 100/ (NumberOfTree * 1.0);
            cout<<nm;
             printf(" %.4lf\n", ans);
        }




    }



    return 0;
}

