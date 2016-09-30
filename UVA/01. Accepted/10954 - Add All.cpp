#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

struct compare
{
    bool operator()(const int &a, const int &b)
    {
        return a>b;
    }
};
int main()
{
    priority_queue<int, vector<int>, compare> pq;
    int n, t, p, q, ans;
    while(cin>>n)
    {
        if(n==0) break;

        for(int i=0;i<n;i++)
        {

            scanf("%d", &t);
            pq.push(t);
        }

        ans=0;
        while(!pq.empty())
        {
            p=pq.top();
            pq.pop();
            q=pq.top();
            pq.pop();
            //cout<<p<<" "<<q<<endl;
            t=p+q;

            pq.push(t);
            ans+=t;
            if(pq.size()==1) break;
        }

        cout<<ans<<endl;
        pq.pop();
    }

    return 0;
}
