#include<iostream>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
using namespace std;

map<int, string> mp;

void Generate()
{
    mp[0]="0";
    mp[1]="2(0)";
    mp[2]="2";
    mp[3]="2+2(0)";
    mp[4]="2(2)";
    mp[5]="2(2)+2(0)";
    mp[6]="2(2)+2";
    mp[7]="2(2)+2+2(0)";
    mp[8]="2(2+2(0))";
    mp[9]="2(2+2(0))+2(0)";
    mp[10]="2(2+2(0))+2";
    mp[11]="2(2+2(0))+2+2(0)";
    mp[12]="2(2+2(0))+2(2)";
    mp[13]="2(2+2(0))+2(2)+2(0)";
    mp[14]="2(2+2(0))+2(2)+2";

}
int main()
{
    //freopen("output.txt", "r+", stdout);
    mp.clear();
    Generate();
    int arr[]={137,1315,73,136,255,1384,16385};
    int n = 7;
    string ans = "", s;
    for(int i=0;i<n;i++)
    {
        bool isFirst = true;
        stringstream ss;
        ss.clear();
        ss<<arr[i];
        ss>>s;
        ans = s+"=";
        for(int j=14;j>=0;j--)
        {
            if((1<<j)&arr[i])
            {
                if(isFirst)
                {
                    if(j==1)
                        ans = ans+"2";
                    else
                        ans =ans+"2("+mp[j]+")";

                    isFirst=false;
                }
                else
                {
                    if(j==1)
                        ans=ans+"+2";
                    else
                        ans=ans+"+2("+mp[j]+")";
                }
            }

        }
        cout<<"printf(\""<<ans<<"\\n\");"<<endl;

    }

    return 0;
}
