#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;
#define INF 999999
#define pi 3.1415926535897932384626433832795


map<int , int> R;
vector<int> Set;
vector<int> Num;

int main()
{
    char s[10000];
    int t, n;
    char c;
    scanf("%d", &t);
    scanf("%c", &c);
    while(t--)
    {
        Num.clear();
        R.clear();

        gets(s);
        istringstream temp(s);
        stringstream ss;
        while(temp)
        {
            string a;
            temp>>a;
            ss.clear();
            ss<<a;
            ss>>n;
            //cout<<"Here: "<<n<<endl;
            Num.push_back(n);
        }
        int Max = 0;
        int x;

        for(int i=0;i<Num.size()-1;i++)
        {
            for(int j=0;j<Num.size()-1;j++)
            {
                if(i==j) continue;
                x=__gcd(Num[i], Num[j]);
                if(x>Max)
                    Max=x;

            }

            //cout<<Num[i]<<endl;
        }
        printf("%d\n", Max);

    }

    return 0;
}

