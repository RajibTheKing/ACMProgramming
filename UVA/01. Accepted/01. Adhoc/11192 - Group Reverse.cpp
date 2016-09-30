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
    int n;
    string a;
    while(cin>>n)
    {
        if(n==0) break;
        cin>>a;
        n = a.length()/n;
        for(int i=0;i<a.length();i+=n)
        {
            for(int j=i+n-1;j>=i;j--)
                cout<<a[j];
        }
        cout<<endl;
    }


    return 0;
}

