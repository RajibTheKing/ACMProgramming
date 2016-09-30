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
#define inf 1000000


int main()
{
    int n, x, y, z, max, min;
    string s1, s2, name;
    int a[10];

    while(cin>>n)
    {
        min=inf;
        max=0;
        s1="";
        s2="";
        if(n==-1) break;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>z;
            cin>>name;
            a[i]=x*y*z;
            if(a[i]<min)
            {
                min = a[i];
                s1=name;

            }
            if(a[i]>max)
            {
                max=a[i];
                s2=name;
            }

        }
        cout<<s2<<" took clay from "<<s1<<"."<<endl;
    }


    return 0;
}



