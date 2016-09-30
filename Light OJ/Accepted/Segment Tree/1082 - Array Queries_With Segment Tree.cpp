#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;

int a[100009];
int tree[400100];

int Min(int p, int q)
{
    if(p<q) return p;
    else return q;
}

int initialize(int node, int left, int right)
{
    if(left==right)
    {
        tree[node]=a[left];
        return tree[node];
    }
    int mid = (left+right)/2;
    int p=initialize(node*2, left, mid);
    int q=initialize(node*2+1, mid+1, right);

    tree[node]=Min(p, q);
    return tree[node];
}
int query(int node, int left, int right, int i, int j)
{
    if(right<i||left>j) return INF;
    if(left>=i&&right<=j) return tree[node];
    int mid=(left+right)/2;
    int p=query(node*2, left, mid, i, j);
    int q=query(node*2+1, mid+1, right, i, j);
    return Min(p, q);
}
int main()
{
    //freopen("input.txt","r", stdin);
    int test, N, Q, kase=0, minimum;
    scanf("%d", &test);
    while(test--)
    {
        memset(a, 0, sizeof(a));
        scanf("%d %d", &N, &Q);
        for(int i=1;i<=N;i++)
            scanf("%d", &a[i]);
        minimum = initialize(1, 1, N);
        //cout<<minimum<<endl;
        int i, j;
        printf("Case %d:\n", ++kase);
        for(int m=1;m<=Q;m++)
        {
            scanf("%d %d", &i, &j);
            printf("%d\n", query(1, 1, N, i, j));

        }



    }

    return 0;
}
