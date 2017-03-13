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
typedef long long LL;
bool flag[500055];

int main()
{
    int k, l, m, n, d;
    cin>>k>>l>>m>>n>>d;
    int kount = 0;
    memset(flag, 0, sizeof(flag));
    if(k==1||l==1||m==1||n==1)
    {
        kount=d;
        goto end;
    }


    for(int i=k;i<=d;i+=k)
        flag[i]=true;
    for(int i=l;i<=d;i+=l)
        flag[i]=true;
    for(int i=m;i<=d;i+=m)
        flag[i]=true;
    for(int i=n;i<=d;i+=n)
        flag[i]=true;

    for(int i=1;i<=d;i++)
        if(flag[i]==true)
            kount++;
    end:
    cout<<kount<<endl;
}



