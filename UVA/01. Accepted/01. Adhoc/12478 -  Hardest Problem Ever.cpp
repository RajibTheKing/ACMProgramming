#include<stdio.h>
main(){printf("KABIR\n");}

/*
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

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)


string name[] = {"RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"};


bool compare_Name(string s1, string s2)
{
    sort(&s1[0], &s1[s1.size()]);
    sort(&s2[0], &s2[s2.size()]);
    if(s1==s2) return true;
    return false;

}

int main()
{

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> data;
    string str, s;
    while(cin>>str)
    {
        data.pb(str);
    }
    cout<<data.size();
    for(int i=0;i<8;i++)
    {
        int temp = name[i].size();
        cout<<"For: "<<name[i]<<endl;
        int kount=0;

        for(int j=0;j<data.size();j++)
        {

            for(int k=0; k<=(data[j].size()-temp+1); k++)
            {
                s = data[j].substr(k, temp);
                //cout<<"      k = "<<k<<" "<<s<<endl;
                if(compare_Name(s,name[i]))
                {
                    kount++;
                }
            }

        }
        cout<<"Counted: "<<kount<<endl;

    }

    printf("KABIR\n");

}
*/
