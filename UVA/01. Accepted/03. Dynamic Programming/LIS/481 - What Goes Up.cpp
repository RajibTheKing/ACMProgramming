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

#define INF 1<<30
#define SZ 100000

int Sequence[SZ], L[SZ], I[SZ];
vector<int> R;
int LisNlogK(int n)
{
    int i;
    I[0]=-INF;
    for(i=1;i<=n;i++)
        I[i]=INF;
    int LisLength = 0;
    for(i=0;i<n;i++)
    {
        int low, high, mid;
        low=0;
        high=LisLength;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I[mid]<Sequence[i])
                low=mid+1;
            else
                high=mid-1;
        }
        I[low]=Sequence[i];
        L[i]=low;
        if(LisLength<low)
            LisLength=low;
    }


    int last_taken=INF;
    R.push_back(n);
    for(i=LisLength;i>0;i--)
    {
        for(int j=R[LisLength-i]-1;j>=0;j--)
        {

            if(L[j]==i&&Sequence[j]<last_taken)
            {
                //cout<<j<<endl;
                R.push_back(j);
                last_taken=Sequence[j];
                break;
            }
        }
    }

    return LisLength;

}
int main()
{
    //freopen("input.txt", "r", stdin);
    int k=0;
    int temp;
    while(scanf("%d", &temp)==1)
    {
        Sequence[k++]=temp;
    }
    int ans = LisNlogK(k);
    cout<<ans<<endl;
    cout<<"-"<<endl;
    for(int i=ans;i>=1;i--)
    {
        cout<<Sequence[R[i]]<<endl;
    }

    return 0;
}

