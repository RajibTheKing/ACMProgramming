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




vector<string> SplitString(string s, char delimiter)
{
    vector<string> result;
    string token;
    stringstream ss(s);
    while(getline(ss,token,delimiter))
    {
        result.push_back(token);
    }
    return result;
}

int main()
{

    int T;
    cin>>T;
    getchar();
    string str;
    vector<string> S;
    while(T--)
    {
        getline(cin, str);
        S = SplitString(str, ' ');
        int male = 0, female = 0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i][0]=='M') male++;
            if(S[i][1]=='F') female++;
        }
        if(S.size()==1)
            printf("NO LOOP\n");
        else if(male==female)
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }

    return 0;
}

