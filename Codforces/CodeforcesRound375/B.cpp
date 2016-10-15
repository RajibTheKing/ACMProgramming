#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>

#include<string.h>
#include<stdio.h>

using namespace std;
int maxNum(int a, int b)
{
    if(a>b) return a;

    return b;
}
int main()
{
    //freopen("/rajib/MyFiles/ProblemSolving/ACMProgramming/Codforces/CodeforcesRound375/input.txt", "r", stdin);

    string ss;
    int n;
    while(cin>>n)
    {
        cin>>ss;

        string s1 = "";
        string s2 = "";

        for(int i=0;i<ss.size();i++)
        {
            if(ss[i]=='(')
            {
                s1+=" ";
                int j=i+1;
                for(j;ss[j]!=')';j++)
                {
                    if(ss[j]=='_')
                        s2+=" ";
                    else
                        s2+=ss[j];
                }
                s2+=" ";
                i=j;
            }
            else
            {
                if(ss[i]=='_')
                    s1+=" ";
                else
                    s1+=ss[i];

            }

        }

        //cout<<s1<<endl;
        //cout<<s2<<endl;

        stringstream ss;
        ss.clear();
        ss<<s1;
        int mx = 0;
        while(ss>>s1)
        {
            mx = maxNum(mx, s1.size());
        }
        int knt = 0;
        ss.clear();
        ss<<s2;
        while(ss>>s2)
        {
            knt++;
        }

        cout<<mx<<" "<<knt<<endl;

    }

    return 0;

}
