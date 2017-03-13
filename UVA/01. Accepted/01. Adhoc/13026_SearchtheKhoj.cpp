#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, kase=0;
    cin>>T;
    int n;
    string str[1001];
    string s;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>str[i];
        }
        cin>>s;
        printf("Case %d:\n", ++kase);
        for(int i=0;i<n;i++)
        {
            int knt = 0;
            if(str[i].size()!=s.size()) continue;
            for(int j=0;j<str[i].size();j++)
            {
                if(str[i][j]!=s[j])
                    knt++;
            }
            if(knt<=1)
            {
                cout<<str[i]<<endl;
            }
        }

    }
}
