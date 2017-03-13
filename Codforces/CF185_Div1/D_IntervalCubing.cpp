#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MX 100005
#define MOD 95542721
LL a[MX];
LL tree[MX*4];

LL getValue(LL v)
{
    LL ans = v;
    for(int i=0;i<2;i++)
    {
        ans%=MOD;
        ans*=v;
    }
    return ans%MOD;

}
LL Initialize(int node, int left, int right)
{
    if(left==right)
    {
        tree[node] = a[left] % MOD;
        return tree[node];
    }

    int mid = (left+right)/2;
    LL p = Initialize(node*2, left, mid);
    LL q = Initialize(node*2+1, mid+1, right);

    tree[node] = (p % MOD + q % MOD) % MOD;

    return tree[node];
}

LL query(int node, int left, int right, int i, int j)
{
    if(right<i || left>j) return 0;
    if(left>=i && right<=j) return tree[node];

    int mid = (left+right)/2;
    LL p = query(node*2, left, mid, i, j);
    LL q = query(node*2+1, mid+1, right, i, j);
    return (p % MOD + q % MOD) % MOD;
}

void update(int node, int left, int right, int i, int newValue)
{
    if(i>right || i<left) return;

    if(left>=i && right<=i)
    {
        tree[node] = ((tree[node]-newValue)%MOD + getValue(newValue))% MOD;
        return;
    }

    int mid = (left+right)/2;
    update(node*2, left, mid, i, newValue);
    update(node*2+1, mid+1, right, i, newValue);
    tree[node] = (tree[node*2] + tree[node*2+1]) % MOD;
}



int main()
{
    int n,m, type, bg ,  en;
    while(scanf("%d", &n)==1)
    {
        memset(a, 0, sizeof(a));
        memset(tree,0,sizeof(tree));

        for(int i=1;i<=n;i++)
        {
            scanf("%I64d", &a[i]);
        }
        LL sum = Initialize(1,1,n);
        //cout<<"Sum: "<<sum<<endl;
        scanf("%d", &m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %d", &type, &bg, &en);
            if(type==1)
            {
                LL ans = query(1,1,n,bg,en);
                printf("%I64d\n", ans);
            }
            else
            {
                for(int i=bg;i<=en;i++)
                {
                    update(1,1,n,i,a[i]);
                    a[i]= getValue(a[i]);
                }
                //LL checkAns = query(1,1,n,1,n);
                //cout<<"Checking: "<<checkAns<<endl;
            }
        }

    }
    return 0;
}


