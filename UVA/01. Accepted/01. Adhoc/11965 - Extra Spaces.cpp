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
    int T, kase=0, n;
    cin>>T;
    string str;
    vector<string> S;
    while(T--)
    {
        if(kase) cout<<endl;
        cin>>n;
        getchar();
        S.clear();
        for(int i=0;i<n;i++)
        {
            getline(cin, str);
            S.push_back(str);
        }
        cout<<"Case "<<++kase<<":"<<endl;
        bool flag;
        for(int i=0;i<n;i++)
        {
            flag=true;
            for(int j=0;j<S[i].size();j++)
            {
                if(flag==true && S[i][j]==' ')
                {
                    cout<<S[i][j];
                    flag=false;
                }
                else if(S[i][j]!=' ')
                {
                    flag=true;
                    cout<<S[i][j];
                }
                else continue;



            }
            cout<<endl;
        }


    }



    return 0;
}

