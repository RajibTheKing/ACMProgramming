#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<algorithm>


using namespace std;


int main()
{
    int t,n;
    long long ans;

    vector<long long> vp;
    vp.clear();
    for(int i=0;i<=44721;i++)
    {
        ans = i*(i+1)/2;
        vp.push_back(ans);

    }

    while(scanf("%d", &t)==1)
    {
        if(t==0) break;
        vector<long long>::iterator it;
        it = upper_bound(vp.begin(), vp.end(), t);

        int pos = it-vp.begin();


        //cout<<vp[pos]-t<<" "<<pos<<endl;

        printf("%lld %d\n", vp[pos]-t, pos);

    }
    return 0;
}
