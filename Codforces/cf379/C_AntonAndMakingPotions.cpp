#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define SZ 200005
LL n,m,k, x, s;
LL a[SZ],b[SZ],c[SZ],d[SZ];

int main()
{
    while(scanf("%I64d %I64d %I64d", &n, &m, &k)==3)
    {
        scanf("%I64d %I64d", &x, &s);
        for(int i=0;i<m;i++) scanf("%I64d", &a[i]);
        for(int i=0;i<m;i++) scanf("%I64d", &b[i]);
        for(int i=0;i<k;i++) scanf("%I64d", &c[i]);
        for(int i=0;i<k;i++) scanf("%I64d", &d[i]);

        LL ans = 4000000000000000002;
        LL newAns, finished;
        int left,right,mid;

        for(int i=0;i<m;i++)
        {
            LL newTime = a[i];
            LL leftManaPoint = s - b[i];
            left = 0, right = k-1, mid;
            if(leftManaPoint<0)
            {
                newAns = n*x;
            }
            else if(leftManaPoint >= d[0])
            {
                while(left<=right)
                {
                    mid = (left+right)/2;
                    if(d[mid]<=leftManaPoint)
                    {
                        finished = c[mid];
                        left = mid+1;
                    }
                    else
                        right = mid-1;
                }

                newAns = (n-finished)*newTime;

                //cout<<"newAns2: "<<newAns<<", finished: "<<finished<<", point: "<<leftManaPoint<<endl;


            }
            else
            {
                newAns = n*newTime;
            }

            if(newAns<ans)
                ans = newAns;

        }

        if(s >= d[0])
        {
            left = 0;
            right=k-1;
            while(left<=right)
            {
                mid = (left+right)/2;
                if(d[mid]<=s)
                {
                    finished = c[mid];
                    left = mid+1;
                }
                else
                    right = mid-1;
            }

            newAns = (n-finished)*x;

            //cout<<"newAns2: "<<newAns<<", finished: "<<finished<<", point: "<<leftManaPoint<<endl;


        }

        if(newAns<ans)
            ans = newAns;


        cout<<ans<<endl;

    }
    return 0;
}
