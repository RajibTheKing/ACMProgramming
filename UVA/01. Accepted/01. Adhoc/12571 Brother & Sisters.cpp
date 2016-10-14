#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T, N, Q;
    cin>>T;
    int arr[100005];
    int ans[235];

    int temp, chk;

    while(T--)
    {
        cin>>N>>Q;
        for(int i=0;i<N;i++)
        {
            scanf("%d", &arr[i]);
        }
        for(int i=0;i<=230;i++)
        {
            int mx = 0;
            for(int j=0;j<N;j++)
            {
                chk = i&arr[j];
                if(chk>mx)
                {
                    mx=chk;
                }

            }
            ans[i] = mx;
        }

        for(int i=0;i<Q;i++)
        {
            scanf("%d", &temp);
            printf("%d\n", ans[temp]);
        }
    }
    return 0;
}
