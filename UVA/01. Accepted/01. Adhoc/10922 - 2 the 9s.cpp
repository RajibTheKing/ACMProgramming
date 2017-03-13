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


int addDigit(int n)
{
    int sum=0;
    while(n)
    {
        sum+= (n%10);
        n/=10;
    }
    return sum;
}
int main()
{
    string a;
    while(cin>>a)
    {
        if(a=="0") break;
        int sum=0, kount=1;
        for(int i=0;i<a.length();i++) sum+= (a[i]-'0');
        if(sum%9)
        {
            cout<<a<<" is not a multiple of 9."<<endl;
            continue;
        }
        while(true)
        {
            if(sum==9) break;
            sum = addDigit(sum);
            kount++;
        }
        cout<<a<<" is a multiple of 9 and has 9-degree "<<kount<<"."<<endl;



    }


    return 0;
}

