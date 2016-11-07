#include<bits/stdc++.h>
using namespace std;
#define SZ 100002
int l[SZ];
int r[SZ];

int main()
{
    int n;

    while(cin>>n)
    {
        int sum1 = 0, sum2 = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d", &l[i], &r[i]);
            sum1+=l[i];
            sum2+=r[i];
        }

        int mx = abs(sum1-sum2);
        int col = 0;

        for(int i=1;i<=n;i++)
        {
            int temp1 = sum1 - l[i] + r[i];
            int temp2 = sum2 - r[i] + l[i];
            int now = abs(temp1-temp2);

            if(mx<now)
            {
                col = i;
                mx = now;
            }
        }

        cout<<col<<endl;

    }

    return 0;
}

