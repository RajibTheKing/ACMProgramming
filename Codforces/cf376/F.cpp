#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<string>
#include<algorithm>
#include<regex>

#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int arr[200005];
int cnt[200005];
int chk[200005];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(cnt, 0, sizeof(cnt));

        for(int i=0;i<n;i++)
        {
            scanf("%d", &arr[i]);
            cnt[arr[i]]++;
        }
        sort(arr, arr+n);

        for(int i=1;i<=200000;i++)
        {
            cnt[i] = cnt[i-1]+cnt[i];
        }

        for(int i=0;i<100;i++)
        {
            cout<<cnt[i]<<" ";
        }
        cout<<endl;


        int mx = 0;

        for(int i=0;i<n;i++)
        {
            int now = arr[i], prev,start=arr[i];
            int sum=0;
            cout<<"Entering for: "<<now<<endl;
            while(true)
            {
                prev=now;
                now=now*start;
                if(now>200000) break;

                int diff = chk[now-1]-chk[prev-1];

                sum+=(diff*prev);


                cout<<"Now sum = "<<sum<<", now = "<<now<<", prev = "<<prev<<", diff = "<<diff<<endl;


            }
            mx = max(mx, sum);
        }

        cout<<mx<<endl;
    }

}
