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
#define mod 1000000007


int main()
{
    int t, n, kount, p;
    cin>>t;
    int a[55];
    map<int, bool> R;
    R.clear();
    long long ans;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);

        ans=1;
        for(int i=0;i<n;i++)
        {
            kount=0;
            for(int j=a[i];j>=1;j--)
            {

                if(R[j]==false)
                {
                    p=j;
                    kount++;
                }

            }

            R[p]=true;
            ans=ans * kount;

            ans=ans % mod;

            //cout<<"koutn: "<<kount<<endl;
        }

        ans = ans % mod;

        cout<<ans<<endl;

        R.clear();



    }


    return 0;
}


