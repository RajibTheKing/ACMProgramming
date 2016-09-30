#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    int arr[127];
    bool flag[100000];
    memset(arr, 0, sizeof(arr));
    memset(flag, 0, sizeof(arr));
    for(int i=0;i<s.size();i++)
    {
        arr[s[i]]++;
    }

    int num = 0;
    for(int i=0;i<127;i++)
    {
        if(arr[i]!=0)
        {
            num++;
            if(flag[arr[i]] == true)
            {
                return false;
            }
            flag[arr[i]]=true;

        }
    }

    if(num<=1) return false;

    return true;


}
int main()
{
    string str;

    int t;
    int kase = 0;

    while(cin>>t)
    {
        int knt = 0;
        for(int i=0;i<t;i++)
        {
            cin>>str;
            if(isValid(str))
                knt++;


        }
        printf("Case %d: %d\n", ++kase, knt);
    }
    return 0;
}
