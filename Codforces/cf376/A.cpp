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
    string s;
    while(cin>>s)
    {

        int pos = 0;
        int sum = 0;

        for(int i=0;i<s.size();i++)
        {
            int target = s[i]-'a';
            if(pos==target)
            {
                continue;
            }
            int knt1 = 0;
            for(int j=pos+1;;j++)
            {
                knt1++;
                if(j==26) j=0;
                //cout<<"FirstLoop: target = "<<target<<", knt1 = "<<knt1<<", j = "<<j<<endl;
                if(j==target) break;
            }
            int knt2=0;
            for(int j=pos-1;;j--)
            {
                knt2++;
                if(j==-1)
                    j=25;
                //cout<<"SecondLoop: target = "<<target<<", knt2 = "<<knt2<<", j = "<<j<<endl;
                if(j==target) break;
            }
            //cout<<"Knt1 = "<<knt1<<", knt2 = "<<knt2<<endl;

            sum+=min(knt1,knt2);
            pos=target;

        }
        cout<<sum<<endl;
    }

    return 0;
}
