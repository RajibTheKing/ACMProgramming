
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<string>
#include<algorithm>
#include<regex>

#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
    //freopen("/Users/RajibTheKing/Desktop/OnTry/cf376/input.txt", "r+", stdin);
    int n;
    while(cin>>n)
    {
        long long sum = 0;
        int temp;
        bool flag = true;

        for(int i=0;i<n;i++)
        {
            scanf("%d", &temp);
            if(temp==0 && sum%2==1)
            {
                flag=false;
            }
            sum+=temp;

        }
        if(sum%2==1)
        {
            flag = false;
        }

        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
