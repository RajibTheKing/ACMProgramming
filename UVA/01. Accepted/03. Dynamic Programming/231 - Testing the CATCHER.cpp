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


vector <int> a;
int compute()
{
    int temp = a.size(), M=0;
    vector<int> b;
    for(int i=0;i<temp;i++)
        b.push_back(1);
    for(int i=0;i<temp;i++)
    {
        for(int j=i-1;j>=0;j--)
            if(a[j]>=a[i])
            {
                b[i]=max(b[i], b[j]+1);
                if(M<b[i]) M=b[i];
            }
    }
    return M;

}

int main()
{


    int t, ans, kase=0;
    while(1)
    {
        cin>>t;
        if(t==-1&&a.size()==0)
            break;
        //cout<<a.size()<<" here is the size"<<endl;
        if(t==-1)
        {
            ans = compute();
            if(kase>0) printf("\n");
            printf("Test #%d:\n", ++kase);
            printf("  maximum possible interceptions: %d\n", ans);
            a.clear();
            continue;

        }
        a.push_back(t);


    }


    return 0;
}
